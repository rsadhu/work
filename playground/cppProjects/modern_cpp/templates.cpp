#include <iostream>


template < typename T > 
void
run (T rhs)
{
  //rhs.template perform(10);
  rhs.perform (10);
  rhs.m_t = 10;
}


class Test
{
public:
  template < typename U > 
  void 
  perform (U rhs)
  {
    std::cout << "Test::Perform" << rhs << "\n";
  }

  template < typename V > 
  class Another
  {
  public:
    V m_a;
  };

  Another m_t;
};




int
main (void)
{
  Test t;
  run (t);
  return 0;
}
