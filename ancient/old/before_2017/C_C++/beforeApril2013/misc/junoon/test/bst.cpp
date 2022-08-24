#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define SIZE 100

class ErrorObj
{
public:
  explicit ErrorObj(char *str, int errorNum)
  {
    m_message = strdup(str);
    m_error = errorNum;
  }
  inline char *errorMessage()
  {
    return m_message;
  }
  inline int errorNumber()
  {
    return m_error;
  }

private:
  char *m_message;
  int m_error;
};

class Node
{
public:
  explicit Node(int rhs) : left(NULL), right(NULL), data(rhs)
  {
  }
  Node *left, *right;
  int data;
};

class BST
{
  BST(const BST &);
  BST &operator=(const BST &);
  Node *m_root;

public:
  BST() : m_root(NULL)
  {
  }
  BST &operator<(int rhs);
  void display();
  int nodes();
  void bfs();
  void spiral();
  bool sumPath(int);
  void mirrorImage();

private:
  void calculateSum(Node *, int &, queue<Node *> &);
  void insert(int rhs);
  Node *insertRec(Node *, int);
  void count(Node *, int &);
  void mirror(Node *node);
};

void BST::mirrorImage()
{
  mirror(m_root);
}

void BST::mirror(Node *ptr)
{
  if (ptr == NULL)
    return;

  Node *tmp = ptr->left;
  ptr->left = ptr->right;
  ptr->right = tmp;

  mirror(ptr->left);
  mirror(ptr->right);
}

bool BST::sumPath(int s)
{
  queue<Node *> q;
  bool
      ret(false);
  calculateSum(m_root, s, q);
  if (!q.empty() && s == 0)
    ret = true;
  return ret;
}

void BST::calculateSum(Node *node, int &sum, queue<Node *> &q)
{
  if (node == NULL || sum == 0)
    return;
  q.push(node);
  sum -= node->data;
  calculateSum(node->left, sum, q);
  sum += node->data;
  q.pop();
  calculateSum(node->right, sum, q);
}

void BST::spiral()
{
  queue<Node *> que;
  Node *tmp = m_root;
  int cnt = 0;
  que.push(tmp);

  while (!que.empty())
  {
    tmp = que.front();
    cout << " " << tmp->data;
    cnt++;
    if (cnt % 2 != 0)
    {
      if (tmp->right)
        que.push(tmp->right);
      if (tmp->left)
        que.push(tmp->left);
    }
    else
    {
      if (tmp->left)
        que.push(tmp->left);
      if (tmp->right)
        que.push(tmp->right);
    }
    que.pop();
  }
}

void BST::bfs()
{
  queue<Node *> que;
  Node *tra = m_root;
  que.push(tra);
  Node *tmp;
  while (!que.empty())
  {
    tmp = que.front();
    que.pop();
    cout << "  " << tmp->data;
    if (tmp->left)
      que.push(tmp->left);
    if (tmp->right)
      que.push(tmp->right);
  }
}

int BST::nodes(void)
{
  int n = 0;
  count(m_root, n);
  return n;
}

void BST::count(Node *ptr, int &n)
{
  if (ptr == NULL)
    return;
  n++;
  count(ptr->left, n);
  count(ptr->right, n);
}

BST &BST::operator<(int rhs)
{
  // insert(rhs);
  Node *
      tmp = m_root;
  m_root = insertRec(tmp, rhs);
  return *this;
}

Node *
BST::insertRec(Node *root, int rhs)
{
  if (!root)
  {
    root = new Node(rhs);
    return root;
  }

  if (rhs > root->data)
  {
    cout << rhs << " goes right " << root->data << "\n";
    root->right = insertRec(root->right, rhs);
  }
  else if (rhs < root->data)
  {
    cout << rhs << " goes left " << root->data << "\n";
    root->left = insertRec(root->left, rhs);
  }
  return root;
}

void BST::insert(int rhs)
{
  Node *tra = m_root;
  Node *tmp = new Node(rhs);
  char ch;
  if (!m_root)
  {
    m_root = tmp;
  }
  else
  {
    while (tra)
    {
      if (rhs > tra->data)
      {
        ch = 'r';
        if (tra->right)
          tra = tra->right;
        else
          break;
      }
      else if (rhs < tra->data)
      {
        ch = 'l';
        if (tra->left)
          tra = tra->left;
        else
          break;
      }
      else
      {
        ch = 't';
        break; //                return *this;
      }
    }
    if (ch == 'r')
      tra->right = tmp;
    if (ch == 'l')
      tra->left = tmp;
  }
}

void inOrder(Node *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root)
{
  if (root == NULL)
    return;

  preOrder(root->left);
  preOrder(root->right);
  cout << root->data << " ";
}

void inOrderIter(Node *root)
{
  if (!root)
  {
    cout << "\n Tree is Empty \n";
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    if (root->left)
    {
      root = root->left;
      q.push(root);
    }
    else if (root->right)
    {
      root = root->right;
      q.push(root);
    }
    else
    {
      cout << "  " << root->data;
      root = q.front();
      q.pop();
    }
  }
}

void BST::display()
{
  Node *tmp = m_root;
  cout << "\n****** RECURSIVE METHODS**************\n";
  cout << "\n INORDER TRAVERSAL \n";
  inOrder(tmp);
  cout << "\nPREORDER TRAVERSAL \n";
  preOrder(tmp);
  cout << "\n POSTORDER TRAVERSAL\n";
  postOrder(tmp);
  cout << "\n****** ITERATIVE METHODS**************\n";
  inOrderIter(tmp);
}

int main(void)
{
  BST tree;
  cout << " element are :: \n 11 8 9 14 13 15 4 \n";
  // tree < 11 < 8 < 9 < 14 < 13 < 15 < 4 < 16 < 3 < 1 < 12 < 6;
  tree < 11 < 8 < 9 < 14 < 13 < 15 < 4;
  tree.display();
  //  tree.bfs ();
  cout << " \nthe number of nodes ::" << tree.nodes() << endl;
  //  tree.spiral ();
  //  cout<<" \npath is ...."<<tree.sumPath(28)<<"\n";
  tree.mirrorImage();
  tree.display();
  return 0;
}
