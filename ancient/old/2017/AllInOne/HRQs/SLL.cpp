#include "stdafx.h"
#include "SLL.h"

using namespace rs;

//[(*[0 - 9] * [a - b] * [A - B] * [0 - 9] * *)]
SLL::SLL()
{
	
}

SLL::~SLL()
{

}

void SLL::add(int d)
{
	if (!mRoot)
		mRoot = new Node(d);
	else
	{
		Node *tra = mRoot;
		for (; tra->next; tra = tra->next);
		tra->next = new Node(d);
	}
}

void SLL::remove(Node *prev,Node *cur, int key)
{
	if (cur)
	{
		if (cur->data == key)
		{
			Node *tmp = cur;			
			if (cur->next){
				prev->next = cur->next;
				cur = cur->next;				
			}
			else
			{
				prev->next = cur = nullptr;
			}		
			delete tmp;		
		}
		
		if (prev && cur)
			remove(prev->next, cur->next, key);
		else
			remove(prev, cur, key);		
	}
}

void SLL::removeItem(int k)
{
	Node *tr = mRoot;
	for (;tr; tr = tr->next)
	{
		if (tr->data == k)
		{
			Node *tmp = tr;
			tr = tr->next;
			delete tmp;
		}
		else
		{
			if (tr->next){
				remove(tr, tr->next, k);
				break;
			}
		}
	}	
	mRoot = tr;
}

void SLL::display()
{
	for (Node *tra = mRoot; tra; tra = tra->next)
		std::cout << tra->data << "  ";
}