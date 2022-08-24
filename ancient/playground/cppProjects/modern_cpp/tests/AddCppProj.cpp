#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include <numeric>
#include <map>

using mymap = std::map<int, int>;
typedef std::map<int, int>
    mappp;

int foo(int x)
{
  return x * x;
}

int asyncTask(int arg)
{
  return arg;
}

int asyncTask1(std::shared_future<int> arg)
{

  int
      N = arg.get();
  return N + N;
}

class
    Test
{
public:
  Test()
  {
    std::cout << "Test::Test\n";
  }

  Test(const Test &rhs)
  {
    std::cout << "\n Copy Const\n";
  }

  Test(const Test &&rhs)
  {
    std::cout << "\n Move Const\n";
  }

  Test &operator=(const Test &rhs)
  {
    std::cout << "\n copy assignment operator \n";
  }

  Test &operator=(const Test &&rhs)
  {

    std::cout << "\n move assignment operator \n";
  }
};

Test createTest(Test x)
{
  Test
      t;
  // return std::move(t);
  return t;
}

int main(void)
{
  auto
      f = std::bind(foo, 8);
  std::cout << "\n"
            << f(10);
  int
      arg = 100;

  std::future<int>
      ret = std::async(std::launch::async, asyncTask, arg);

  std::cout << "\n"
            << ret.get();

  std::promise<int>
      data;
  std::shared_future<int>
      sf = data.get_future().share();

  std::future<int>
      ret1 = std::async(std::launch::async, asyncTask1, sf);
  std::future<int>
      ret2 = std::async(std::launch::async, asyncTask1, sf);
  std::future<int>
      ret3 = std::async(std::launch::async, asyncTask1, sf);

  data.set_value(9);
  ;

  std::cout << "\n"
            << ret1.get();
  std::cout << "\n"
            << ret2.get();
  std::cout << "\n"
            << ret3.get();

  std::vector<double>
      v = {1.9, .2, .3, .4, .5, .1, .4, .1, .1};

  {
    auto
        t1 = std::chrono::high_resolution_clock::now();
    double
        result = std::accumulate(v.begin(), v.end(), 0.0);
    auto
        t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,
                          std::milli>
        ms = t2 - t1;
    std::cout << std::fixed << "std::accumulate result " << result
              << " took " << ms.count() << " ms\n";
  }

  /*  {
      auto t1 = std::chrono::high_resolution_clock::now ();
      double result = std::reduce (std::execution::par, v.begin (), v.end ());
      auto t2 = std::chrono::high_resolution_clock::now ();
      std::chrono::duration < double, std::milli > ms = t2 - t1;
      std::cout << "std::reduce result "
        << result << " took " << ms.count () << " ms\n";
    }*/

  Test
      x;
  Test
      t = createTest(x);

  // string_view("rakesh");

  mymap
      m2 = {{1, 3}, {2, 4}};
  mappp
      m1 = {{3, 2}, {2, 3}};

  return 0;
}
