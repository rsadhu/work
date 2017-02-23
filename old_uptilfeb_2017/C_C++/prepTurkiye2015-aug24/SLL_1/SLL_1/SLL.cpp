
#include "stdafx.h"
#include "SLL.h"


SLL& SLL::operator<(int d)
{
	if(!mHead)
		mHead =  new Node (d);
	else
		//mHead  = 
	//Node *tmp=	addRec1(mHead,d);
		//addRec(&mHead,d);
		addIter(mHead,d);
	return *this;
}

Node * SLL::addRec1(Node *head,int d)
{
	if(!head)
		return new Node(d);
	else
		head->next  = addRec1(head->next,d);
		return head;	
}


void SLL::addRec(Node **head, int d)
{
	if(!*head)
	{
		*head = new Node(d);
	}
	else
	{
		addRec(&(*head)->next,d);
	}
}


void SLL::addIter(Node *head,int  d)
{
	Node *tra;
	for(tra= head;tra->next!=NULL;tra= tra->next);
		tra->next  = new Node (d);
}


void SLL::display(void)
{
	cout<<endl;
	Node *tra=  mHead;
	while(tra)
	{
		cout<<tra->data<< " ";
		tra =  tra->next;
	}
}

void SLL::revDisplay()
{
	cout<<endl;	
	if(mHead && mHead->next){
		display();
		cout<<endl;
		reverseIter(&mHead);
	}
}


void SLL::rDisplay(Node *head)
{
	if(!head)
		return ;
	else
		rDisplay(head->next);

	cout<<head->data<<" ";
}

void SLL::reverseIter(Node **head)
{
	Node *temp =  NULL;
	Node *cur=*head,*tra=cur->next;
	while(tra)
	{		
		cur->next = temp;
		temp =  cur;
		cur=tra;
		tra =tra->next;
	}
	
	cur->next=temp;
	*head  = cur;
}


void SLL::reverseRec1(Node **cur,Node **head)
{
	if(!(*cur)->next){
		*head =  *cur;
		return;
	}
	else 
		reverseRec1(&(*cur)->next,head);
		(*cur)->next = *cur;	
}


void SLL::reverseRec(Node **cur,Node **next,Node **head)
{
	if(!*next){
		*head =  *cur;
		return;
	}
	reverseRec(&((*cur)->next),&((*next)->next),head);
	(*next)->next = *cur;
}


