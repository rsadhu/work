#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
  Node(int d) : left(NULL), right(NULL)
  {
    data = d;
  }
  int data;
  Node *left, *right;
};

typedef enum
{
  INORDER,
  POSTORDER,
  PREORDER,
  INORDERREC,
  POSTORDERREC,
  PREORDERREC,
  BFS,
  DFS,
  SPIRAL
} TYPE;

class BST
{
public:
  BST() : m_root(NULL)
  {
  }
  BST &operator<(int);
  void BuildTree();
  void display(TYPE t);

protected:
  void inOrder(Node *);
  void postOrder(Node *);
  void preOrder(Node *);
  void inOrderRec(Node *);
  void postOrderRec(Node *);
  void preOrderRec(Node *);
  void bfs(Node *);
  void spiralLevelD(Node *);

private:
  Node *m_root;
};

BST &BST::operator<(int d)
{
  if (!m_root)
  {
    m_root = new Node(d);
  }
  else
  {
    Node *
        tra = m_root;
    while (tra)
    {
      if (d > tra->data)
      {
        if (NULL == tra->right)
        {
          tra->right = new Node(d);
          break;
        }
        else
          tra = tra->right;
      }
      else if (d < tra->data)
      {
        if (NULL == tra->left)
        {
          tra->left = new Node(d);
          break;
        }
        else
          tra = tra->left;
      }
    }
  }
  return *this;
}

void BST::inOrderRec(Node *root)
{
  if (!root)
    return;
  inOrderRec(root->left);
  cout << " " << root->data << " ";
  inOrderRec(root->right);
}

void BST::postOrderRec(Node *root)
{
  if (!root)
    return;
  postOrderRec(root->left);
  postOrderRec(root->right);
  cout << " " << root->data << " ";
}

void BST::preOrderRec(Node *root)
{
  if (!root)
    return;
  cout << " " << root->data << " ";
  preOrderRec(root->left);
  preOrderRec(root->right);
}

void BST::inOrder(Node *root)
{

  stack<Node *> s;
  Node *tra = root;
  while (!s.empty() || tra)
  {
    if (tra)
    {
      s.push(tra);
      tra = tra->left;
    }
    else
    {
      tra = s.top();
      s.pop();
      cout << tra->data << "  ";
      tra = tra->right;
    }
  }
}

void BST::postOrder(Node *root)
{
}

void BST::preOrder(Node *root)
{
}

void BST::display(TYPE t)
{
  switch (t)
  {
  case INORDERREC:
    cout << "INORDER::";
    inOrderRec(m_root);
    break;
  case PREORDERREC:
    cout << "PREORDER::";
    preOrderRec(m_root);
    break;
  case POSTORDERREC:
    cout << "POSTORDER::";
    postOrderRec(m_root);
    break;
  case INORDER:
    cout << "INORDERREC::";
    inOrder(m_root);
    break;
  case PREORDER:
    cout << "INORDERREC::";
    preOrder(m_root);
    break;

  case POSTORDER:
    cout << "INORDERREC::";
    postOrder(m_root);
    break;
  case BFS:
    cout << "\n bfs\n";
    bfs(m_root);
    break;
  case SPIRAL:
    cout << "\n SPIRAL ...\n";
    spiralLevelD(m_root);
    break;
  default:
    cout << "\n bfs .....\n";
    break;
  }
  cout << "\n";
}

void BST::bfs(Node *root)
{
  cout << "\n .... bfs ... statt  \n";
  queue<Node *> q;
  Node *tra = root;
  q.push(tra);
  while (!q.empty())
  {
    tra = q.front();
    cout << tra->data << "  ";
    q.pop();
    if (tra->left)
      q.push(tra->left);
    if (tra->right)
      q.push(tra->right);
  }

  cout << " \n.... bfs ... end  \n";
}

void BST::spiralLevelD(Node *root)
{
  cout << "\n BST::spiral\n";
  Node *tra = root;
  int dir = 1;
  queue<Node *> q;
  q.push(tra);
  while (!q.empty())
  {
  }
}

int main(void)
{
  BST bt;
  bt < 20 < 12 < 15 < 25 < 22 < 10 < 30;
  // bt.display (INORDERREC);
  // bt.display (PREORDERREC);
  // bt.display (POSTORDERREC);
  // bt.display (INORDER);
  bt.display(BFS);
  return 0;
}
