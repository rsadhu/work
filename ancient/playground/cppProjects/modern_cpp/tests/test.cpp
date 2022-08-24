#include <iostream>
#include <memory>

class Test
{
public:
    Test()
    {
        std::cout << "Test::Test" << ++s_ref << "\n";
    }
    ~Test()
    {
        std::cout << "Test::~Test" << --s_ref << "\n";
    }
    static int s_ref;
};

int Test::s_ref = 0;

void foo(int &refIn)
{
    int x = 100;
    refIn = x;
}

void fooPtr(int *p)
{
    int x = -100;
    *p = x;
}

void fooSp(std::shared_ptr<Test> &p)
{
    // p = std::make_shared<Test> ( Test());
}

void testBind(int x, int y, int z, int a)
{
    std::cout << " testBind:: " << x << "  " << y << "  " << z << " " << a << "\n";
}

constexpr int count() { return 5; }

int main(void)
{
    using namespace std::placeholders;
    int v = 10;
    std::cout << " value of v ::" << v << "\n";
    foo(v);
    std::cout << " value of v ::" << v << "\n";

    int *ptrV = new int(10);
    std::cout << " value of ptrv ::" << *ptrV << "\n";
    fooPtr(ptrV);
    std::cout << " value of ptrv ::" << *ptrV << "\n";

    std::shared_ptr<Test> sp(new Test);

    std::shared_ptr<Test> spArray(new Test[10], [](Test *p)
                                  { delete[] p; });

    /*    std::unique_ptr<Test> uPtrArray (new Test[10], [] ( Test * d ) {
            delete [] d;
        } );*/

    int arr[count() + 3] = {0};

    auto func = std::bind(testBind, _1, _3, _2, _4);

    func(1, 2, 3, 4);

    int x(1), y(2);

    int *xp = nullptr, ynp = 10;

    std::cout << "\nx : " << x << " y : " << y << std::endl;
    xp = &ynp;
    std::cout << "\nxp : " << *xp << " ynp : " << ynp << std::endl;

    return 0;
}
