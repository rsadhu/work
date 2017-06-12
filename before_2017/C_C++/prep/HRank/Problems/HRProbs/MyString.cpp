#include "stdafx.h"
#include "MyString.h"
#include <string.h>
#include <malloc.h>

MyString::MyString(char *src)
{
	mString = _strdup(src);
	mLength = strlen(src);
}


MyString::MyString(const MyString &rhs)
{
	mString = _strdup(rhs.mString);
	mLength = rhs.mLength;
}

MyString & MyString::operator = (const MyString &rhs)
{
	if (this != &rhs)
	{
		if (mString)
			free(mString);

		mString = _strdup(rhs.mString);
		mLength = rhs.mLength;
	}
	return *this;
}

MyString::~MyString()
{
	free(mString);
	mLength = 0;
}


int MyString::length()
{
	return mLength;
}

bool MyString::compare(MyString &rhs)
{
	bool ret(false);
	return ret;
}

bool MyString::compare(const char *)
{
	bool ret(false);
	return ret;
}

bool MyString::compare(MyString &, MyString &)
{
	bool ret(false);
	return ret;
}