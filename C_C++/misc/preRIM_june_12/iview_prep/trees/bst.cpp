#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node( T *data);
	Node *left ;
	Node *right;
	T *m_data;
};


template <typename T>
Node<T>::Node(T *data):left(NULL),right(NULL),m_data(data)
{
cout<<"Node::Node(data *)\n";
}

template<typename T>
class BST
{
public:
	ST ():root(NULL){ cout<<"BST::BST\n";}
  BST& operator <<(T data );
private :
Node<T> *root;
};


BST<T> &BST<T>::operator <<(T &data )
{
  Node *tmp = new Node(&data);
  Node * tra = root;
  if(!tra)
  {
	tra = tmp;	
  }
  else
{
	while(tra)
{
	if(tra->m_data > tmp->data)
	{
		
	}
	else
	{
	}
}
}
}


int main(void)
{
 BST<int> bt;
 return 0;
}
