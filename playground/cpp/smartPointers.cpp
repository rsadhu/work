#include<iostream>
#include<memory>


class Data
{
public:
  Data ()
  {
    std::cout << "Data::Data:: " << s_ref++ << "\n";
  }
  Data (const Data &rhs)
  {
    std::cout << "Data::copy Data:: " << s_ref++ << "\n";
  }

   ~Data ()
  {
    std::cout << "Data::~Data:: " << s_ref-- << "\n";
  }
  void display ()
  {
    std::cout << " Data::display\n";
  }
  static int s_ref;
};


template < typename T > 
class Compositor
{
public:
  Compositor ()
  {
    m_obj = std::make_unique < T > ();
  } 
  ~Compositor ()
  {
      std::cout<<"Compositor::~Compositor\n";
  }
  void setImplementation (T * d)
  {
    m_obj = std::make_unique<T>(*d);
  }
private:
  std::unique_ptr < T > m_obj;
};

int Data::s_ref = 0;

template < typename T > 
class Test
{
public:
  void receive (const std::shared_ptr < T >);
  std::shared_ptr < T > send ()const;
private:
  std::shared_ptr < T > m_sptr;
};


template < typename T > 
void Test <T >::receive (const std::shared_ptr < T > sp)
{
  T * rPtr = sp.get ();
//  std::cout << rPtr->display ();
}


template < typename T > 
std::shared_ptr < T > Test < T >::send () const
{
 return m_sptr;
}




int
main (void)
{
  //std::shared_ptr < int >
  //sp (std::make_shared < int >(9));

  //Test < int > t;
  //t.receive (sp);

  //Test < Data > s;
  //auto sd = std::make_shared < Data > ();
  //s.receive (sd);

    
  Compositor<Data> cmp;
  cmp.setImplementation(new Data());

  return 0;
}
