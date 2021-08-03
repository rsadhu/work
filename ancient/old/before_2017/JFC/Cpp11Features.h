#pragma once
#include<initializer_list>
#include<vector>
#include<array>
#include<iostream>

template<typename T,unsigned int size=100>
class Cpp11Features
{
public:
	Cpp11Features();
	Cpp11Features(const std::initializer_list<T> &list);
	~Cpp11Features();
	void display();
private:	
	std::array<T,size> m_Vect;
	int mIndex = 0;
};




template<typename T,unsigned int size >
Cpp11Features<T,size>::Cpp11Features()
{
}

template<typename T, unsigned int size >
Cpp11Features<T,size>::Cpp11Features(const std::initializer_list<T> & list)
{
	for (auto i : list)
	{
		m_Vect.at(mIndex++) = i;
	}
}

template<typename T, unsigned int size >
Cpp11Features<T,size>::~Cpp11Features()
{
}

template<typename T, unsigned int size >
void Cpp11Features<T, size>::display()
{
	for (auto i : m_Vect)
	{
		std::cout << "value :  " << i << std::endl;
	}
}





