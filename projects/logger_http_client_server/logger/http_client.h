#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <thread>

namespace beast = boost::beast;   // from <boost/beast.hpp>
namespace http = beast::http;     // from <boost/beast/http.hpp>
namespace net = boost::asio;      // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

class http_client : public std::enable_shared_from_this<http_client>
{
public:
    http_client(net::io_context &ioc, const std::string &host, const std::string &port)
        : resolver_(ioc), socket_(ioc), ioc_(ioc)
    {
        // Resolve the host and port
        auto const results = resolver_.resolve(host, port);
        // Connect to the server
        net::connect(socket_, results.begin(), results.end());
        // Start the io_context in a separate thread
        io_thread_ = std::thread([this]()
                                 { ioc_.run(); });
    }

    ~http_client()
    {
        ioc_.stop();
        if (io_thread_.joinable())
        {
            io_thread_.join();
        }
    }

    void do_write(const std::string &data_stream)
    {
        auto req = std::make_shared<http::request<http::string_body>>(http::verb::post, "/", 11);
        req->set(http::field::host, "localhost");
        req->set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        req->set(http::field::content_type, "text/plain");
        req->body() = data_stream;
        req->prepare_payload();

        auto self = shared_from_this();
        http::async_write(socket_, *req,
                          [this, self, req](beast::error_code ec, std::size_t)
                          {
                              if (ec)
                              {
                                  std::cerr << "Write error: " << ec.message() << std::endl;
                              }
                          });
    }

private:
    tcp::resolver resolver_;
    tcp::socket socket_;
    net::io_context &ioc_;
    std::thread io_thread_;
};
