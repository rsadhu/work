
#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/asio/connect.hpp>
#include <boost/config.hpp>

// Namespace aliases for convenience
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

// Function to send an HTTP GET request
void sendGetRequest(const std::string &host, const std::string &target, int version)
{
    try
    {
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        tcp::socket socket(ioc);

        // Resolve the host and connect
        auto const results = resolver.resolve(host, "80");
        net::connect(socket, results.begin(), results.end());

        // Set up the GET request
        http::request<http::empty_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send the HTTP request
        http::write(socket, req);

        // Read the response
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);

        // Print the response
        std::cout << res << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);
        if (ec && ec != beast::errc::not_connected)
        {
            throw beast::system_error{ec};
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to send an HTTP POST request with a body
void sendPostRequest(const std::string &host, const std::string &target, int version, const std::string &data)
{
    try
    {
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        tcp::socket socket(ioc);

        // Resolve the host and connect
        auto const results = resolver.resolve(host, "80");
        net::connect(socket, results.begin(), results.end());

        // Set up the POST request
        http::request<http::string_body> req{http::verb::post, target, version};
        req.set(http::field::host, host);
        req.set(http::field::content_type, "application/json");
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        req.body() = data;
        req.prepare_payload();

        // Send the HTTP request
        http::write(socket, req);

        // Read the response
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);

        // Print the response
        std::cout << res << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);
        if (ec && ec != beast::errc::not_connected)
        {
            throw beast::system_error{ec};
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    // Send a GET request to a sample endpoint
    sendGetRequest("jsonplaceholder.typicode.com", "/todos/1", 11);

    // Send a POST request with a JSON body
    std::string jsonData = R"({"title": "foo", "body": "bar", "userId": 1})";
    sendPostRequest("jsonplaceholder.typicode.com", "/posts", 11, jsonData);

    return 0;
}
