#include <iostream>
#include <string.h>
using namespace std;

class utilityString;

class myString
{
public:
  myString() : m_str(0), m_length(0)
  {
    cout << "myString::myString\n";
  }

  myString(char *rhs)
  {
    cout << "myString::char *rhs\n";
    m_length = strlen(rhs);
    m_str = new char[m_length + 1];
    strcpy(m_str, rhs);
  }

  myString(const myString &rhs)
  {
    cout << "myString ::myString\n";
    if (this == &rhs)
      return;
    if (0 != m_length)
    {
      delete m_str;
      m_str = NULL;
    }
    *this = rhs.m_str;
  }

  myString &operator=(char *rhs)
  {
    cout << "myString::char *rhs\n";
    m_length = strlen(rhs);
    m_str = new char[m_length + 1];
    strcpy(m_str, rhs);
    return *this;
  }

  myString &operator=(const myString &rhs)
  {
    cout << "myString:: ASSIGNMENT OPERATOR \n";
    if (this == &rhs)
      return *this;
    if (0 != m_length)
    {
      delete m_str;
      m_str = NULL;
    }
    *this = rhs.m_str;
  }

  void display(void)
  {
    cout << "myString::display :: " << m_str << endl;
  }

  ~myString()
  {
    cout << " myString ::~myString  m_str :: " << m_str << endl;
    if (m_str != NULL)
    {
      m_length = 0;
      delete m_str;
    }
  }

  void replace(char *src, char *dest)
  {
  }

private:
  utilityString uClass;
  mutable char *m_str;
  mutable int m_length;
  friend class utilityString;
};

int main(void)
{
  myString str1("test");
  return 0;
}
