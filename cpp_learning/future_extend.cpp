#include <iostream>
#include <string>
#include <future>

static int cnt = 0;
template <typename T>
class F : std::future<T>
{
public:
  F(std::future<T> &&f) : std::future<T>(std::move(f))
  {
    std::cout << "\n move -- " << ++cnt;
  }

  ~F()
  {
    std::cout << --cnt << "F::~F\n";
  }
};

int main()
{
  std::string x = "x";

  auto f1 = std::async(std::launch::async, [&x]()
                       { x = "y"; });

  F ff = std::move(f1);

  auto f2 = std::async(std::launch::async, [&x]()
                       { x = "z"; });

  F ff1 = std::move(f2);

  std::cout << x;
}