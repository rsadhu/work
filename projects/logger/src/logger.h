
#ifndef LOG_ROUTER_H
#define LOG_ROUTER_H

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include <spdlog/details/log_msg.h>
#include <spdlog/sinks/sink.h>

struct Data
{
    std::string msg;
    long date;
    size_t thread_id;
    int log_level;
};

class Logger : public spdlog::sinks::sink
{
public:
    Logger(const std::string &component_name = "");
    ~Logger();

    virtual void log(const spdlog::details::log_msg &msg) override;
    virtual void flush() override;
    virtual void set_pattern(const std::string &pattern) override;
    virtual void set_formatter(std::unique_ptr<spdlog::formatter> sink_formatter) override;

protected:
    void publishLogData();

    std::atomic<bool> read_buffer_ = false;
    std::atomic<bool> publisher_exit_ = false, exit_from_reader_thread_ = false;

private:
    std::vector<Data> buffer_;
    mutable std::mutex mut_buffer_, mut_publisher_;
    std::condition_variable cond_buffer_;
    std::thread publisher_thread_;
    std::string component_name_;
};

#endif // LOG_ROUTER_H
