// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"BST.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BST t;
	t.add(10);
	t.add(5);
	t.add(15);
	t.add(8);
	t.add(1);
	t.add(12);
	t.add(20);
	t.display(TYPE::INORDER_R);
	return 0;
}

