#ifndef __CACHE__H
#define __CACHE__H
#include"global.h"
template<typename T>
class Node
{
	public:
	Node(T *data):m_ptr(data),left(NULL),right(NULL){}
	T *m_ptr;
	Node *left,*right;
};

template<typename T>
class Cache
{
	 public:
	 Cache():m_root(NULL){}
	 void readAll(FILE *fp);	 
	 void insert(T *d);
	 void remove(T *d);
	 T  *search(T *);
	 private:
	 Node<T> *m_root;
};

template<typename T>
void Cache<T>::readAll(FILE *fp)
{
	if(!fp) return;
	fseek(fp,0,SEEK_SET);
	Contact *c = new Contact();
	char name[25],mob[25];	
	while(feof(fp)==0)
	{
           fscanf(fp,"%s%s",name,mob);           
           c = new Contact(name,mob);
           insert(c);
    }
}


template<typename T>
void Cache<T>::insert(T *d)
{
    if(m_root==NULL)
    {
		m_root =  new Node<Contact>(d);          
    }
	else
	{
	    int key = atoi(d->mobile());
		int tKey;
		Node *tra= m_root;
		while(tra)
		{
			tKey= atoi(tra->data->mobile());
			if(key >tKey)
			{
				tra->right = d;
			}
			
		}
		 
	}

}

template<typename T>
void Cache<T>::remove(T *d)
{

}

template<typename T>
T *Cache<T>::search(T *d)
{

}
#endif //CACHE
