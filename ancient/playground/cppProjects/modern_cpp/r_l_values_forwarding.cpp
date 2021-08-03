#include <iostream>
#include <utility>

class Test
{
    public:
        Test()=default;
        Test(const Test &)
        {
             std::cout<<"Copy constructor \n";
        }


        Test (Test && )
        {
            std::cout<<"\n MoveConstructor\n";

        }
        int x = 100;
};


template< typename T>
T relay(T &&b)
{
    return T(std::forward(b));
}



template<typename T>
void check(T &&rhs)
{
    play(rhs);
}


int main(void)
{
    int a =  10;

    Test t;
    auto x = relay<Test>(t);
    return 0;
}
