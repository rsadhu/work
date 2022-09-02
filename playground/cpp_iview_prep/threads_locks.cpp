#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>
#include <iostream>

std::queue<int> production_line;
std::condition_variable cond_;
std::mutex mu;
std::mutex cout_mu;

template <typename type>
class Functor
{
public:
    void operator()(type arg)
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> locker(cout_mu);
        std::cout << arg << "\n";
    }
};

void worker()
{
    auto data = 1;
    while (data != 0)
    {
        std::unique_lock<std::mutex> lock(mu);
        cond_.wait(lock, []()
                   { return !production_line.empty(); });
        data = production_line.front();
        production_line.pop();
        lock.unlock();

        std::lock_guard<std::mutex> c_lock(cout_mu);
        std::cout << data << "\n";
    }
}

void producer()
{
    int i = 100;
    while (i-- > -1)
    {

        std::unique_lock<std::mutex> lock(mu);
        production_line.push(i);
        lock.unlock();
        cond_.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(void)
{

    std::thread worker_thread(worker);
    std::thread producer_thread(producer);

    Functor<std::string> f;
    std::string data = "testing threading";
    std::thread test_thread[100];
    for (int i = 0; i < 100; i++)
    {
        test_thread[i] = std::thread(f, std::ref(data));
    }

    worker_thread.join();
    producer_thread.join();

    for (int i = 0; i < 100; i++)
        test_thread[i].join();

    return 0;
}