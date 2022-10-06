#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

#include <shared_mutex>

std::vector<int> open_channel;
std::shared_mutex mu;

int cnt = 0;

using namespace std::chrono_literals;


void reader()
{
    std::lock_guard lock(mu);
    for (auto it: open_channel)
    {
        std::cout<<it <<" ";
    }
    std::cout<<"\n";
}


void writer()
{
    std::unique_lock lock(mu);
    open_channel.push_back(cnt++);
}


int main(void)
{
    std::cout<<" \n main starts\n";

    std::thread reader_th[100], writer_th[100];
    for (int i = 0; i < 100; i++)
    {
        reader_th[i] =  std::thread(reader);
        writer_th[i] =  std::thread(writer);

        std::this_thread::sleep_for(200ms);
    }


     for (int i = 0; i < 100; i++)
    {
        reader_th[i].join();
        writer_th[i].join();
    }
    return 0;
}