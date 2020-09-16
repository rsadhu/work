#include <iostream>


struct stud
{
 int i;
 float f ;
 std::string str;
};



int main(void)
{
 struct stud st{ 1, 1.4f, std::string("abc")},st1;;
 st1 = st;

 std::cout<<st.i << st.f<<st.str<<"\n";
 std::cout<<st1.i << st1.f<<st1.str;  
 return 0;
}



