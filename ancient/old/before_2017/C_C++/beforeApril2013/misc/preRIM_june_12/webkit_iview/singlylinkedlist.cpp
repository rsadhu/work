#include <iostream>
using namespace std;

class Node
{
public:
  Node(int d) : next(NULL), data(d)
  {
    cout << " NODE :: Node \n";
  }
  ~Node()
  {
    cout << " Node ::~Node\n";
    next = NULL;
    data = 0;
  }
  Node *next;
  int data;
};

class SLL
{
public:
  SLL() : head(NULL), size(0)
  {
    cout << " SLL::SLL\n";
  }
  SLL &operator<(int rhs);
  void display();
  void insertAt(int d, int pos);
  void deleteAt(int pos);
  inline int length()
  {
    return size;
  }

private:
  Node *head;
  int size;
};

SLL &SLL::operator<(int rhs)
{
  if (!head)
  {
    head = new Node(rhs);
    size++;
  }
  else
  {
    Node *
        tra = head;
    for (; tra->next != NULL; tra = tra->next)
      ;
    tra->next = new Node(rhs);
    size++;
  }
  return *this;
}

void SLL::display(void)
{
  Node *tra = head;
  while (tra)
  {
    cout << tra->data << " ";
    tra = tra->next;
  }
  cout << endl;
}

void SLL::insertAt(int d, int pos)
{
  if (pos == 1)
  {
    Node *n = new Node(d);
    n->next = head;
    head = n;
    size++; // incrementin size of the linkedlist by 1
  }
  else
  {
    Node *n = new Node(d);
    int cnt = 2;
    for (Node *tra = head; tra != NULL; tra = tra->next, cnt++)
    {
      if (pos == cnt)
      {
        size++; // incrementin size of the linkedlist by 1
        n->next = tra->next;
        tra->next = n;
        break;
      }
    }
  }
}

void SLL::deleteAt(int pos)
{
  if (1 == pos)
  {
    size--; // decrementing size of the linkedlist by 1
    Node *tmp = head;
    head = head->next;
    delete tmp;
  }
  else
  {
    int cnt = 2;
    for (Node *tra = head, *cur = head; cur->next != NULL;
         tra = tra->next, cnt++)
    {
      cur = cur->next;
      if (cnt == pos)
      {
        Node *tmp = cur;
        tra->next = cur->next;
        delete tmp;
        size--; // decrementing size of the linkedlist by 1
        break;
      }
    }
  }
}

int main(void)
{
  SLL *sll = new SLL;
  *sll < 1 < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9;
  cout << " the size of linkedlist .. " << sll->length() << endl;
  sll->display();
  sll->insertAt(99, 1);
  cout << " the size of linkedlist .. " << sll->length() << endl;
  sll->display();
  sll->insertAt(100, 10);
  cout << " the size of linkedlist .. " << sll->length() << endl;
  sll->display();
  sll->insertAt(1001, 12);
  cout << " the size of linkedlist .. " << sll->length() << endl;
  sll->display();
  sll->deleteAt(1);
  cout << " the size of linkedlist .. " << sll->length() << endl;
  sll->display();
  sll->deleteAt(1);
  cout << " the size of linkedlist .. " << sll->length();
  sll->deleteAt(sll->length());
  sll->display();
  return 0;
}
