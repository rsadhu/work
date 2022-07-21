#include <iostream>


class DataType
{
    public:
    // explicit DataType(int d):m_data(d)
    // {
    //     std::cout<<"\nExplicit DataType::int\n";
    // }

    DataType(int c):m_data(c)
    {
        std::cout<<"\nDataType::int\n";
    }

    //private:
        int m_data {};
};

void foo(DataType d)
{
    std::cout<<d.m_data;
}

int main(void)
{
    DataType t(1);
    foo(1);
    return 0;
}