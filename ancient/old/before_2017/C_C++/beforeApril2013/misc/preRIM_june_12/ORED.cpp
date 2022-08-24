#include <iostream>

using namespace std;

class T
{
public:
  T() : m_1st(false), m_2nd(false)
  {
    cout << "T::T\n";
  }
  inline bool first()
  {
    cout << "T::first\n";
    return m_1st;
  }
  inline bool second()
  {
    cout << "T::second\n";
    return m_2nd;
  }
  inline void setFirst() { m_1st = true; }
  inline void setSecond() { m_2nd = true; }

private:
  bool m_1st;
  bool m_2nd;
};

int main(void)
{
  T t;
  if (t.first() || t.second())
  {
    cout << "\n pass1:: \n";
  }
  t.setFirst();

  if (t.first() || t.second())
  {
    cout << "\n pass2:: \n";
  }

  return 0;
}
