#include <iostream>
#include <type_traits>

template <typename Type = float, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
class Animal
{
    Type v_;

public:
    void makesound()
    {
        std::cout << "BAAAAAA\n";
    }
    Type weight() const
    {
        return v_;
    }
};
template <typename T = int, typename U>
void foo(T arg, U para)
{
    std::cout << "\nfoo " << arg << "  " << para << "\n"
              << "type is " << typeid(T).name()
              << " " << typeid(U).name() << "\n";
}

int main(void)
{
    Animal a;
    a.makesound();
    std::cout << a.weight();

    foo(1, "Tarzan Sadhu");

    foo("Rakesh Sadhu", 40);

    return 0;
}