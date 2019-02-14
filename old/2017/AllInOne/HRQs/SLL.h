#pragma once
#include<iostream>
namespace rs
{
	class Node
	{
	public:
		Node(int d) :data(d){}
		int data;
		Node *next = nullptr;
	};

	class SLL
	{
	public:
		SLL();
		~SLL();
		void add(int d);
		void removeItem(int k);
		void display();
		static void remove(Node *,Node *, int);
	private:
		Node *mRoot = nullptr;
	};
};

