#include "stdafx.h"
#include "singleton.h"
#include<iostream>
using namespace std;

singleton singleton:: mObj;

singleton * singleton::getInstance()
{
	return &mObj;
}


void singleton::display()
{
	cout << "singleton:: display\n";
}