#include <iostream>

class Base {
public:
  Base() { std::cout << "\nBase::Base\n"; }
  explicit Base(int a) { std::cout << "Base::Base::int\n"; }

  explicit Base(double a) { std::cout << " Base::Base::double " << a << "\n"; }

  virtual void process(int a) { std::cout << " Base:: process\n"; }

  virtual ~Base() { std::cout << "Base::~Base\n"; }
};

class Der : public Base {
public:
  using Base::Base;

  Der() { std::cout << "\nDer::Der\n"; }

  Der(int i) { std::cout << "\n Der::int " << i << "\n"; }

  void process(char c) { std::cout << " Der::process " << c << "\n"; }
  ~Der() { std::cout << "\nDer::~Der\n"; }
};

int main(void) {
  /*Base *b = new Der(10.0);

  b->process(10);
  delete b;
  b =  new Der(10);

  b->process(10);

*/
  //    Base *bb =  new Der(10);
  //  delete bb;

  Base b(1.0f);
  Base c(1);
  Base d(c);

  return 0;
}
