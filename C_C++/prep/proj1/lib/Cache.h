#ifndef __CACHE__H
#define __CACHE__H
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
#endif //CACHE