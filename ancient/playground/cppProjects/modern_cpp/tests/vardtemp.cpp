#include <iostream>

/*template<typename T>
T adder<T a>
{
    return a;
}


template<typename T, typename... arg>
T adder(T a, Args... args)
{
    return a+ adder(args);
}
*/
namespace
{
    template <typename T>
    T adder(T v)
    {
        return v;
    }

    template <typename T, typename... Args>
    T adder(T first, Args... args)
    {
        return first + adder(args...);
    }

    template <typename T>
    T add(T a, T b)
    {
        return a + b;
    }

}

int main(void)
{
    std::cout << "\n"
              << adder(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << "\n";
    std::cout << "\n"
              << add(1, 9) << "\n";
    std::cout << "\n"
              << add(1.0, 9.1) << "\n";
    // std::cout<<"\n"<<add('a','b')<<"\n";
    std::cout << "\n"
              << add(std::string("abc"), std::string("def")) << "\n";
    return 0;
}
