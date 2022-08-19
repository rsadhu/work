#include <iostream>
#include <memory>


class Animal
{
    public:
    Animal() = default;

    void speak(std::string word)
    {
        std::cout<<"\nI speak "<< word<<"\n";
    }

    void test();

};


class Human
{
    public:
    Human(Animal * dependency):impl_(dependency)
    {
        std::cout<<"\nHuman Called\n";
    }

    ~Human()
    {
        delete impl_;
    }

    void makeSound()
    {
        impl_->speak("Bow Bow");
    }
    private:
    Animal* impl_ =  nullptr;
};

void Animal::test()
{
    Human ptr(this);
    ptr.makeSound();
    std::cout<<" test ends\n";

}


int main(void)
{
    Animal anim;
    anim.test();
    return 0;
}