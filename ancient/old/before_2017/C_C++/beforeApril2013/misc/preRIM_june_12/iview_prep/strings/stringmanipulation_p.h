#ifndef __STRING_P__
#define __STRING_P__

#include <iostream>
#include <string.h>
using namespace std;

class DerString;

class String
{
public:
  /*  String ()
    {
      cout << "String:::String\n";
      m_str = strdup ("default");
      m_length = 7;
    }*/
  String(DerString *child) : m_child(child)
  {
    cout << " String::String::para \n";
    // if (m_str == NULL)
    //    {
    //    String ();
    m_str = strdup("default");
    m_length = 7;
    // }
  }
  String(String &rhs);

  String(const char *rhs);
  String &operator=(const String &rhs);
  String &operator=(const char *rhs);

public:
  virtual void display() const
  {
    cout << " String :: display :: ... " << m_str;
  }
  virtual void setValues(char *val = "setValue");

  virtual ~String()
  {
    cout << "String :: ~String \n";
    delete m_str;
    m_length = 0;
  }

private:
  char *m_str;
  int m_length;
  DerString *m_child;
};

#endif // STRING_P
