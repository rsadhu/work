#include <iostream>
#include <vector>

class Der;
template <typename T>
class Base
{
public:
  Base(T *child)
  {
    std::cout << "Base::Base\n";
    mData.push_back(child);
  }

  ~Base()
  {
    std::cout << " Base::~Base\n";
  }
  std::vector<T *> mData;
};

class Der : public Base<Der>
{
public:
  Der() : Base(this)
  {
    std::cout << "Der::Der\n";
  }
  ~Der()
  {
    std::cout << "Der::~Der\n";
  }
  void display()
  {
    std::cout << " Der:: display\n";
  }

  friend class Base;
};

int main(void)
{
  Der *d = new Der();
  d->display();
  delete d;

  return 0;
}
