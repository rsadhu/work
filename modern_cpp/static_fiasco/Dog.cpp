#include "Dog.h"
#include "Cat.h"
#include <iostream>

Cat c("Kitty");

void Dog::bark()
{
    std::cout << _name << " Dog :: barks \n";
}

Dog::Dog(char *name)
{
    this->_name = name;
    c.meow();
}
