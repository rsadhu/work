#include <iostream>

class Animal {
public:
    Animal()
    {
        std::cout << "\n\n";
    }

    Animal(const Animal& rhs)
    {
        std::cout << "\nCopy Animal\n";
    }

    Animal& operator=(const Animal& rhs)
    {
        std::cout << "\nAnimal = operator\n";
        return *this;
    }

    Animal(Animal&& rhs)
    {
        std::cout << "\nmove Animal\n";
    }

    Animal& operator=(Animal&& rhs)
    {
        std::cout << "\nmove Animal\n";
    }
};