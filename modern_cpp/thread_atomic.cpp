#include <atomic>
#include <iostream>

class Test
{
    public:
    Test() {}
    Test(int d, std::string rhs):m_data(d), m_str(rhs)
    {
    }

    Test(const Test &rhs)
    {
        
    }
    std::string  str()const { return m_str;}
    int data()const { return m_data;}

private:
    int m_data;
    std::string m_str;
};


int main(void)
{
std::atomic<bool > tmp;

//Test x{10, "hello this is Rakesh"};

tmp.store(false);

    return 0;
}