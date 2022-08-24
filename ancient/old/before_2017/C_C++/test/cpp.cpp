#include <iostream>
#include <thread>
#include <mutex>
std::mutex mu, mu1;

void sharedPrint_1()
{
  // mu1.lock ();
  mu.lock();

  std::cout << " sharedPrint_1 " << std::endl;

  mu.unlock();
  // mu1.unlock ();
}

void sharedPrint_2()
{
  // mu1.lock ();
  mu.lock();

  std::cout << " sharedPrint_2 " << std::endl;

  mu.unlock();
  // mu1.unlock ();
}

void myThread()
{

  for (int i = 0; i < 100; i++)
    sharedPrint_1();
  //    std::cout<<" Worker Thread ::"<< i<<std::endl;
}

class
    A
{
public:
  // explicit
  A(int x = 0)
  {
    std::cout << "parameterized constructor\n";
  }
  A(const A &rhs)
  {
    std::cout << "COPY CONSTRUCTOR\n";
  }
  static void
  s_fun();
  void
  m_fun();
};

void A::s_fun()
{
  std::cout << "A::s_fun\n";
}

void A::m_fun()
{
  std::cout << "A::m_fun\n";
  s_fun();
}

void test()
{
  int a = 0;
  int *const p = &a;
  int const *x = new int(9);
}

void t(A a)
{
}

int main(int argc, char *argv[])
{
  std::thread::hardware_concurrency();

  std::thread t1(myThread);
  for (int i = 0; i < 100; i++)
    //    std::cout<<"Main Thread:: "<< i<<std::endl;
    sharedPrint_2();

  t1.join();
  std::cout << "done\n";

  A b = 10;
  t(10);
  return 0;
}
