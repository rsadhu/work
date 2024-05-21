
#include "logger.h"
#include <iostream>

Logger::Logger(const std::string &component_name) : component_name_(component_name)
{
    publisher_thread_ = std::move(std::thread(&Logger::publishLogData, this));
    read_buffer_ = true;
}

Logger::~Logger()
{
    exit_from_reader_thread_ = true;
    publisher_exit_ = true;
    read_buffer_ = true;
    cond_buffer_.notify_all();
    publisher_thread_.join();
    flush();
}

// writer thread
void Logger::log(const spdlog::details::log_msg &msg)
{
    Data log_event_data;
    log_event_data.log_level = msg.level;
    log_event_data.msg.assign(msg.payload.begin(), msg.payload.end());
    log_event_data.thread_id = msg.thread_id;
    log_event_data.date = msg.time.time_since_epoch().count();

    std::lock_guard<std::mutex> u_lock(mut_buffer_);
    buffer_.push_back(log_event_data);
    cond_buffer_.notify_all();
}

void Logger::flush()
{

    std::vector<Data> tmp;
    {
        std::lock_guard<std::mutex> lock(mut_buffer_);
        if (buffer_.size() == 0)
            return;
        buffer_.swap(tmp);
    }

    cond_buffer_.notify_all();
}

void Logger::set_pattern(const std::string &pattern) { (void)pattern; }

void Logger::set_formatter(std::unique_ptr<spdlog::formatter> sink_formatter) { (void)sink_formatter; }

// reader thread
void Logger::publishLogData()
{
    while (!publisher_exit_)
    {
        std::vector<Data> tmp;
        std::unique_lock<std::mutex> locker(mut_buffer_);
        cond_buffer_.wait(locker, [this]()
                          { return (buffer_.size() != 0 && read_buffer_) || exit_from_reader_thread_; });
        buffer_.swap(tmp);
        locker.unlock();
    }
}
