#include <iostream>
#include <memory>

void foo(const std::shared_ptr<int> s_ptr)
{
    std::cout << "\nfoo  " << s_ptr.use_count();
}

void foo_r(const std::shared_ptr<int> &s_ptr)
{
    std::cout << "\nfoo_ref  " << s_ptr.use_count();
}

std::shared_ptr<int> foo_m(std::shared_ptr<int> &&s_ptr)
{
    std::cout << "\nfoo_m  " << s_ptr.use_count();
    return std::move(s_ptr);
}

class Base : public std::enable_shared_from_this<Base>
{
public:
    void foo()
    {
        std::cout << "\n Base::foo\n";
    }

    std::shared_ptr<Base> getptr()
    {
        return std::shared_ptr<Base>(this);
    }
};

int main(void)
{

    // std::shared_ptr<int> s_ptr = std::make_shared<int>(1);
    // std::cout << "\nmain  " << s_ptr.use_count();

    // foo(s_ptr);

    // foo_r(s_ptr);

    // s_ptr = foo_m(std::move(s_ptr));

    // std::cout << "\nmain  " << s_ptr.use_count();

    auto b_sptr = std::make_shared<Base>();

    std::cout << b_sptr.use_count();

    b_sptr->foo();

    auto ss = b_sptr->getptr();

    std::cout << ss.use_count();

    ss->foo();

    return 0;
}