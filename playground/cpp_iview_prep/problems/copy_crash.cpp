#include <iostream>
/*
class Test
{
    char *m_data = nullptr;
    size_t m_len = 0;
    public:
    Test(std::string str)
    {
        m_len = str.length();
        m_data = new char [str.length()];
        memcpy(m_data, str.c_str(), m_len);
    }

    Test(const Test &rhs)
    {
        m_data = new char[rhs.m_len];
        memcpy(m_data, rhs.m_data, rhs.m_len);
        m_len = rhs.m_len;
    }

    Test & operator = (const Test &rhs)
    {
        if (m_data)
        {
            //delete this;
            delete []m_data ;
            m_len = 0;
        }
        m_data = new char[rhs.m_len];
        memcpy(m_data, rhs.m_data, rhs.m_len);
        m_len = rhs.m_len;
        return *this;
    }

    ~Test()
    {
        std::cout<<"\n~Test\n";
        delete [] m_data;
        m_data = nullptr;
        m_len = 0;
    }

    void display()
    {
        std::cout<<" \n data is " << m_data <<"\n";
    }
};

*/

class Test
{
    char *m_data = nullptr;
    size_t m_len = 0;

public:
    Test(std::string str)
    {
        m_len = str.length();
        m_data = new char[str.length()];
        memcpy(m_data, str.c_str(), m_len);
    }

    ~Test()
    {
        std::cout << "\n~Test\n";
        if (m_data)
            delete[] m_data;
        m_data = nullptr;
        m_len = 0;
    }

    void display()
    {
        std::cout << " \n data is " << m_data << "\n";
    }
};

void test(Test u)
{
    u.display();
}

int main(void)
{
    Test t("Hello World!!");

    t.display();

    test(t);

    return 0;
}
