#include<iostream>

using namespace std;

int pow(int base , int pow)
{
int tmp = 1;
 while(pow-- >0)
 tmp = tmp*base;
 cout<<pow<<"  pow  :: "<<tmp<<endl;
 return tmp;
}
int i;
int main(void)
{

int bit;
cout<<" enter the bit position ";
 cin >> bit;
 i|=pow(2,bit);
 cout << i;
 return 0;
}
