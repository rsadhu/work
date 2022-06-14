#include "Cat.h"
#include "Dog.h"
#include <iostream>

extern Dog d;

void Cat::meow()
{
    std::cout << _name << " Cat :: meows \n";
}

Cat::Cat(char* name)
{
    this->_name = name;
    d.bark();
}
