#include <iostream>


/*

Add the following extension for EvtTxt:
Create 2 new registry keys in the EvtTxt:
Detect_key
Key_value
Extend the EvtTxt so that when there is a new line in the monitored file, the event is normally created (sent) but if the new line
contains the value defined in the Detect_key reg key then it tries to find the value after it.
The value will be compared with the value in reg. key Key_value.
If the value is different from what is already stored there then an event will be sent with some text (E.g. "Card number changed") and
the new value will be saved in the registry key.
The value in the registry key key_value will be encrypted in AES256 using a hard-coded fixed key.
E.g.
The Detect_key is defined as: Card number:
and the new line in the file is Card number: 123456
Then the number "123456" will be compared with the value that is in Key_value
If it is the same nothing will happen. Otherwise an event will be fired and the new value will be written in the reg key.
Otherwise the functionality of EvtTxt will remain the same as it already is.

*/


template<typename T>
class Base
{
    public:
    Base(T r):m_r(r)
    {

    }
    T m_r;


    void Der()
    {

   }
};



class Der: public Base<int>
{
    public:
    Der():Base(1)
    {

    }
};


class A
{
    public:
    A()
    {

    }

   virtual  ~A()
    {

    }

    void B()
    {

    }
};


class B:public A
{
    public:
    B()
    {

    }

    ~B()
    {

    }
};

int main(void)
{
    int *p = new int [20];
    for (int i = 0; i < 20;i++)
    {
        p[i] = i;
    }
    delete []p;

    Der d;

    A *a = new A();

    B *b = new B();
    delete a;
    a = b;
    delete a;

    //b->B();
    return 0;
}