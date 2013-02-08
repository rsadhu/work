#include<iostream>
using namespace std;

//class BST;

template < class U > 
class Node
{
private:
  Node * left, *right;
  U *data;
//  friend class BST;
};

template < class U > 
class BST
{
public:
  BST & operator< (U  data);
  void display ();
private:
  Node<U> * m_root;
};



template < typename U > 
void BST<U>::display ()
{

}

template < typename U > 
BST & BST<U>::operator <(U  data)
{
  return *this;
}

int
main (void)
{
  BST < int >  bst;
  bst < 9 < 5 < 12 < 3 < 11 < 6 << 13;
  bst.display ();
  return 0;
}
