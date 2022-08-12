#include <iostream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>


void shiftonesandzeros(std::vector<int> &rhs)
{
    int i = 0, j = rhs.size()-1;

    while(i <= j)
    {
        if (rhs[i] == 1 && rhs[j] == 0)
        {
            std::swap(rhs[i], rhs[j]);
            i++;
            j--;
        }
        else
        if (rhs[i] == 0)
        {
            i++;
        }
        else
        if (rhs[j] == 1)
        {
            j--;
        }
    }
}


// C++ conversion functions between integers (or floats) to std::string.
template <typename T>
std::string toString(T t)
{
    std::ostringstream out;
    out << t;
    return out.str();
}


template <typename T>
T fromString(std::string t)
{
    T out;
    std::istringstream in(t);
    in >> out;
    return out;
}

int main(void)
{
    std::vector<int> v =  {0,1,1,0,1,0,1,0,1, 0};

    auto t1 = std::chrono::high_resolution_clock::now ();

    shiftonesandzeros(v);

    auto t2 = std::chrono::high_resolution_clock::now ();

    std::chrono::duration < double,std::milli > ms = t2 - t1;


    printf("%*d\n", 30, 100);


    std::string str =  "{\n name: \"rakesh\",\n";
    str+="num:";
    str+= "\"" + std::to_string(6) + "\" \n}";

    std::cout<<str;

    int val = 10;
    std::cout<<"\n str for "<<val<< " is "<< toString(val);

    std::cout<<"\n str for "<<val<< " is "<< fromString<std::string>(std::string("1982"));

    int a = 10;

    auto eq = [&a] ()
    {
        assert(a==10);

    };

    auto le = [&a] ()
    {

    assert (a > 10);


    };

    auto gt =  [&a]()
    {
        assert(a < 10);
    };


    eq();
    //le();
    gt();

    return 0;
}