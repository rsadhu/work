/*
1. tell me your favourite 5 concepts of modern c++
2. what do you know about move and perfect forwarding?
3. can you implement your own smart pointer ?
4. dangling pointer, memory leaks, and avoidance ?
5. example code shall and deep copy crash
6. rule of 3, 5 cpp?
7. is make_shared faster than shared_ptr<new T>()? if yes why ? what are other benefits?
8. where is custom deleter useful for shared_ptr <T>

e.g shared_ptr<T> sp ( new T[10], [] ( T *p){ delete [] p;});

Dog *saved_ptr =  nullptr;
void save(Dog *p)
{
 saved_ptr = p;
}

void test()
{
    shared_ptr<Dog> dog_p(new Dog("Bruno"));
    auto *pt = dog.p->get();
    save(pt);
}

int
main(void)
{
 test();
 // what will saved_ptr have now?
 return 0;
}



*/

#include <iostream>

class Animal
{
public:
    Animal()
    {
        std::cout << "\nAnimal::Animal\n";
        makeSound();
    }

    ~Animal()
    {
        std::cout << "\nAnimal::~Animal\n";
    }

    virtual void makeSound()
    {
        std::cout << "\nAnimal::makesound \n";
    }

    void test()
    {
        makeSound();
    }
};

class Dog : public Animal
{

public:
    Dog()
    {
        std::cout << "\nDog::Dog\n";
    }

    ~Dog()
    {
        std::cout << "\nDog::~Dog\n";
    }

    void makeSound() override
    {
        std::cout << "\nDog::barks\n";
    }
};

// template specialization
template <typename T>
void foo(T arg)
{
    std::cout << "\n data is " << arg << "\n";
}

template <>
void foo(Dog d)
{
    d.makeSound();
}

int main(void)
{
    std::cout << "\nFirst Try with DOG\n";
    Dog d;
    d.test();

    foo(123);
    foo("abc");
    foo('z');
    foo(d);

    return 0;
}