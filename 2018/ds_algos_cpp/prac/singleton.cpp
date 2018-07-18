#include<iostream>

class Singleton;
class Singleton
{
 public:
 static Singleton & getInstance();
 void display()
{
 std::cout<<"Singleton::display\n";
}
 private:

 static Singleton s_Instance;
 static int s_refCnt;
 Singleton()
{
}

};

Singleton Singleton::s_Instance;
int Singleton::s_refCnt=0;


Singleton & Singleton::getInstance()
{
 return s_Instance;
}


int main(void)
{

 Singleton::getInstance().display();
 return 0;
}


