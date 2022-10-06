#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <vector>

std::vector<int> common_data;
std::condition_variable cond;
std::mutex mu;
std::random_device rd;  // Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib(0, 6000);

void reader()
{
    int val = 0;
    while (val != 6000)
    {
        std::unique_lock locker(mu);
        cond.wait(locker, []()
                  { return !common_data.empty(); });

        val = common_data.back();
        std::cout << val << "  ";
        common_data.pop_back();
        cond.notify_all();
        locker.unlock();
    }
    // cond.notify_all();
}

void writer()
{
    int random_variable = 1;
    while (random_variable != 0)
    {
        std::unique_lock locker(mu);
        cond.wait(locker, []()
                  { return common_data.empty(); });

        random_variable = distrib(gen);

        common_data.push_back(random_variable);
        cond.notify_one();
        locker.unlock();
    }
}

int main(void)
{
    std::thread ts[2];

    ts[0] = std::thread(reader);
    ts[1] = std::thread(writer);

    for (int i = 0; i < 2; i++)
        ts[i].join();

    return 0;
}