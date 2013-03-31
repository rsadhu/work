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
	 void insert(Node<T> *d);
	 void remove(Node<T> *d);
	 Node<T> *search(Node<T> *);
	 private:
	 Node<T> *m_root;
};


template<typename T>
void Cache<T>::insert(Node<T> *d)
{
    if(m_root==NULL)
    {
        //m_root = new Node (
    }

}

template<typename T>
void Cache<T>::remove(Node<T> *d)
{

}

template<typename T>
Node<T> *Cache<T>::search(Node<T> *d)
{

}
#endif //CACHE
