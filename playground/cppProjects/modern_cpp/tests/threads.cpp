#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>


std::condition_variable cond_;
std::mutex mu_;


std::queue<int> jobs_;

void reader(void)
{
       while(1)
       {
           std::unique_lock<std::mutex> lock(mu_);
           cond_.wait(lock , [](){return !jobs_.empty();});
           std::cout << jobs_.front()<<"\n";
           jobs_.pop();
           std::getchar();
       }
}

void writer(void)
{
    static int i = 0;
    while(1) {
        std::unique_lock<std::mutex> lock( mu_);
        jobs_.push(i++);
        cond_.notify_all();
    }

}


int main(void)
{
    std::cout << std::thread::hardware_concurrency();
    std::thread reader_thread(reader);

    std::thread writer_thread(writer);

    reader_thread.join();
    writer_thread.join();


    return 0;
}
