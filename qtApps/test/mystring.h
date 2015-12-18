#ifndef MYSTRING_H
#define MYSTRING_H
#include<string.h>
//#include<iostream>
#include<QDebug>

class Test;
class MyString
{
public:
    MyString(){ mData = new char[1000]; memset(mData,0,1000);}
    MyString(const MyString &rhs);
    MyString & operator=(const MyString &rhs);

    inline char *toAscii(){ return mData;}
    inline void setText(char *s="hello Main Obj"){ strcpy(mData,s);}

    friend void fFunc(MyString &);

    void display(){ qDebug()<<"string is ..."<<mData<<"\n";}
private:
    char *mData;
    int mLen;
    friend class Test;
};

class Test
{
 public:
    void foo(MyString &obj){ strcpy(obj.mData,"freind obj says hello");}

};



#endif // MYCLASS_H
