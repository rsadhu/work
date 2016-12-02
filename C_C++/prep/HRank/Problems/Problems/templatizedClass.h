#pragma once
#include<iostream>


template<typename T>
class templatizedClass
{
public:
	templatizedClass();
	~templatizedClass();
	 friend void test();
	 void display()
	 {
		 if (mObj)
		 {
			 std::cout << *mObj << std::endl;
		 }
	 }
private:
	T *mObj;
};



template<typename T>
templatizedClass<T>::templatizedClass() 
{
	mObj = new T();
}

template<typename T>
templatizedClass<T>::~templatizedClass()
{
	delete mObj;
}


template<typename U>
void test(U &obj)
{
	obj.display();
}

template<typename T>
class Der : public templatizedClass<T>
{
public:
	Der();
	void foo1();
};




template<typename T>
Der<T>::Der()
{

}


template<typename T>
void Der<T>::foo1()
{

}






class Test
{
public:
	template <typename T>
	static T adder(T a,T b)
	{
		return a + b;
	}
};