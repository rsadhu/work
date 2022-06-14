#include <cmath>
#include <initializer_list>
#include <iostream>
#include <map>
#include <set>
#include <vector>

struct Data {
  int _indentifier;
  std::string _content;
};

std::ostream &operator<<(std::ostream &os, const struct Data &s) {
  os << s._indentifier << " " << s._content << "\n";
  return os;
}

class Test {
public:
  Test() {
    std::cout << "\nTest::Test  " << _counter << "\n";
    _counter++;
  }

  Test(int a, char ch, std::string str) : _int(a), _char(ch), _str(str) {
    std::cout << "\n constructor :: int a, char ch, std::string str   "
              << _counter << " \n";
    _counter++;
  }

  ~Test() {
    _counter--;
    std::cout << "\nTest::~Test  " << _counter << "\n";
  }

  Test(std::initializer_list<int> rs) {
    _counter++;
    std::cout << "\n constructor :: initializer_list\n";
    for (auto it : rs) {
      _arr.push_back(it);
    }
  }

  void foo(const std::string &str = "test") {
    std::cout << "Test::foo " << str << "\n";
  }

  void displayItems() const {
    std::cout << "\n";
    for (auto it : _arr) {
      std::cout << it << "  ";
    }
    std::cout << "\n";
  }

  Test &operator+(const Test &rhs) { return *this; }

private:
  int _int;
  char _char;
  std::string _str;
  std::vector<int> _arr;

  static int _counter;
};

int Test::_counter = 0;

template <typename T> void print(T arg, std::map<int, T> &rhs) {
  static int cnt = 0;
  rhs[cnt++] = arg;
}

void printMatrixBySize() {

  std::vector<std::vector<int>> arr = {
      {0, 1, 2, 3},
      {4, 5, 6, 7},
      {8, 9, 10, 11},
      {12, 13, 14, 15},
  };
  std::cout << "\n";

  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j < static_cast<size_t>(sqrt(arr.size())); j++) {
      for (int k = 0; k < static_cast<size_t>(sqrt(arr.size())); k++) {
        std::cout << arr[j % 3][k % 3] << " ";
      }
    }
    std::cout << "\n";
  }
}

constexpr long double operator""_mm(long double val) { return val / 100; }

constexpr long double operator""_km(long double val) {
  return val * 100 * 1000;
}

constexpr long double operator""_m(long double val) { return val * 100; }

template <typename passType, typename retType>
retType handleArgs(passType arg) {
  std::cout << "\ntype of passed arg is " << typeid(arg).name() << "\n";

  return static_cast<retType>(10.0);
}

int main(void) {
  std::cout << "\nMain\n";

  char *arr[2] = {"abc", "def"};
  char brr[2][4] = {"abc", "def"};

  std::cout << "\n" << arr[0] << "   " << arr[1] << "\n";

  std::cout << "\n" << brr[0] << "   " << brr[1] << "\n";

  struct Data d {
    1234, "This is the testing going on"
  };

  std::cout << d;

  d._indentifier *= 2;

  std::reverse(d._content.begin(), d._content.end());

  std::cout << d;

  printMatrixBySize();

  std::cout << "how many centemetres 100m have " << 100.0_m << "\n";
  std::cout << "how many centemetres 100km have " << 100.0_km << "\n";
  std::cout << "how many centemetres 100mm have " << 100.0_mm << "\n";

  std::cout << handleArgs<std::string, int>("a");

  const int *p;
  int z = 10;

  p = &z;

  int qq = 99;
  p = &qq;

  //*p =10;

  int *const q = &z;

  *q = 100;

  const Test t;
  t.displayItems();
  // t.foo();
  Test uu;
  uu.foo("This is a non const object's call to foo");

  const Test *c_t = new Test();
  delete c_t;

  Test *const d_t = new Test();
  delete d_t;
  c_t = new const Test();

  delete c_t;

  return 0;
}