#include<iostream>

template<typename T>

class GC
{

 ~GC()
 private:
 T *m_obj;
};