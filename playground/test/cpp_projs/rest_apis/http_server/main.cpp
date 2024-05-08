#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <memory>
#include <string>

// Namespace aliases
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

// HTTP session class
class HttpSession : public std::enable_shared_from_this<HttpSession>
{
public:
    HttpSession(tcp::socket socket)
        : socket_(std::move(socket)) {}

    void start()
    {
        read_request(); // Start reading HTTP requests
    }

private:
    tcp::socket socket_;
    beast::flat_buffer buffer_;
    http::request<http::string_body> req_;
    http::response<http::string_body> res_;

    void read_request()
    {
        auto self = shared_from_this();
        http::async_read(
            socket_, buffer_, req_,
            [self](beast::error_code ec, std::size_t)
            {
                if (!ec)
                {
                    self->process_request();
                }
            });
    }

    void process_request()
    {
        std::cout << " process_request handled\n";
        res_.result(http::status::ok);
        res_.version(req_.version());
        res_.set(http::field::content_type, "text/plain");

        // Respond based on the HTTP method
        switch (req_.method())
        {
        case http::verb::get:
            res_.body() = "GET request received from rsadhu_http_server";
            break;

        case http::verb::post:
            res_.body() = "POST request from rsadhu_http_server  received with data: " + req_.body();
            break;

        default:
            res_.result(http::status::bad_request);
            res_.body() = "Unsupported HTTP method.";
        }

        res_.prepare_payload(); // Prepare the response
        write_response();       // Send the response
    }

    void write_response()
    {
        auto self = shared_from_this();
        http::async_write(
            socket_, res_,
            [self](beast::error_code ec, std::size_t)
            {
                self->socket_.shutdown(tcp::socket::shutdown_send, ec);
            });
    }
};

// HTTP server class
class HttpServer
{
public:
    HttpServer(net::io_context &ioc, tcp::endpoint endpoint)
        : acceptor_(ioc), socket_(ioc)
    {
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(net::socket_base::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();

        accept(); // Start accepting connections
    }

private:
    tcp::acceptor acceptor_;
    tcp::socket socket_;

    void accept()
    {
        acceptor_.async_accept(
            socket_,
            [this](beast::error_code ec)
            {
                if (!ec)
                {
                    std::make_shared<HttpSession>(std::move(socket_))->start(); // Start a new HTTP session
                }
                accept(); // Continue accepting connections
            });
    }
};

int main()
{
    net::io_context ioc;                     // ASIO I/O context
    tcp::endpoint endpoint(tcp::v4(), 8082); // Listen on port 8080

    HttpServer server(ioc, endpoint); // Start the HTTP server

    std::cout << "http_server listening at 8082\n";

    ioc.run(); // Run the I/O context

    return 0;
}
