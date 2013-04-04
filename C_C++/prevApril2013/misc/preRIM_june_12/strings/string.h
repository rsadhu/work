#ifndef __STIRNG__H
#define __STRING__H

#include<iostream>
#include<string.h>

using namespace std;


class String
{
public:
  String ();
  String (const char *);
  String (const String &);
  String & operator= (const String &);
  String & operator = (const char *);
  bool operator > (const String &);
  bool operator > (const char *);
  bool operator == (const char *);
  bool operator == (const String &);
  bool operator!=(const String &);
  String & operator + (const String &);
  String & operator + (const char *);
  

  char *ascii(){ return m_str;}

  static int strlen (const char *);
private:
  char *m_str;
  int m_len;
};

#endif
