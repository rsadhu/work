#include <iostream>

int main(void)
{
    int x = 10;

    decltype(x) y = 9;

    std::cout << x << " " << y << "\n";
    return 0;
}