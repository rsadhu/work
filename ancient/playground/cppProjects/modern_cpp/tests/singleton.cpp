#include <iostream>
#include <thread>
#include <mutex>

int i = 0;
class Singleton;
class Singleton
{
public:
    static Singleton &getInstance();
    void display()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        std::cout << "Singleton::display" << i++ << "\n";
    }

private:
    static Singleton s_Instance;
    static int s_refCnt;
    std::mutex mMutex;
};

Singleton Singleton::s_Instance;
int Singleton::s_refCnt = 0;

Singleton &Singleton::getInstance()
{
    return s_Instance;
}

void threadFunc(Singleton *sptr)
{
    if (sptr)
    {
        sptr->display();
    }
}

int main(void)
{
    unsigned int n = std::thread::hardware_concurrency();

    std::thread threads[n * 5];
    for (int i = 0; i < n * 5; i++)
    {
        threads[i] = std::thread(threadFunc, &Singleton::getInstance());
    }

    for (int i = 0; i < n * 5; i++)
    {
        threads[i].join();
    }
    return 0;
}
