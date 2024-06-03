
#include "logger.h"

Logger::Logger(const std::string ip, const std::string &component_name) : component_name_(component_name)
{
    IP_ = ip;
    publisher_thread_ = std::move(std::thread(&Logger::publishLogData, this));

    try
    {
        if (!client_created_)
        {
            client_ = std::make_shared<http_client>(ioc_, IP_, PORT_NUM_);
            client_created_ = true;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "\nBoost connection failed " << e.what() << "\n";
        publisher_thread_.join();
    }
}

Logger::~Logger()
{
    cond_buffer_.notify_all();
    exit_from_reader_thread_ = true;
    publisher_thread_.join();
}

// writer thread
void Logger::log(const std::string &msg)
{
    Data log_event_data;
    log_event_data.log_level = mock_log_level_++;
    log_event_data.msg.assign(msg.begin(), msg.end());
    log_event_data.thread_id = mock_thread_id_++;
    log_event_data.date = mock_date_++;

    std::lock_guard<std::mutex> u_lock(mut_buffer_);
    buffer_.push_back(log_event_data);
    cond_buffer_.notify_one();
}

// reader thread
void Logger::publishLogData()
{
    std::unique_lock<std::mutex> locker(mut_buffer_);

    while (true)
    {
        cond_buffer_.wait(locker, [this]()
                          { return buffer_.size() != 0 || exit_from_reader_thread_; });

        std::vector<Data> tmp;
        buffer_.swap(tmp);
        client_->do_write(adaptVecDataToString(tmp));
        if (exit_from_reader_thread_)
        {
            break;
        }
    }
}

std::string Logger::adaptVecDataToString(std::vector<Data> &rhs)
{
    std::string msg;
    for (auto ele : rhs)
    {
        msg += ele.msg;
        msg += "\ndate: " + std::to_string(ele.date);
        msg += "\nthread_id: " + std::to_string(ele.thread_id);
        msg += "\nlog_level: " + std::to_string(ele.log_level);
        msg += "\n";
    }
    return msg; // expecting compiler will do optimization
}