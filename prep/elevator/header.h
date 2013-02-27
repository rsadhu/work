#ifndef __HEADER__
#define __HEADER__
#include<iostream>
#include<queue>
using namespace std;

class Elevator
{
 public:
 Elevator():curPosition(0){}
 Elevator & operator<(int d);
 private:
 queue<int> up,down;
 int curPosition; 
};
#endif // __HEADER__
