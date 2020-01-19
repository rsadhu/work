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



void testSorting()
{
    Sorter<int> sort =  {6, 0, 1, 9, 2, 5, 3, 7, -1, 19};
    sort.exec(Type::INSERTION);
    sort.display();
}


// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//



Node<int> * rearrangeLastN(Node<int> * l, int n) {

    if(l  && n > 0) {
    Node<int> *tmp =  l,*tmp1 = nullptr;
     int  i = 1;

        while ( l->next )
        {
            if(i == n)
            {
                tmp1 = l;
            }
            l =  l->next;
            i++;
        }


        if(!tmp1 )
            return tmp;

        i = 1;

        while( i < n  )
        {

            l->next = tmp;
            l = l->next;

            tmp = tmp->next;
            i++;
        }


       l->next = nullptr;

        return tmp1;
    }
    return l;
}

std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
    std::vector<std::vector<int>> myMat(matrix.size(), std::vector<int> (matrix.at(0).size(), 0));
    for( size_t i = 0;i < matrix.size(); i++)
    {
        for(size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j])
            {
                myMat[i][j]+=1;

                if ( i - 1 >= 0 )
                    myMat[i - 1][j] += 1;

                if ( i + 1 < matrix.size() )
                    myMat[i + 1][j] += 1;

                if ( j - 1 >= 0 )
                    myMat[i][j - 1] += 1;

                if ( j + 1 < matrix[i].size() )
                    myMat[i][ j + 1] += 1;

                if ( (i - 1 >= 0) && j - 1 >= 0)
                    myMat[i - 1][j-1] += 1;

                if ( (i - 1 >= 0) && j + 1 < matrix[i].size())
                    myMat[i - 1][j + 1] += 1;

                if ( (i + 1 < matrix.size()) && j - 1 >= 0)
                    myMat[i + 1][j-1] += 1;

                if ( (i + 1 < matrix.size()) && j + 1 < matrix[i].size())
                    myMat[i + 1][j+1] += 1;
                }
        }
    }
    return myMat;

}



int main(void)
{
    // testVector();
    // testLinkList();
    //testQueue();
    //testSearch();
    //testBits(1024);
    //testSorting();
    //1, 2, 3, 4, 5, 6, 7
    Node<int> *tra = nullptr;
    tra =  new Node<int>(1);
    tra->next = new Node<int>(2);
    tra->next->next = new Node<int>(3);
    tra->next->next->next = new Node<int>(4);
    tra->next->next->next->next = new Node<int>(5);
    tra->next->next->next->next->next = new Node<int>(6);
    tra->next->next->next->next->next->next = new Node<int>(7);

   // auto t = rearrangeLastN(tra, 1);

    std::vector<std::vector<bool>> matrix
    {
        {true, false, false},
        {false, true, false },
        {false, false, false}
    };

    auto res = minesweeper( matrix);

    return 0;
}
