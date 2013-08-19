#include<iostream>
using namespace std;

typedef struct _Node
{
     _Node(int d):data(d),next(0){}
     int data;
     struct _Node *next;

}Node;

class sll
{
    public:
    sll():head(0){}
    sll &operator<(int d);
    void display();
    void reverse();
    protected:
    void reversePriv(Node **,Node **);
    private:
    Node *head;
};

sll &sll::operator<(int d)
{
     if(!head)
          head =  new Node (d);
      else
      {
           Node *tra;
          for(tra= head;tra->next;tra=tra->next);
          tra->next = new Node(d);
      }
     return *this;
}


void sll::display()
{
    Node *tra= head;
    while(tra)
    {
         cout<<"\n data :: "<<tra->data;
         tra= tra->next;
    }
}

void sll::reverse()
{
    Node *tra= head,*n=head->next;
    cout<<"\n cur :: newt \n";
    this->reversePriv(&tra,&n);
    tra->next = NULL;
}


void sll::reversePriv(Node **tra,Node**tra_next)
{
    if(!*tra_next){
        head  = *tra;
        return;
    }
    reversePriv(&((*tra)->next),&((*tra_next)->next));
    cout<<"\n"<<*tra_next<<"  :: "<<*tra<<"data :: "<<(*tra)->next->data<<"\n";
    (*tra_next)->next =  *tra_next;
}



int main(void)
{
    sll l;
    l<1<2<3<4<5;
    l.display();
    l.reverse();
    l.display();
     return 0;
}
