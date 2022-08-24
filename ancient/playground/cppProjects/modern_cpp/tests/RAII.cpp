#include <iostream>
#include <memory>

#define PRINTF(obj) std::cout << typeid(obj).name() << "::" << __func__ << "\n";

class Base
{
public:
  Base()
  {
    PRINTF(*this)
    func();
  }

  void testFire()
  {
    func();
  }

  // copy constructor
  Base(const Base &rhs){
      PRINTF(*this)}

  // move constructor
  Base(Base &&rhs){
      PRINTF(*this)}

  // assignment operator
  Base &
  operator=(const Base &rhs)
  {
    PRINTF(*this)
    return *this;
  }

  // move assignment operator
  Base &operator=(Base &&rhs)
  {
    PRINTF(*this)
    return *this;
  }

  // virtual
  void func()
  {
    PRINTF(*this);
  }

  virtual ~Base()
  {
    PRINTF(*this)
  }
};

class Der1 : public Base
{
public:
  Der1()
  {
    PRINTF(*this)
    Base::func();
  }
  ~Der1()
  {
    PRINTF(*this)
  }

  void func()
  {
    PRINTF(*this);
  }
};

class Der2 : public Base
{
public:
  Der2()
  {
    PRINTF(*this)
  }
  ~Der2()
  {
    PRINTF(*this)
  }
};

class GrandChild : public Der1, public Der2
{
public:
  GrandChild()
  {
    PRINTF(*this)
  }
  ~GrandChild()
  {
    PRINTF(*this)
  }
};

int main(void)
{
  //  Base *b = new Base ();
  // Base anotherBPtrCPy = *b;
  // auto *anotherBPtr = std::move (b);

  // std::unique_ptr < Base > ubptr = std::make_unique < Base > ();

  /*  Der1 *d1 = new Der1 ();

    Der2 *d2 = new Der2 ();

    std::shared_ptr < GrandChild > sgptr = std::make_shared < GrandChild > ();
  */
  // delete b;
  // delete anotherBPtr;
  // delete d1;
  // delete d2;
  std::unique_ptr<Base> p = std::make_unique<Der1>();
  p->testFire();

  return 0;
}
