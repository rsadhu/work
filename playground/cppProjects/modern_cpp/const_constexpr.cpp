#include <iostream>
#include <string>

class Test {
    int m_age;
    std::string m_name;

public:
    explicit Test(int age = 0, std::string name = "test")
        : m_age(age)
        , m_name(name)
    {
    }
    /*  inline void setAge (int age)
  {
    m_age = age;
  }*/

    inline void setAge(const int& age)
    {
        m_age = age;
    }

    inline int age()
    {
        return m_age;
    }
    inline int age() const
    {
        return m_age;
    }

    //inline const int age () const
    //  {
    //    return m_age;
    //  }
};

int main(void)
{
    //const int *p = nullptr;
    //const int x =  100;
    ///const_cast<int&>(x) = 10;

    //std::cout<<x;

    const int x = 10;
    int const y = 11;
    int z = 12;
    std::cout << x << " " << y << " " << z << "\n";
    //  x = 13;
    //  y = 14;
    //  z = 15;
    //  std::cout << x << " " << y << " " << z << "\n"

    Test t;
    t.setAge(10);

    std::cout << " age is " << t.age() << "\n";

    const Test u;
    std::cout << " age is " << t.age() << "\n";
    return 0;
}
