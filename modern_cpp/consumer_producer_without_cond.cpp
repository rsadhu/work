#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mu;
std::deque<int> buff;
using namespace std::chrono_literals;



void producer()
{

    int cnt = 10;
    while( cnt > -1 )
    {
        mu.lock();
        buff.push_front(cnt);
        mu.unlock();
        std::this_thread::sleep_for(10ms);
        cnt--;
    }
}

void consumer()
{
    int val = INT_MAX;
    while(val > 0)
   {
        mu.lock();
        if ( !buff.empty() )
        {
            val = buff.back();
            buff.pop_back();
            std::cout<< val <<"  ";
        }
        mu.unlock();
    }
}


int main(void)
{
    std::thread p(producer);
    std::thread c(consumer);

    p.join();
    c.join();

    std::cout<<"\nended well\n";

    return 0;

}