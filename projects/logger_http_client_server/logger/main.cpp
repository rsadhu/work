#include "logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

int main()
{
    try
    {
        auto my_logger = std::make_shared<Logger>("my_logger");

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