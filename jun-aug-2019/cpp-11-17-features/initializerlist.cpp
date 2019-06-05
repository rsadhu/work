#include<iostream>
#include<string>

using namespace std;

 struct  stud {
	int someint;
	string somestring;
	char somechar;
};

using mystruct = struct stud;


//template<typename T>
class Test
{

 int age;
 string name;
 mystruct comp;

public:

 Test (const std::initializer_list<int> &l)
{
}

/*emplate<> 
 Test( const std::initializer_list<int> &list)
 {
  std::cout<< "\nst::initializer_list\n";
 }*/

//Test(int a, string name, mystruct str)
//{
// std::cout<<"\n Regular Constructor\n";
//}

Test()
{
 std::cout<<" Test:: Test\n";
}
 
};


template<typename T>
T add(T a, T b)
{
 return a+b;
}


//specialization
template<>
int add(int a, int b)
{
 return a+b;
}

// specialization 
template<>
string add(string a, string b)
{
 return a+b;
}


class Abc
{
 public:
int age;
};

int main(void)
{
//	Test t = { 1, "Rkesh", {19, "rs", 'D'}};
//	Test t1 =  { 1, 2, 3, 4, 5 };
	Test t2 = { 1, 3, 5 , 7, 9 };

    auto aa = add(9, 1);
    auto bb = add(9.1, 0.9);
	auto cc = add(string("test"), string(" me"));

    Abc c{3};
  

 return 0;
}
