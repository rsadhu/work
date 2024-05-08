#include "common.h"

int countbits(long num)
{
    size_t count = 0;
    while (num)
    {
        if (num & 1)
            count++;
        num = num >> 1;
    }
    return count;
}

void test1()
{
    long num = 255;
    std::cout << "number of bits are " << countbits(num) << "\n";
}

void test2()
{

    int n = 127;
    std::vector<int> r(n);
    for (int i = 0; i <= n; i++)
    {
        r[i] = countbits(i);
    }
    for (auto it : r)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

int setNthBit(int num, int pos)
{
    std::cout << num << "  " << pos << " ";
    int bit = 1 << pos;
    return num | bit;
}

int resetNthBit(int num, int pos)
{
    std::cout << num << "  " << pos << " ";
    int bit = ~(1 << pos);
    return num & bit;
}

int reverseBits(int num, int sz)
{
    int new_num = 0;
    int pos = 0;
    while (num)
    {
        if (num & 1)
        {
            new_num |= 1 << (sz - pos);
        }
        pos++;
        num >>= 1;
    }
    return new_num;
}

int missing_number(std::vector<int> &list)
{
    int missng_num = list.size();
    for (int i = 0; i < list.size(); i++)
    {
        missng_num = missng_num ^ list[i] ^ i;
    }
    return missng_num;
}

/*
    1 = 0001
    2 = 0010
    3 = 0011
*/
int main(int argc, char *argv[])
{

    // for (int i = 0; i < 8; i++)
    // {
    //     int num = 0;
    //     num = setNthBit(num, randomNumGenerator(8));
    //     std::cout << num << " ";
    //     std::cout << "\n";
    // }

    // for (int i = 0; i < 8; i++)
    // {
    //     int num = 255;
    //     num = resetNthBit(num, randomNumGenerator(8));
    //     std::cout << num << " ";
    //     std::cout << "\n";
    // }

    // std::cout << reverseBits(1, 4) << " ";
    // std::cout << reverseBits(16, 4) << "\n";

    std::vector<int> list = {0, 1, 3, 4, 6, 5};
    std::cout << missing_number(list);

    return 0;
}