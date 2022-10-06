#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <future>

template<typename T>
class Queue
{

};

std::queue<int> q;

void read()
{

}


void write()
{

}



int factorial(std::future<int> &data)
{
    int n = data.get();
    int res =  1,i =0;;
    while(i < n)
    {
        res=  res *++i;
    }

   // std::this_thread::sleep_for(std::chrono::milliseconds(res));
    return res;
}

constexpr int num_of_threads = 10;
int main(void)
{
  std::thread r_th[num_of_threads], w_th[num_of_threads];

  for (size_t i = 0; i < num_of_threads; i++)
  {
    r_th[i] = std::thread(read);
    w_th[i] = std::thread(write);
  }

  for (size_t i = 0; i < num_of_threads; i++)
  {
   r_th[i].join();
   w_th[i].join();
  }

  std::promise<int> prom;
  std::future<int> input = prom.get_future();

  std::future<int> f_res = std::async(std::launch::async, factorial, std::ref(input));

  prom.set_value(4);


  std::cout<<" value is "<< f_res.get();

  return 0;
}
