#include <thread>
#include <iostream>
#include <fstream>

int main(void)
{
    std::string str = "a:b:c:d:e:f:g::h:i:j";
    std::istringstream is(str);
    std::string item;
    while (std::getline(is, item, ':'))
    {
        std::cout << item << "\n";
    }
    return 0;
}
