#include "MyVector.h"
#include "linklist.h"
#include "queue.h"
#include <vector>

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
        //     //   list.push_back(j*2);
        //        list.push_back(j*3);
        //        list.push_back(j*5);
    }

    //std::cout<<"\nsize of list >>> "<< list.size()<<"\n";


    //    for(int i = 0;i<5;i++)
    //        std::cout<<list.pop_front();


    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";

    //    list.display();

    //    list.remove_value(9);
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
    //    list.display();
    //    list.remove_value(6);
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
    //    list.display();

    list.reverse();

    //    for(int i = 1; i <= 10;i++){
    //        list.display();
    //        std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
    //        list.removeAllSentItems(i*3);
    //        list.removeAllSentItems(i*2);
    //        list.removeAllSentItems(i*5);

    //    }

    list.display();
    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
    //    list.removeAllSentItems(10);
    //    list.display();
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
    //    list.removeAllSentItems(30);
    //    list.display();
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";

    //    list.removeAllSentItems(12);
    //    list.display();
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";

    //    list.removeAllSentItems(20);
    //    list.display();
    //    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
}

void testQueue()
{
    MyQueue::Queue<bool> q;
    std::string e("is empty "), ne("not empty");
    std::cout<< (q.empty() ? e: ne);
    q.enQueue(false);
    q.enQueue(false);
    q.enQueue(false);
    q.enQueue(false);
    q.enQueue(false);
    q.enQueue(false);

    std::cout<< (q.empty() ? e: ne);

    for(auto i = 1; i<=10;i++)
        std::cout<<q.deQueue();
    std::cout<< (q.empty() ? e: ne);
}

#include<stack>

template<typename T>
class ListNode
{
public:
    ListNode(T rhs):value(rhs), next(nullptr){}
    int value;
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

    ListNode<int> *head = nullptr, *cur;

    int cnt  = 0;

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
    for(auto it: nums)
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

#include<map>

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

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
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


    std::vector<std::vector<std::string>> ret;
    //std::map<std::string, std::string> final;

    auto i = lookup.equal_range("Cheese");


    std::cout<<" ggggggggggggggggggggggg ";
 //   std::cout<<" i:: >> " << i;

//    for(auto it: lookup)
//    {
//        for(auto subIt lookup)
//        {
//            int len = lookup.count(subIt.first);
//            final[subIt.first] = subIt.second;
//            while(len--)
//            {
//                subIt++;
//            }
//        }
//    }

//    for(auto it: lookup)
//    {
//       std::vector<std::string> item;
//       item.push_back(it.first);
//       if (lookup.count(it.first) >= 2 ) {

//       for(auto value: lookup.equal_range(it.first))
//       {
//        item.push_back(value);
//       }

//        ret.push_back(item);
//       }
//    }
}


int main(void)
{
    //  testVector();
    testLinkList();
    //std::vector<int> a  = {13, 20, 7, 4};

    //a = digitalSumSort(a);

    //testQueue();

    /*a: [123, 4, 5]
b: [100, 100, 100]*/

//        ListNode<int> *q, *r;
//        ListNode<int> *tmp =  new ListNode<int> (123);
//        q = tmp;
//        tmp->next =  new ListNode<int> (4);
//        tmp->next->next = new ListNode<int>(5);


//        tmp =  new ListNode<int> (100);
//        r = tmp;
//        tmp->next =  new ListNode<int> (100);
//        tmp->next->next = new ListNode<int>(100);

//        addTwoHugeNumbers(q, r);

    std::vector<std::vector<std::string>> input ={
                    {"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
                    {"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
                    {"Quesadilla", "Chicken", "Cheese", "Sauce"},
                    {"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}
    };

///    auto ret =  groupingDishes(input);

    //    int A[] = {1,2,3,4,5};
    //    int N = 5;
    //    int Total = 1 << N;
    //    for ( int i = 0; i < Total; i++ ) {
    //    for ( int j = 0; j < N; j++) {
    //    if ( (i >> j) & 1 )
    //    std::cout <<" "<< A[j];
    //    }
    //    std::cout << std::endl;
    //    }
    return 0;
}
