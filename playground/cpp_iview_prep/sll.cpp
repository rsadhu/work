#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Node
{
  Node(int d): data(d), next(nullptr)
  {
   // next =  nullptr;
  }
  Node *next ;
  int data;
};


Node *createLinkList(const std::vector<int> &l)
{
  Node *head = nullptr, *tra  = nullptr;
  
  for(auto it : l)
  {
    if (tra == nullptr)
    {
      tra =  new Node(it);
      head =  tra;
    }
    else
    {
      tra->next = new Node(it);
      tra =  tra->next;

    }
  }
  
  return head;
}



void display(Node *tra)
{
  while(tra)
  {
    std::cout<<tra->data <<" ";
    tra =  tra->next;
  }
}



Node * reverse(Node *head)
{
    Node *prev = nullptr, *cur = head;

        while (cur)
        {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
}


int main(int argc, char *argv[])
{
    std::vector<int> l = {1,2,3,4,5};
    Node *head = createLinkList(l);
  
    display(head);
    
    //reverse(head);
    
    display(head);
 
    return 0;
}