#include<iostream>
#include<map>
#include<functional>
#include<list>

using func =  std::function<void()>;


void foo( std::map<std::string, func> &lookup)
{
    int *p = new int (10);
    auto fptr  = [p]() {
        std::cout<<" Main:: first"<<*p<<"\n";
    };

   lookup.insert(std::pair< std::string, func  > ( std::string("test"), fptr) );

}

int main(void)
{
    std::map<std::string , func > lookup;

    foo(lookup);

/*    auto fptr  = []() {
        std::cout<<" Main:: first\n";
    };

   lookup.insert(std::pair< std::string, func  > ( std::string("test"), fptr) );
*/
    auto fnc = lookup["test"];


    if(fnc) {
        std::cout<<"  Main:: fnc  \n";
    }
    else {
        std::cout<<"  Main:: fnc :: nullptr \n";
    }

    return 0;
}
