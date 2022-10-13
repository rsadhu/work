#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "\nBase\n";
    }

    ~Base()
    {
        std::cout << "\n~Base\n";
    }
};

class Der : Base
{
public:
    Der()
    {
        std::cout << "\nDer\n";
    }

    ~Der()
    {
        std::cout << "\n~Der\n";
    }
};

int main(void)
{
    Der d;
    return 0;
}
#include <queue>
#include <stack>
#include <set>


bool isAnIsland(std::vector<std::vector<int, int>> &array, int row, int col)
{   
}