#include <iostream>

class Test {
public:
    /*void set (const int d)
  {
    std::cout << " setter non const\n";
    m_data = d;
  }*/

    void set(const int d)
    {
        std::cout << " setter  const\n";
        int x = 10;
        x = d;
    }

    void set(const int d) mutable
    {
        m_dan = d;
    }

private:
    int m_data = 1;
    const m_dan = 10;
};

int main(void)
{
    Test t;
    t.set(10);
    //const Test u;
    // u.set (10);
    return 0;
};
