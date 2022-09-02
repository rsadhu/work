#include <iostream>
#include <thread>

#define th_id std::this_thread::get_id()
class Worker {
public:
    void operator()()
    {
        std::cout << "\nWorker Thread called:: " << th_id;
    }
};

void thread_worker()
{
    std::cout << "\nthread_worker called  " << th_id;
}

int main(void)
{
    std::thread th(thread_worker);
    std::thread th1(std::move(Worker()));
    std::thread th2([]() { std::cout << "\nthread inside lamba is called   " << th_id; });
    th.join();
    th1.join();
    th2.join();
    std::cout << "\n";
    return 0;
}