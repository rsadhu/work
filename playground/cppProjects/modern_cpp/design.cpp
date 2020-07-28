#include <iostream>


struct stud
{
 int i=0;
 float f=0.0f;
 double d=0.0;
};


/*class Test;
template <typename T>
class Base
{
 private:
 T m_data;
};



class Test: public Base<Test>
{
public:
friend Base<Test> ;
};
*/
int main(void)
{
//static 
constexpr struct stud d;
std::cout<<d.i<< "  "<< d.d <<"  "<< d.f;

// Test t;
 return 0;
}
