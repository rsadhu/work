#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <utility>

using func = std::function<void()>;

void lambaFunction(void) { std::cout << " lambaFunction \n"; }

void foo(std::map<std::string, func> &lookup) {
  int *p = new int(10);
  auto fptr = [p]() { std::cout << " Main:: first" << *p << "\n"; };

  lookup.insert(std::pair<std::string, func>(std::string("test"), fptr));
}

namespace X {
namespace Y {
namespace Z {
void foo() { std::cout << " A::B::D::foo\n"; }
} // namespace Z

} // namespace Y
} // namespace X

int main(void) {
  std::map<std::string, func> lookup;

  foo(lookup);

  auto fnc = lookup["test"];

  if (fnc) {
    std::cout << "  Main:: fnc  \n";
  } else {
    std::cout << "  Main:: fnc :: nullptr \n";
  }

  auto t = [](auto t) { std::cout << " lamba:: auto " << t << "\n"; };

  t(00);
  t("string");
  t('c');
  t(0.4f);

  // std::apply(lambaFunction, std::make_tuple(1, 2, 3, 4));
  auto fc = std::bind(lambaFunction);

  fc();
  X::Y::Z::foo();

  return 0;
}
