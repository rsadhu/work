#include <vector>
#include <stack>
#include <map>
#include <memory>

#include "MyVector.h"
#include "linklist.h"
#include "queue.h"
#include "searchAlgos.h"
#include "bitwise.h"
#include "sort.h"

void testVector()
{
    MyVector<int> vec = { 1, 2, 3 , 4};

    //TODO: Implement Iterator

    for(int i = 1; i <= 6; i++)
    {
        vec.push(4+i);
    }

    vec.prepend(0);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    vec.insert(9, 100);

    std::cout<<"\n";

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    std::cout<<"\n  vector popping out:: "<<vec.size()<<"\n";


    for(int i=0;i<vec.size();i++)
    {
        std::cout<<vec.pop()<<" ";
    }


    std::cout<<"\n size is "<< vec.size();
}

void testLinkList()
{
    LinkList<int> list;
    int j = 0;

    for(int i=1; i <= 10; i++)
    {
        j = i;
        list.push_back(j*2);
    }


    list.reverse();


    list.display();
    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
}

void testQueue()
{
    MyQueue::QueueIntf<int> * q =   new MyQueue::SQueue<int>();

    for(int i=0;i<10;i++)
        q->enQueue(i);


    for(int i=0;i<10;i++)
        std::cout<<q->deQueue()<<" ";

    delete q;


    std::unique_ptr<MyQueue::QueueIntf<int>> bb;

    bb =  std::make_unique<MyQueue::DQueue<int>>();

    for(int i=0;i<10;i++)
       bb->enQueue(i);


    for(int i=0;i<10;i++)
        std::cout<<bb->deQueue()<<" ";
}



template<typename T>
class ListNode
{
public:
    ListNode(T rhs):value(rhs), next(nullptr){}
    int value = 0;
    ListNode<T> *next =  nullptr;

};


ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {

    std::stack<int> s1, s2, s3;
    int carry = 0;
    std::string fin="";
    while(a)
    {
        s1.push(a->value);
        a =  a->next;
    }

    while(b)
    {
        s2.push(b->value);
        b =  b->next;
    }


    while(!s1.empty() && !s2.empty())
    {

        auto res = s1.top() + s2.top() + carry;
        carry = 0;
        std::string str =  std::to_string(res);
        if (str.length() == 5){
            carry = str[0] - '0';
            str =  str.substr( 1, str.length());
        }
        else
            if (str.length() == 6)
            {
                carry = int(str[0] -  '0') + int(str[1] - '0');
                str =  str.substr( 1, str.length()-2);
            }
        fin.insert(0, str);
        s1.pop();
        s2.pop();
    }


    while(!s1.empty())
    {
        fin.insert(0, std::to_string(s1.top()));
        s1.pop();
    }

    while(!s2.empty())
    {
        fin.insert(0, std::to_string(s2.top()));
        s2.pop();
    }

    ListNode<int> *head = nullptr, *cur=nullptr;

    do
    {
        std::string str="";

        str = fin.substr(0, 4);
        fin =  fin.substr(4,fin.length());

        if(!head)
        {
            cur =  new ListNode<int>(std::stoi(str));
            head = cur;
        }
        else
        {
            cur->next =  new ListNode<int> (std::stoi(str));
            cur = cur->next;
        }
    }while(fin.length() >= 4);

    return head;

}


void sortColors(std::vector<int>& nums)
{
    int arr[3]= {0};
    for(const auto &it: nums)
    {
        arr[it]+=1;
    }

    for(int i = 0, j=0, k =0;i<3;i++)
    {
        j = 0;
        while((arr[i]-j++)>0)
        {
            nums[k++] = i;
        }
    }
}


void competitiveQuestions()
{
    std::vector<int> r =  {2,0,2,1,1,0};
    sortColors(r);

    for(auto o: r)
        std::cout<< o <<" ";

}


std::vector<int> digitalSumSort(std::vector<int> a)
{
    std::multimap<int, int> lookup;
    for(auto it: a)
    {
        int sum = 0, b = it;
        while(it)
        {
            sum += it%10;
            it/=10;
        }
        lookup.insert(std::pair<int,int>(sum,b));
    }

    std::vector<int> res;
    for(auto it: lookup)
    {
        res.push_back(it.second);
    }

    return res;
}

void addIntsFromLists()
{
    std::vector<int> n1 =  { 9, 0, 0, 1};
    std::vector<int> n2 =  {1};
}

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes)
{
    std::vector<std::vector<std::string>> res;
    std::multimap<std::string , std::string> lookup;

    for(auto it: dishes)
    {
        std::string item="";
        for(auto subit : it)
        {
            if(item=="")
                item =  subit;
            else
            {
                lookup.insert(std::pair<std::string, std::string> (subit, item));
            }
        }
    }
    return res;
}

void testSearch()
{
    //Searching<int> finder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Searching<int> finder = {7, 2, 8, 6, 5, 3, 10, 1, 9, 4};

    for(int i = 1;i<=10;i++)
    std::cout<<"\n"<< i << "    ===== "<< finder.findItem(i, SEARCH_TYPE::BINARY_TREE_SEARCH_RECU);
  //  std::cout<<"\n item found ::"<<finder.findRecItem(1);


//    std::cout<<"\n item  4 is :: "<< finder.findItem(4, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);
//    std::cout<<"\n item  1 is :: "<< finder.findItem(1, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);
//    std::cout<<"\n item  10 is :: "<< finder.findItem(10, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);
//    std::cout<<"\n item  5 is :: "<< finder.findItem(5, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);
//    std::cout<<"\n item  6 is :: "<< finder.findItem(6, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);
//    std::cout<<"\n item  100 is :: "<< finder.findItem(109, SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU);



//    std::cout<<"\n item  4 is :: "<< finder.findIterItem(4);
//    std::cout<<"\n item  1 is :: "<< finder.findIterItem(1);
//    std::cout<<"\n item  10 is :: "<< finder.findIterItem(10);
//    std::cout<<"\n item  5 is :: "<< finder.findIterItem(5);
//    std::cout<<"\n item  6 is :: "<< finder.findIterItem(6);
//    std::cout<<"\n item  100 is :: "<< finder.findIterItem(109)<<"\n\n";
}

void testBits(int a)
{
    std::cout<<" number of bits for "<< a <<"set are " << countBits(a) << "\n";
}

void testSorting()
{
    Sorter<int> sort =  {6, 0, 1, 9, 2, 5, 3, 7, -1, 19};
    sort.exec(Type::BUBBLESORT);
    sort.display();
}


int main(void)
{
    // testVector();
    // testLinkList();
    //testQueue();
    testSearch();
    testBits(1024);
    testSorting();
    return 0;
}
