#include<iostream>
class Node
{
 public:
 int data;
 Node *next = nullptr;

 Node(int d):data(d)
 {
 
 }
};

Node * createStack(Node *head, int item)
{
 Node *ele  = new Node(item);
 ele->next =  head;
 return ele;
}


int main(void)
{
 Node *head =  new Node(1);
 for(int i = 2;i<10;i++)
  head =  createStack(head, i);

auto tmp =  head;
 while(tmp)
{
 std::cout<<tmp->data<< "  ";
 tmp= tmp->next;
}

 std::cout<<"\n";
 return 0;
}
