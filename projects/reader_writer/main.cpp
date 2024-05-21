#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <deque>
#include <chrono>

std::deque<int> buffer_;
std::condition_variable cond_;
std::mutex mu_;
std::atomic_bool exit_ = false;
int count = 0;
constexpr int N = 10000;

void reader_thread()
{
    std::unique_lock<std::mutex> u_lock(mu_);
    while (!exit_)
    {
        cond_.wait(u_lock, []()
                   { return !buffer_.empty() || exit_; });

        std::this_thread::sleep_for(std::chrono::milliseconds(3)); // Simulate work

        if (!buffer_.empty())
        {
            std::cout << buffer_.front() << "  ";
            buffer_.pop_front();
        }
    }
}

void writer_thread(int data)
{
    {
        std::lock_guard<std::mutex> lock(mu_);
        buffer_.push_back(data);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work

    cond_.notify_one();
}

int main(void)
{
    std::thread reader_th(reader_thread);

    for (int i = 0; i < N; i++)
    {
        writer_thread(i);
    }

    exit_ = true;

    cond_.notify_one();

    reader_th.join();

    return 0;
}
