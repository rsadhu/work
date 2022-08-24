#include <pthread.h>
#include <iostream>
using namespace std;

class MyRunnable
{
public:
  virtual void run() const = 0;
  void virtual start();
  virtual ~MyRunnable()
  {
    cout << " MyRunnable ::~MyRunnable\n";
  }
};

void *
threadFunc(void *para)
{
  cout << "threadFunc::called \n";
  MyRunnable *that = reinterpret_cast<MyRunnable *>(para);
  if (that)
  {
    that->run();
  }
}

void MyRunnable::start()
{
  cout << " MyRunnable::start\n";
  pthread_t tid1;
  int handle = pthread_create(&tid1, NULL, threadFunc, this);
  pthread_join(tid1, NULL);
}

class Test : public MyRunnable
{
public:
  void run() const
  {
    cout << "Test::Runnable\n";
  }
  ~Test()
  {
    cout << " Test::~Test\n";
  }
};

int main(void)
{
  MyRunnable *t = new Test;
  t->start();
  cout << " main func:: start already Called";
  delete t;
  return 0;
}
