#include<iostream>
#include<string.h>
using namespace std;

class strings
{
public:
  strings ();
  strings (const strings & rhs);
  strings (const char *rhs);
  strings & operator = (const strings & rhs);
  strings & operator = (const char *rhs);
  bool operator == (const strings & rhs);
  strings & operator + (const strings & rhs);
  ~strings ();
  bool isSentence ();
  void reverse ();
  inline int length(){ return m_length;}
  inline char *ascii(){ return m_str;}

public:
  void display ()
  {
    cout << " the string is .." << m_str << endl;
  }
protected:
  void reverseWord (int from, int to);
private:
  int m_length;
  char *m_str;
};

void
strings::reverseWord (int from, int to)
{
  char ch;
  while (from < to)
    {
      ch = *(m_str + from);
      *(m_str + from) = *(m_str + to);
      *(m_str + to) = ch;
  	from++;
	to--;      
    }

}

bool strings::isSentence ()
{
char *s = m_str;
  while (*s++ != '\0')
    {
      if (*s == ' ')
	return true;
    }
  return false;
}

void
strings::reverse ()
{
  reverseWord (0, m_length - 1);
  if (isSentence ())
    {
	cout<<"  its sentence \n";
    }
}


strings::strings ()
{

  m_str = NULL;
  m_length = 0;
  cout << " strings :: strings\n";
}

strings::strings (const char *rhs)
{
  m_length = strlen (rhs);
  m_str = new char[m_length + 1];
  strcpy (m_str, rhs);
}

strings::strings (const strings & rhs)
{
  m_length = rhs.m_length;
  m_str = new char[m_length + 1];
  strcpy (m_str, rhs.m_str);
}

strings & strings::operator = (const char *rhs)
{
  cout << "strings:: operator = char * \n";
  if (0 != strcmp (this->m_str, rhs))
    {
      delete m_str;
      m_length = strlen (rhs);
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs);
    }
  return *this;
}

strings & strings::operator = (const strings & rhs)
{
  cout << " assignment operator = \n";
  if (this != &rhs)
    {
      delete m_str;
      m_length = rhs.m_length;
      m_str = new char[m_length + 1];
      strcpy (m_str, rhs.m_str);
    }
  return *this;
}

strings & strings::operator + (const strings & rhs)
{
  cout << " strings::append\n";
  if (rhs.m_length > 0)
    {
      char *
	tmp = strdup (m_str);
      delete m_str;
      m_length = m_length + rhs.m_length;
      m_str = new char[m_length + 1];
      strcpy (m_str, tmp);
      strcat (m_str, rhs.m_str);
      delete tmp;
    }
  return *this;
}

bool
strings::operator == (const strings & rhs)
{
  bool ret (false);
  if (this == &rhs)
    ret = true;
  else if (0 == strcmp (this->m_str, rhs.m_str))
    ret = true;

  return ret;
}


strings::~strings ()
{
  cout << " strings:: ~strings:: " << __func__ << endl;
  delete m_str;
  m_length = 0;
}


int
main (void)
{
#ifdef R
  strings *s = new strings ("testing functionality");
  s->display ();
  *s = " test";
  s->display ();
  strings t (*s);
  t.display ();
  strings u ("hello");
  u.display ();
  t = u;
  t.display ();
  t = " hello how are you";
  t.display ();
  t = *s + u + t;
  t.display ();
  if (t == u)
    cout << " same " << endl;
  else
    cout << " not same" << endl;
  cout << t.isSentence () << endl;


  delete s;
#endif //

  strings *a = new strings ("hola");
  strings *b = new strings (" hola como estas");
  a->display ();
  a->reverse ();
  a->display ();
  delete a;
  b->display ();
  b->reverse ();
  b->display ();
  delete b;
  return 0;
}
