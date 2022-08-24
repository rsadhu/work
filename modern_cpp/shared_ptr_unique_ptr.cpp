#include <iostream>
#include <memory>

class Test
{
public:
    void run();
    void display()
    {
        std::cout << " Test::display\n";
    }
};

class HandlerImpl;
class Handler
{
    std::shared_ptr<Test> impl_;

public:
    Handler(std::shared_ptr<HandlerImpl> impl_p);
};

class HandlerImpl
{
public:
    HandlerImpl(std::shared_ptr<Test> t_ptr)
    {
    }
    void foo()
    {
    }
};

void Test::run()
{
    auto h = std::make_shared<Handler>(this);
    // h->run();
}

int main(void)
{
    Test t;
    t.run();

    t.display();
    return 0;
}