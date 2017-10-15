// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"BST.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BST t;
	/*t.add(10);
	t.add(5);
	t.add(15);
	t.add(8);
	t.add(1);
	t.add(12);
	t.add(20);*/
	
	t < 10<5 < 15 < 8 < 1 < 12 < 20;
	t.display(TYPE::INORDER_R);	
	t.display(TYPE::PREORDER_R);
	t.display(TYPE::POSTORDER_R);

	t.display(TYPE::INORDER_I);
	t.display(TYPE::PREORDER_I);
	t.display(TYPE::SPIRAL);
	t.display(TYPE::LEVELORDER);
	return 0;
}

 