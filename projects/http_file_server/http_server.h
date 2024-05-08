#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <fstream>
#include <vector>

// Alias namespaces for convenience
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

// Server class
class FileServer
{
public:
    FileServer(asio::io_context &io_context, int port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        accept_connection(); // Start accepting connections
    }

private:
    tcp::acceptor acceptor_;

    void accept_connection()
    {
        auto socket = std::make_shared<tcp::socket>(acceptor_.get_executor().context());

        acceptor_.async_accept(
            *socket,
            [this, socket](boost::system::error_code ec)
            {
                if (!ec)
                {
                    std::cout << "New client connected" << std::endl;
                    handle_client(socket); // Handle the client
                }
                accept_connection(); // Continue accepting connections
            });
    }

    void handle_client(std::shared_ptr<tcp::socket> socket)
    {
        std::ifstream file("large_file.txt", std::ios::binary); // Open the file to serve

        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file." << std::endl;
            return;
        }

        const std::size_t buffer_size = 4096; // Define the chunk size
        std::vector<char> buffer(buffer_size);

        while (!file.eof())
        { // Read and send data in chunks
            file.read(buffer.data(), buffer_size);
            std::size_t bytes_read = file.gcount();

            asio::write(*socket, asio::buffer(buffer.data(), bytes_read));
        }

        std::cout << "File transfer complete." << std::endl;
    }
};
