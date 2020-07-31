#include <iostream>
#include <tuple>

template <typename T>
void process(T arg)
{
    //return  arg;
    // to nothing
}

//std::tuple tp;

template <typename T, typename... Args>
void process(T arg1, Args... args)
{
    std::cout << "\nProcess called " << arg1 << "\n";
    process(args...);
    //tp.insert(it);
}

//template<>
void test(...)
{
    // std::cout<<"\n integer value is "<<p<<"\n";
}

int main(void)
{
    process("", 1, 'a', 5.5, 0.9f);
    return 0;
}
