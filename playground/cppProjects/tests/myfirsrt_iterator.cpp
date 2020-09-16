#include <iostream>
#include <vector>


template < typename T > 
class Test
{
  using DataType = std::vector < T >;
public:

private:
  DataType m_items;
};


class MyIterator
{
  public:
    MyIterator & begin ()
    {
      return *this;
    }

    MyIterator & end ()
    {
      return *this;
    }

    DataType & operator * ()
    {
      return m_items;
    }

    DataType & operator -> ()
    {
      return &m_items;
    }
  friend class Test;
};





int
main (void)
{
  Test < int >t; 
  return 0;
}
