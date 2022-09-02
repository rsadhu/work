#include <iostream>

int getSum(int a, int b)
{
    int res = 0;
    int carry = 0;

    // 4 = 0100
    // 3 = 0011

    // bit1&bit2 = carry ?
    // bit1 ^ bit2 = sum
    // res

    return res;
}

int main(void)
{
    int a = 4, b = 3;
    std::cout << getSum(a, b);
    return 0;
}