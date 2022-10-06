#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu1, mu2;

int common_fork = 0;


using namespace std::chrono_literals;


void cook_well(int index)
{
    std::cout<<" cook_well dear Chef"<< index<<"\n";
    while(true)
    {
        // mu2.lock();
        // mu1.lock();

        common_fork += index;

        std::cout<< " thread 1::   " << common_fork;

                        std::this_thread::sleep_for(200ms);


        // mu2.unlock();
        // mu1.unlock();

        std::cout<< " ended  \n";

    }
}


void eat_well(int index)
{


    std::cout<<" eat_well dear Philospher"<< index<<"\n";

    std::this_thread::sleep_for(2000ms);


    while(true)
    {
        std::lock_guard  lock(mu1);
        common_fork += index;

        std::cout<<"thread::id."<<std::this_thread::get_id() << " :  \n";

        std::this_thread::sleep_for(20ms);

    }
}


int main(void)
{
    std::thread  th1, th2;

    th1 = std::thread(eat_well, 1);
    th2 = std::thread(eat_well, 2);

    th1.join();

    th2.join();

    return 0;
}