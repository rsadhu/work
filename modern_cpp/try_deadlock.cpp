#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mu1, mu2;

int common_data = 1;

void problematic_thread()
{
    mu1.lock();
    mu2.lock();
    common_data++;
    std::cout << "\n problematic_thread::  " << common_data;
    mu1.unlock();
    mu2.unlock();
}

void working_thread()
{
    mu1.lock();
    mu2.lock();
    common_data--;
    std::cout << "\nworking_thread:: " << common_data;
    mu2.unlock();
    mu1.unlock();
}

int main(void)
{
    std::thread t1[10];
    std::thread t2[10];

    for (int i = 0; i < 1000000; i++)
    {
        t1[i] = std::thread(problematic_thread);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        t2[i] = std::thread(working_thread);
    }

    for (int i = 0; i < 1000000; i++)
    {
        t1[i].join();
        t2[i].join();
    }

    return 0;
}