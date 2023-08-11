#include <chrono>
#include <condition_variable>
#include <fstream>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>
#include <thread>
#include <vector>
constexpr int KNUM = 10000;
using namespace std::chrono_literals;
class Test
{
    std::vector<int> buffer_;
    std::thread worker_;
    std::mutex mu_, console_mu_;
    std::condition_variable cond_;

public:
    Test();
    ~Test();
    void print(int d);
    void reader();
    std::atomic_bool worker_exit_ = true;
    std::ofstream fs_;
};
Test::Test() { worker_ = std::thread(&Test::reader, this); }
Test::~Test()
{
    worker_exit_ = false;
    cond_.notify_all();
    if (worker_.joinable())
        worker_.join();
}
void Test::print(int d)
{
    std::unique_lock<std::mutex> lock(mu_);
    buffer_.push_back(d);
    lock.unlock();
    cond_.notify_all();
}
void Test::reader()
{
    while (worker_exit_)
    {
        std::unique_lock<std::mutex> lock(mu_);
        cond_.wait(lock, [this]()
                   { return buffer_.size() != 0 || !worker_exit_; });
        buffer_.clear();
    }
}
void multiple_threads()
{
    size_t num_of_threads_available = std::thread::hardware_concurrency();
    std::vector<std::thread> ths(num_of_threads_available);
    for (size_t cnt = 0; cnt < num_of_threads_available; cnt++)
    {
        ths[cnt] = std::thread([]()
                               {
      Test t;
      int iterations = KNUM;
      while (--iterations != 0) {
        t.print(iterations);
      } });
    }
    for (size_t cnt = 0; cnt < num_of_threads_available; cnt++)
    {
        ths[cnt].join();
    }
}
void no_thread()
{
    Test t;
    int iterations = KNUM;
    while (--iterations != 0)
    {
        t.print(iterations);
    }
}
void single_thread()
{
    std::cout << " ##################### 1 #####################\n";
    no_thread();
    std::cout << " ##################### 2 #####################\n";
    std::thread th([]()
                   {
    Test t;
    int iterations = KNUM;
    while (--iterations != 0) {
      t.print(iterations);
    } });
    th.join();
}
int main()
{
    std::cout << " STARTED\n";

    for (int i = 0; i < KNUM; i++)
        multiple_threads();
    std::cout << " ENDED \n";
    return 0;
}