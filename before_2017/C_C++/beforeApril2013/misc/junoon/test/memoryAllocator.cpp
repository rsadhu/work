#include<iostream>
#include<stdlib.h>
using namespace std;

class MemPool
{
public:
	MemPool(){ init();cout<<" Mempool::MemPool\n";}
	void *operator new (size_t bytes);
	void operator delete (void *p2obj);
	  void init(){ cout<<"MemPool:: "<<data<<endl;}
	int data;
        char *p;
};


void * MemPool::operator new (size_t bytes)
{
  cout<<" MemPool::new "<<bytes<<endl;
  return  malloc(bytes);
}


void  MemPool::operator delete(void *p2obj)
{
cout<<" MemPool::delete ";
 if(p2obj)
 free(p2obj);
}







int main(void)
{
 //MemPool *p= (MemPool *)new(sizeof(MemPool)) MemPool();
 MemPool *p= new MemPool();
 p->init();
 delete p;
}

