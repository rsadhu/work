#include <iostream>

struct Data
{
    char ch;
    short s;
    int num;
    double f;
};

int main(void)
{
    std::cout << " size of char " << sizeof(char) << "\n";
    std::cout << " size of int " << sizeof(int) << "\n";
    std::cout << " size of short " << sizeof(short) << "\n";
    std::cout << " size of long " << sizeof(long) << "\n";
    std::cout << " size of double " << sizeof(double) << "\n";
    std::cout << " size of float " << sizeof(float) << "\n";
    std::cout << " size of int_8 " << sizeof(int8_t) << "\n";
    std::cout << " size of int_16 " << sizeof(int16_t) << "\n";
    std::cout << " size of int_32 " << sizeof(int32_t) << "\n";
    std::cout << " size of Data " << sizeof(Data) << "\n";
    return 0;
}