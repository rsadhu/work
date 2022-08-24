#include <iostream>

template <typename U>
class Test
{
public:
    template <typename T>
    void foo(T &);

    void disp(U &);
    template <typename XX>
    static void sFoo(XX);
};

template <typename U>
template <typename T>
void Test<U>::foo(T &d)
{

    std::cout << " Test:: foo\n";
}

template <typename U>
void Test<U>::disp(U &s)
{
    std::cout << " Test:: disn\n";
}

template <typename U>
template <typename XX>
void Test<U>::sFoo(XX x)
{
    std::cout << "Test::sFoo\n";
}

int main(void)
{
    std::cout << "main\n";
    Test<int> a;
    int x = 10;
    a.disp(x);
    float f = 10.5f;
    a.foo<float>(f);
    Test<int>::sFoo<float>(10.1);
    return 0;
}
