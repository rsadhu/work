#include <iostream>

using namespace std;

class obj
{
public:
    void display()
    {
        std::cout << "obj::dislay\n";
    }
};
template <typename T>
class A
{
public:
    A() : mData(0)
    {
        mData = new T;
    }
    ~A()
    {
        delete mData;
        mData = 0;
    }

    T *operator->();
    T &operator*();
    void display() { cout << "\nA::display\n"; }

private:
    T *mData;
};

template <typename T>
T *A<T>::operator->()
{
    return mData;
}

template <typename T>
T &A<T>::operator*()
{
    return *mData;
}

int main(void)
{
    A<obj> a; // = new A<obj>();
    A<obj> *b = new A<obj>();
    a->display();
    (*b)->display();
    b->display();
    delete b;
    return 0;
}
