#include <iostream>

/*class Base
{
 public:
void play(int d)
{
 std::cout<<"Base::play : "<<d<<"\n";
}
};


class Der: public Base
{
 public:
using Base::play;
 void play(float f)
{
 std::cout<<" Der::play "<<f<<"\n";
}

void  play(char c)
{
    std::cout<<" Der::play:: int"<<c<<"\n";
}

};
*/

// perfect forwarding ? 

int sq(int s)
{
 return s*s;
}



template<typename T>
T forwarding_fun(T && rhs) 
{
// std::forward  job was to forward the reference , 
  //return sq(std::forward<T> (rhs));
  return sq(rhs);
}




int main(void)
{
 ///Der d;
 //d.play(10);
 //d.play('c');

 int d = 3;

  std::cout<<"square of 10 "<< forwarding_fun(10);  // int && 
  std::cout<<"square of 10 "<< forwarding_fun(d);  // int &


};
