#include <iostream>
#include <memory>

class Data
{
public:
  Data()
  {
    std::cout << "Data::Data:: " << s_ref++ << "\n";
  }
  Data(const Data &rhs)
  {
    std::cout << "Data::copy Data:: " << s_ref++ << "\n";
  }

  ~Data()
  {
    std::cout << "Data::~Data:: " << s_ref-- << "\n";
  }
  void display()
  {
    std::cout << " Data::display\n";
  }
  static int s_ref;
};

int Data::s_ref = 0;

template <typename T>
class Compositor
{
public:
  Compositor()
  {
    m_obj = std::make_unique<T>();
  }
  ~Compositor()
  {
    std::cout << "Compositor::~Compositor\n";
  }
  void setImplementation(std::unique_ptr<T> d)
  {
    m_obj = d;
  }

private:
  std::unique_ptr<T> m_obj;
};

template <typename T>
class Test
{
public:
  void
  receive(const std::shared_ptr<T>);
  std::shared_ptr<T> send() const;

private:
  std::shared_ptr<T> m_sptr;
};

template <typename T>
void Test<T>::receive(const std::shared_ptr<T> sp)
{
  T *rPtr = sp.get();
}

template <typename T>
std::shared_ptr<T> Test<T>::send() const
{
  return m_sptr;
}

int main(void)
{
  std::unique_ptr<int> p = std::make_unique<int>();

  *p = 10;

  std::cout << "jjjjjjjjj===>>  " << *(p.get());
  std::cout << "jjjjjjjjj===>>  " << *(p.get());

  std::unique_ptr<int> up = std::make_unique<int>(10);

  std::cout << " value in up is " << *up << "\n";

  std::unique_ptr<int> &nup = up;

  *nup = 100;

  std::cout << " value in up is " << *up << "\n";

  //  delete nup.get();

  //  std::cout<<" value in up is "<<*up<<"\n";
  std::unique_ptr<int> ppp;
  return 0;
}
