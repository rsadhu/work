#include <iostream>
#include <atomic>

class Test
{
    public:
    Test() = default;
    Test(int d, std::string &rhs):m_data(d), m_str(rhs)
    {

    }

    std::string  str()const { return m_str;}
    int data()const { return m_data;}

    private:
    int m_data;
    std::string m_str;
};

std::atomic<Test> t;
t.store({10, "hello this is Rakesh"});

int main(void)
{


    return 0;
}