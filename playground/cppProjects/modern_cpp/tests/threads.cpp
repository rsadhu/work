#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>
#include <future>


std::condition_variable cond_;
std::mutex mu_;


std::queue<int> jobs_;

void reader(void)
{
    auto val = 0;
       while(val < 99)
       {
           std::unique_lock<std::mutex> lock(mu_);
           cond_.wait(lock , [](){return !jobs_.empty();});
           val = jobs_.front();
           std::cout << val<<"\n";
           jobs_.pop();
       }
}

void writer(void)
{
    int i  = 0;
    while(i < 100) {
        std::unique_lock<std::mutex> lock( mu_);
        jobs_.push(i++);
        cond_.notify_all();
    }
}

int process(std::future<int> &data)
{
    int seed =  data.get();
    return seed * seed;
}




int main(void)
{
    std::cout << std::thread::hardware_concurrency();
    std::thread reader_thread(reader);

    std::thread writer_thread(writer);

    reader_thread.join();
    writer_thread.join();

    std::promise<int> prom_data;
    std::future<int> promised_future =  prom_data.get_future();
    std::future<int> res_fut =  std::async(std::launch::async, process, std::ref(promised_future));
    prom_data.set_value(9);
    std::cout<<res_fut.get();

    return 0;
}
