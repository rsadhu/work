#include <iostream>

/*

Order of calling constructors/destructors in inheritance
Copy Constructor sample
Explicit constructor : when is it used and why ?
Smart pointers
Explain advantages and disadvantages of std::make_shared over std::shared_ptr construction from plain C++ pointer.
lambda which accepts one variable by value and one by reference

pointers vs reference argument passing

template specialization


*/

/*
1. tell me your favourite 5 concepts of modern c++
2. what do you know about move and perfect forwarding?
3. can you implement your own smart pointer ?
4. dangling pointer, memory leaks, and avoidance ?
5. example code shallow and deep copy crash
6. rule of 3, 5 cpp?
7. is make_shared faster than shared_ptr<new T>()? if yes why ? what are other benefits?
8. where is custom deleter useful for shared_ptr <T>


class Test
{
    char *m_data = nullptr;
    size_t m_len = 0;
    public:

    Test(std::string str)
    {
        m_len = str.length();
        m_data = new char [str.length()];
        memcpy(m_data, str.c_str(), m_len);
    }

    ~Test()
    {
        std::cout<<"\n~Test\n";
        if (m_data)
            delete [] m_data;
        m_data = nullptr;
        m_len = 0;
    }

    void display()
    {
        std::cout<<" \n data is " << m_data <<"\n";
    }
};




void test(Test u)
{
    u.display();
}

int main(void)
{
    Test t("Hello World!!");

    t.display();

    test(t);

    return 0;
}






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

// #include <iostream>

// class Animal
// {
// public:
//     Animal()
//     {
//         std::cout << "\nAnimal::Animal\n";
//         makeSound();
//     }

//     ~Animal()
//     {
//         std::cout << "\nAnimal::~Animal\n";
//     }

//     virtual void makeSound()
//     {
//         std::cout << "\nAnimal::makesound \n";
//     }

//     void test()
//     {
//         makeSound();
//     }
// };

// class Dog : public Animal
// {

// public:
//     Dog()
//     {
//         std::cout << "\nDog::Dog\n";
//     }

//     ~Dog()
//     {
//         std::cout << "\nDog::~Dog\n";
//     }

//     void makeSound() override
//     {
//         std::cout << "\nDog::barks\n";
//     }
// };

// // template specialization
// template <typename T>
// void foo(T arg)
// {
//     std::cout << "\n data is " << arg << "\n";
// }

// template <>
// void foo(Dog d)
// {
//     d.makeSound();
// }

// // int main(void)
// // {
// //     std::cout << "\nFirst Try with DOG\n";
// //     Dog d;
// //     d.test();

// //     foo(123);
// //     foo("abc");
// //     foo('z');
// //     foo(d);

// //     return 0;
// // }

class Animal
{
public:
    Animal()
    {
        std::cout << "\nAnimal\n";
    }

    virtual void foo() { std::cout << "\nAnimal :: foo\n"; }

    ~Animal()
    {
        std::cout << "\n~Animal\n";
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        std::cout << "\nDog\n";
    }
    void foo()
    {
        std::cout << "\nDog :: foo\n";
    }
    ~Dog()
    {
        std::cout << "~Dog\n";
    }
};

int main(void)
{

    return 0;
}
