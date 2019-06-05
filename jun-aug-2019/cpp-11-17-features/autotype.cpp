#include<iostream>

using namespace std;
int x = 100;

auto getObject(){
 int & rv =  x;
 return rv;
}


int main(void)
{
 auto x = 10;
 return 0;
}
