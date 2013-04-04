#include"string.h"

int
String::strlen (const char *str)
{
  int i;
  for (i = 0; *(str + i) != '\0'; i++);
  return i;
}

String::String ():m_str (NULL), m_len (0)
{
}

String::String (const char *str)
{
	if(m_str != str)
	{
		m_len = strlen (str);
		m_str = new char[m_len];
		strcpy (m_str, str);
	}
}

String::String (const String & str)
{
	if(*this != str){
		m_len = str.m_len;
		m_str = new char[m_len];
		strcpy (m_str, str.m_str);
	}
}


String & String::operator= (const String & str)
{
	if(*this!=str)
	{
		delete m_str;
		m_len =  str.m_len;
		m_str  = new char[m_len];
		strcpy(m_str,str.m_str);
	}
	return *this;
}

String & String::operator = (const char *str)
{
	if(m_str!=str)
	{
		delete m_str;
		m_len =  strlen(str);
		m_str =  new char[m_len];
		strcpy(m_str,str);
	}
	return *this;
}

bool
String::operator > (const String & str)
{
	bool ret(false);
	return m_len> str.m_len ? !ret:ret;
}

bool
String::operator > (const char *str)
{
	bool ret(false);
	return m_len >strlen(str)?!ret:ret;
}

bool
String::operator == (const char *str)
{
	bool ret(false);
	return m_len  == strlen(str)?!ret:ret;

}

bool
String::operator == (const String & str)
{

	bool ret(false);
	return m_len  == str.m_len?!ret:ret;
}


bool String::operator!=(const String &str)
{
	return *this==str ? false: true;
}
String & String::operator + (const String & str)
{
	return *this;
}

String & String::operator + (const char *str)
{

	return *this;
}
