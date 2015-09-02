#pragma once
#include<iostream>
using namespace std;

class Node 
{
public:
	Node(int d)
	{
		data = d;
		next = 0;
	}
	int  data;
	Node *next;
};


class SLL
{
public:
	SLL(void){ mHead=0;}
	~SLL(void){}
	SLL &operator<(int d);
	void display();
	void revDisplay();
protected:
	static void addRec(Node **,int d);
	static Node * addRec1(Node *,int d);
	static void addIter(Node *,int d);
	static void rDisplay(Node *head);
	static void reverseIter(Node  **head);
	static void reverseRec(Node **cur,Node **next,Node **head);
	static void reverseRec1(Node **cur,Node **head);
protected:
	Node *mHead;
};


