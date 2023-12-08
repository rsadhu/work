#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class WebServer
{
public:
    WebServer(std::string url = "", size_t port = 8100);

    void start();

private:
    std::string url_;
    size_t port_;
};

#endif // WEBSERVER_H