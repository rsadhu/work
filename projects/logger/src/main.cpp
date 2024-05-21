#include "logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>

void init_logger()
{
    auto my_logger = std::make_shared<Logger>("my_logger");
    my_logger->set_level(spdlog::level::debug);
    my_logger->set_pattern("[%Y-%m-%d %H:%M:%S %z] [%l] %v");

    std::vector<spdlog::sink_ptr> sinks{my_logger};

    auto logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::debug);
    logger->flush_on(spdlog::level::debug);
    spdlog::set_default_logger(logger);
    spdlog::warn("Logger initialized");
}

int main(void)
{
    init_logger();

    spdlog::info("This is an info message");
    spdlog::debug("This is a debug message");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");

    return 0;
}