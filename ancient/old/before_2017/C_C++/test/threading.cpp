#include <iostream>
#include <thread>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void myThread()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << " Worker Thread1:: I am in my thread\n";
}

class FunctorClas
{
public:
  void operator()()
  {
    std::cout << "\nMain Thread ::  Hello you're in Functor class \n";
  }
};

void *
lThread(void *p)
{
  int val = *(int *)p;
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << "Worker Thread:: Thread wait finished ::  " << val << std::endl;
  return (void *)(val * val);
}

void linuxThread()
{
  pthread_t t1;
  int *p = new int(9);
  pthread_create(&t1, 0, lThread, (void *)p);
  void **ret;
  pthread_join(t1, ret);
  std::cout << " MainThread:: value from thread :: " << *(int *)ret;
  delete p;
}
int main(void)
{

  std::thread t1(myThread);
  FunctorClas s;
  s();

  linuxThread();

  t1.join();

  return 0;
}
