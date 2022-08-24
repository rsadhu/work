#include <iostream>

// template<>
// class Base
// {

// };
template <typename T>
class Base
{
public:
    Base()
    {
        std::cout << "\nBase::Base\n";
    }

    Base(int p)
        : m_data(p)
    {
        std::cout << "\nBAse::Base::int \n";
    }

    virtual ~Base()
    {
        std::cout << "\nBase::~Base\n";
    }

    virtual void foo()
    {
        std::cout << " Base::foo\n";
    }
    void test()
    {
        std::cout << "\nBase::test\n";
        foo();
    }

    void run()
    {
        processDer();
    }

    void processDer()
    {
        std::cout << "Base::processDer\n";
        static_cast<T *>(this)->processDer();
    }

    Base &operator+(Base &rhs)
    {
        m_data += rhs.m_data;
        return *this;
    }

    void display()
    {
        std::cout << "\nBase::display  " << m_data << "\n";
    }

private:
    int m_data;
};

class Der : public Base<Der>
{
public:
    Der()
        : Base(100)
    {
        std::cout << "\nDer:Der\n";
    }

    ~Der()
    {
        std::cout << "\nDer::~Der\n";
    }

    void foo()
    {
        std::cout << "Der::foo\n";
    }

    void processDer()
    {
        std::cout << "Der::processDer\n";
    }
};

int main(void)
{

    // Der d;
    // d.run();

    // Base<Der> *b = new Der();
    // b->test();
    // delete b;

    Base<int> bb(10);
    Base<int> cc(10);
    bb = bb + cc;

    bb.display();

    // bb.test();
    return 0;
}