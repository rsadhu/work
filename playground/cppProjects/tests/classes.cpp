// *****************    disco dance **************  me 

template<typename T>
class Base
{
public:
  virtual void displayData ();
 
 virtual void setData(const T &d)
 {
    m_Data = d;
 }
 virtual ~Base()
 {
    std::cout<<" Base::~Base\n";
 }

private:
  T m_Data = 0;
};

template<typename T>
void
Base<T>::displayData ()
{

  std::cout << " Der::displayData:: data" << m_Data << "\n";
}



template<typename T>
class Der:public Base<T>
{
public:
  Der (int x)
  {

  }

  void displayData () override;
  void setData(const T &d) override
  {
      m_Data=d;
  }

  ~Der()
  {
    std::cout<<" Der::~Der\n";
  }

private:
  T m_Data = 0;
};


template<typename T>
void
Der<T>::displayData ()
{
  std::cout << " Der::displayData:: data" << m_Data << "\n";
}


int
main (void)
{
  std::unique_ptr < Base<int> > uptr (new Der<int> (5));
  uptr->displayData ();
  return 0;
}
