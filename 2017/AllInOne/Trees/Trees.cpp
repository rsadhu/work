// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"BST.h"
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	/*BST t,t1;
	t.add(10);
	t.add(5);
	t.add(15);
	t.add(8);
	t.add(1);
	t.add(12);
	t.add(20);*/
	
	//t1 < 10 < 5 < 15 < 8 < 1 < 12 < 20 < 40  < 6 < 9;
	//t.display(TYPE::INORDER_R);	
	//t1.display(TYPE::INORDER_R);
	/*t.display(TYPE::PREORDER_R);
	t.display(TYPE::POSTORDER_R);

	t.display(TYPE::INORDER_I);
	t.display(TYPE::PREORDER_I);
	t.display(TYPE::SPIRAL);*/
	//t.display(TYPE::LEVELORDER);
	//t.display(TYPE::REVERSE_LEVELORDER);

//	std::cout << "min : " << t.min();
//	std::cout << "max: " << t.max();
//
////	t.display(TYPE::MIRROR);
//	//t.display(TYPE::INORDER_R);
//
//
//
///*
//	BinaryTree bt;
//	bt.addNode(10);
//	bt.addNode(5);
//	bt.addNode(15);
//	bt.addNode(8);
//	bt.addNode(1);
//	bt.addNode(12);
//	bt.addNode(20);
//	bt.display();*/
//
//	std::cout <<"\nmin : "<<t.min();
//	std::cout << "\nmax: " << t.max();
//
//	/*std::cout << "\nheight :: " << t.height();
//	std::cout << "\ndepth :: 8 " << t.depth(8);
//	std::cout << "\ndepth :: 5 " << t.depth(5);
//	std::cout << "\ndepth :: 10 " << t.depth(10);
//	std::cout << "\ndepth :: 20 " << t.depth(20);
//	std::cout << "\ndepth :: 0" << t.depth(0);*/
//
//	t.printAllPaths();
//	t.printLargestSumPath();
//	t.printSmallestSumPath();
//	std::cout<<"coun:: "<<t.count();
//	std::cout<<"isBST:: "<<t.isBST();
//	
	/*std::cout << t.count() << "   " << t1.count();
	bool ret = t.areTreesSame(t.root(), t1.root());*/

	BST t;
	t.add(20);
	t.add(6);
	t.add(30);
	t.add(2);
	t.add(10);
	t.add(1);
	t.add(3);
	t.add(8);
	t.add(12);

	t.display(TYPE::INORDER_I);
	t.deleteItem(6);
	t.display(TYPE::INORDER_I);
	return 0;
}

 