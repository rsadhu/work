#include<iostream>
#include<string.h>
using namespace std;


class CString
{
public:
  CString ()
  {
    m_str = NULL, m_length = 0;
    cout << "cString :: cString\n";
  }
  CString (char *str)
  {
    cout << "CString :: constructor \n";
    m_length = strlen (str);
    m_str = new char[m_length + 1];
    strcpy (m_str, str);
  }
  CString (const CString & rhs);
  CString & operator = (const CString &);
public:
  inline int length ()
  {
    return m_length;
  }
  static inline int length (CString & p)
  {
    return p.m_length;
  }
  static inline int overloadFunc (char a, int b = 0)
  {
    return (int) a *b;
  }
  inline static int overloadFunc (int a, int b = 4)
  {
    return a * b;
  }
public:
  void display ()
  {
    cout << "\n the stirng is " << m_str << endl;
  }
  void reverseRec ();
  void reverseIter ();
  void reverseSentence ();
private:
  char *m_str;
  int m_length;
};


CString::CString (const CString & rhs)
{
  cout << "\nCString :: copy Constructor \n";
  if (this != &rhs)
    {
      m_length = strlen (rhs.m_str);
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs.m_str);
    }
  else
    {
      m_length = rhs.m_length;
      delete m_str;
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs.m_str);
      cout << "else ::: " << __func__ << this;
    }
}


CString & CString::operator = (const CString & rhs)
{
  cout << "CString :: CString :: operator = \n";
  if (this != &rhs)
    {
      m_length = strlen (rhs.m_str);
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs.m_str);
    }
  else
    {
      m_length = rhs.m_length;
      delete
	m_str;
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs.m_str);
      cout << " else :: cString :: operator = \n" << this;

    }
}

void
CString::reverseRec ()
{
  cout << "CString::reverseRec\n";
}

void
reverseFromTo (char *str, int from, int to)
{
  char ch;
  while (from < to)
    {
      ch = *(str + from);
      *(str + from) = *(str + to);
      *(str + to) = ch;
    }
}

void
CString::reverseIter ()
{
  cout << "CString::reverseIter\n";
  char ch;
  for (int i = 0, j = m_length - 1; i < j; i++, j--)
    {
      ch = m_str[i];
      m_str[i] = m_str[j];
      m_str[j] = ch;
    }
}

void
CString::reverseSentence ()
{
  cout << "CString::reverseSentence\n";
  reverseIter ();
  int flag = 0;
  for (int i = 0, cnt = 0; i < m_length; i++)
    {
      while (m_str[i] == ' ')
	{
	  flag++;
	  i++;
	}

      if (flag != 0)
	{
	  reverseFromTo (m_str, cnt, i - flag);
	  cnt = i + flag;
	  flag = 0;
	}
    }
  cout << " the string is .... " << m_str << endl;
}

int
main (void)
{
  CString cStr2, cStr3 (const_cast < char *>("testing")), cStr4 (cStr3);
  cStr2 = cStr3;
  cout << " The length of cstr2 --- " << cStr2.length () << endl;
  cout << "The length of cstr3 ... " << CString::length (cStr3) << endl;
  cout << " the product is ... " << CString::overloadFunc (5);
  cout << " the product is ... " << CString::overloadFunc ('a', 2);
  cout << " the product is ... " << CString::overloadFunc ('a') << endl;
  cStr3.reverseIter ();
  cStr3.display ();
  CString t ("rakesh is my name");
  t.reverseSentence ();
  return 0;
}
