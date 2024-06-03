#include "logger.h"

int main(int argc, char *argv[])
{
    try
    {
        std::string ip = "127.0.0.1";
        if (argc == 2)
        {
            ip = argv[1];
        }
        auto my_logger = std::make_shared<Logger>("my_logger", ip);

        my_logger->log("Logger initialized");

        my_logger->log("This is an info message");
        my_logger->log("This is a debug message");
        my_logger->log("This is a warning message");
        my_logger->log("This is an error message");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}