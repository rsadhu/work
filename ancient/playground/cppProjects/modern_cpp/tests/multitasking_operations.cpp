#include <iostream>
#include <future>
#include <thread>
#include <mutex>
//#include<pair>

int main(void)
{
    auto it = std::async(std::launch::async, []()
                         { return 6.27; });

    std::cout << " the result :: >> " << it.get() * 15;

    auto t = std::make_tuple(1, "char", 'c', std::make_pair(10, "ten"));

    // for(int i = 0;i < t.size();i++)
    {
        std::cout << " ===> " << std::get<0>(t);
        std::cout << " ===> " << std::get<1>(t);
        std::cout << " ===> " << std::get<2>(t);
    }
    return 0;
}
