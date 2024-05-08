#include "http_server.h"

constexpr u_int16_t port_no = 30303;

int main()
{
    try
    {
        asio::io_context io_context;
        FileServer server(io_context, port_no); // Start the server on port 12345
        io_context.run();                       // Run the IO context
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}