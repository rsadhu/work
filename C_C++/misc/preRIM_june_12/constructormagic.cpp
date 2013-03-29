#include<iostream>
using namespace std;

class Bomb
{
public:
	Bomb()
{	
		cout<<"Bomb::Bomb\n";
	}
	Bomb(int a)
	{
	cout<<"\n Bomb::Bomb::para\n";
	}

};

int main(void)
{
 Bomb b(1);
 return 0;
}
