#include "stdafx.h"
#include "ProxyClass.h"
#include<stdio.h>

void RealClass::display()
{
	cout << "RealClass::\n";
}





void ProxyClass::display()
{
	//mInt!=NULL ? mInt->display : (cout << " Interface not Initialized\n");
	mInt->display();
}
