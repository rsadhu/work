#include <iostream>
#include <memory>

class Base {
public:
    Base()
    {
        std::cout << "\nBase::Base ::" << ++m_ref << "\n";
    }

    ~Base()
    {
        std::cout << "\nBase::~Base " << --m_ref << "\n";
    }

    Base(const Base& rhs)
    {
        std::cout << "\nBase::Base::copy:: "<<++m_ref<<"\n";
    }

    Base& operator=(const Base& rhs)
    {
        std::cout << "\nBase::Base::= operator :: "<<++m_ref<<"\n";
        return *this;
    }

    Base(const Base&& rhs)
    {
        std::cout << "\nBase::Base::move\n";
    }

    Base& operator=(const Base&& rhs)
    {
        std::cout << "\nBase::Base::move = operator\n";
        return *this;
    }

    void display()
    {
        std::cout<<"\nBase::display \n";
    }

private:
    static int m_ref;
};

int Base::m_ref = 0;

Base& foo(Base& rhs)
{
    return rhs;
}

Base test(Base b)
{
    return b;
}

Base createBase()
{
    return Base();
}

Base createTempFromTemp(Base&& r)
{
    return r;
}

// Base& createRefFromTemp(Base&& r)
// {
//     Base s = r;
//     return s;
// }


template<typename T>
class MySmartPointer
{
    public:
    MySmartPointer(T *ptr):m_ptr(ptr)
    {

    }


    ~MySmartPointer()
    {
        delete m_ptr;
    }

    T & operator *()
    {
        return *m_ptr;
    }

    T * operator ->()
    {
        return m_ptr;
    }

    private:
    T *m_ptr;

    //static 
};


template<typename T>
void pass_my_pointer(MySmartPointer<T> &p)
{

}




int main(void)
{
    // Base t ;//= createTempFromTemp(createBase());

    // Base u = test(t);

    // Base p = foo(u);

    // std::cout << "\nmain:: ends\n";


    MySmartPointer pp (new Base);
    pp->display();


    std::unique_ptr<Base> up ( std::make_unique<Base>());
    //throw std::exception ();
    (*pp).display();

    up->display();

    pass_my_pointer(pp);

    std::string sss("xyz");

    std::cout<<"\n str size is "<<sizeof(sss)<<"\n";
    return 0;
}