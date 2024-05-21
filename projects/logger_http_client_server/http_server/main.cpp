#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <memory>

namespace beast = boost::beast;   // from <boost/beast.hpp>
namespace http = beast::http;     // from <boost/beast/http.hpp>
namespace net = boost::asio;      // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

class http_session : public std::enable_shared_from_this<http_session>
{
public:
    explicit http_session(tcp::socket socket)
        : socket_(std::move(socket)) {}

    void run()
    {
        do_read();
    }

private:
    tcp::socket socket_;
    beast::flat_buffer buffer_;
    http::request<http::string_body> req_;

    void do_read()
    {
        auto self = shared_from_this();
        http::async_read(socket_, buffer_, req_,
                         [self](beast::error_code ec, std::size_t bytes_transferred)
                         {
                             boost::ignore_unused(bytes_transferred);
                             if (!ec)
                             {
                                 std::cout << self->req_.body() << std::endl;
                                 self->do_write();
                             }
                         });
    }

    void do_write()
    {
        auto self = shared_from_this();
        std::string data_stream = "Continuous data stream..."; // Simulate continuous data stream
        auto res = std::make_shared<http::response<http::string_body>>(
            http::status::ok, req_.version());
        res->set(http::field::server, "Boost.Beast");
        res->set(http::field::content_type, "text/plain");
        res->body() = data_stream;
        res->prepare_payload();

        http::async_write(socket_, *res,
                          [self, res](beast::error_code ec, std::size_t)
                          {
                              if (!ec)
                              {
                                  self->do_write(); // Continue writing data
                              }
                          });
    }
};

class http_server
{
public:
    http_server(net::io_context &ioc, tcp::endpoint endpoint)
        : acceptor_(ioc, endpoint)
    {
        do_accept();
    }

private:
    tcp::acceptor acceptor_;

    void do_accept()
    {
        acceptor_.async_accept(
            [this](beast::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<http_session>(std::move(socket))->run();
                }
                do_accept();
            });
    }
};

int main()
{
    try
    {
        auto const address = net::ip::make_address("0.0.0.0");
        auto const port = static_cast<unsigned short>(79099);

        net::io_context ioc{1};
        tcp::endpoint endpoint{address, port};
        http_server server(ioc, endpoint);

        std::cout << "Server is running on port " << port << std::endl;

        ioc.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
