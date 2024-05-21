
#ifndef LOG_ROUTER_H
#define LOG_ROUTER_H
#include "http_client.h"

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

struct Data
{
    std::string msg;
    long date;
    size_t thread_id;
    int log_level;
};

const std::string PORT_NUM = "13563";
const std::string IP = "127.0.0.1";

class Logger
{
public:
    Logger(const std::string &component_name = "");
    ~Logger();

    virtual void log(const std::string &msg);

protected:
    void publishLogData();

    std::atomic<bool> client_created_ = false;
    std::atomic<bool> exit_from_reader_thread_ = false;

private:
    std::string adaptVecDataToString(std::vector<Data> &rhs);
    std::vector<Data> buffer_;
    mutable std::mutex mut_buffer_, mut_publisher_;
    std::condition_variable cond_buffer_;
    std::thread publisher_thread_;
    std::string component_name_;
    net::io_context ioc_;
    std::shared_ptr<http_client> client_;

    // mock data
    int mock_log_level_ = 0;
    size_t mock_thread_id_ = 1000;
    long mock_date_ = 1212121;
};

#endif // LOG_ROUTER_H
