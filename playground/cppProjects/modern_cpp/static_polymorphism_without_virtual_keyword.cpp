#include <iostream>

template <typename T>
class Base {
public:
    Base()
    {
    }
    void run()
    {
        exec();
    }

    //virtual
    void exec()
    {
        std::cout << " Base::exec\n";
        static_cast<T*>(this)->exec();
    }
};

class Der : public Base<Der> {

public:
    void exec()
    {
        std::cout << " Der::exec\n";
    }
};

int main(void)
{
    Der r;
    r.run();
    return 0;
}
