#include <iostream>
#include"list.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    List<int> l;
    for(int i = 0;i<10;i++)
    {
        l.push_back(i);
    }


    std::cout<< l.length()<<"\n";
    std::cout<<l.front()<<"  "<<l.back()<<"\n";

    l.pop_back();

    std::cout<<l.front()<<"  "<<l.back()<<"\n";

    l.pop_front();

    std::cout<<l.front()<<"  "<<l.back()<<"\n";

    l.pop_front();
    l.pop_back();

    std::cout<<l.front()<<"  "<<l.back()<<"\n";
    std::cout<< l.length()<<"\n";

    return 0;
}
