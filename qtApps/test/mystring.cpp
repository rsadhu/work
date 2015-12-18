#include "mystring.h"

MyString::MyString(const MyString &rhs)
{
    mData = new char[rhs.mLen];
    strcpy(mData,rhs.mData);
}

MyString &MyString ::operator=(const MyString &rhs)
{
    if(this!=&rhs){
        mData = new char[rhs.mLen];
        strcpy(mData,rhs.mData);
    }
    return *this;
}

void fFunc (MyString &obj)
{
    strcpy(obj.mData,"freind func  says hello");
}



