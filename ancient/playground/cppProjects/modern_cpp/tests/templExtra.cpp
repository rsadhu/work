#include <iostream>

template <typename T>
bool isGreater(T a, T b)
{
    return a > b ? true : false;
}

template <typename T, typename U = int>
void justPrint(T a, U b)
{
    std::cout << " JustPrint::  " << a << "  " << b << std::endl;
}

int main()
{
    std::cout << "isGreator::  " << isGreater(9, 1) << std::endl;
    std::cout << "isGreator::  " << isGreater(9, 1) << std::endl;
    std::cout << "isGreator::  " << isGreater(9, 1) << std::endl;
    justPrint<int, int>(10, 20);
    justPrint(200, 2000);
    justPrint('a', 'b');
    justPrint('a', 10);
    justPrint<char>('z', 10);
    u
