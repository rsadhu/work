
#include<iostream>


class Abc
{
 public:
 Abc(){}
 Abc(const Abc &rhs)
{
std::cout<<" \ncopy constructor ::\n";
}

Abc(Abc &&rhs)
{ 

std::cout<<" \nmove constructor ::\n";
}
};


void printInt(int &&v)
{

}


void printInt(int &v)
{

}


/*void printInt(int v)
{

}*/

Abc createAbc()
{ 
 return Abc();
}

void test (Abc c)
{
}

int main(void)
{
 int a =  9;
 printInt(a);
 printInt(10);

 auto cc =  createAbc();
 test(cc);
 test(createAbc());
 
 return 0;
}
