#pragma once


/*
push(item)
insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
prepend(item) - can use insert above at index 0
pop() - remove from end, return value
delete(index) - delete item at index, shifting all trailing elements left
remove(item) - looks for value and removes index holding it (even if in multiple places)
find(item) - looks for value and returns first index with that value, -1 if not found
resize(new_capacity) // private function
*/
template <typename T>
class MyVector
{
public:
	MyVector();
	MyVector(unsigned int, T &);
	MyVector(const MyVector &);
	MyVector & operator =(const MyVector &);
	~MyVector();

	inline int capacity() { return m_Capacity; }
	inline int size() { return m_Size; }
	inline bool isEmpty(){ return m_Size == 0; }
	void insert(unsigned int, T&);
	T & pop();
	void del(unsigned int value);
	void remove(unsigned int index);
	unsigned int find(T &);
	T & at(unsigned int);
	T & operator [](unsigned int);
protected:
	void resize(unsigned int new_capacity);
private:
	int m_Capacity = 10000;
	int m_Size = 0;
	int m_Index = 0;
	T *m_Data;
};




template<typename T>
MyVector<T>::MyVector<T>()
{
	m_Data = new T[m_Capacity]();

}

template<typename T>
MyVector<T>::~MyVector<T>()
{


}

template<typename T>
MyVector<T>::MyVector(unsigned int, T &)
{

}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &rhs)
{


}

template<typename T>
MyVector<T> & MyVector<T>::operator = (const MyVector<T> &rhs)
{

}


template<typename T>
void MyVector<T>::insert(unsigned int, T&)
{

}

template<typename T>
T & MyVector<T>::pop()
{

}

template<typename T>
void MyVector<T>::del(unsigned int value)
{

}

template<typename T>
void MyVector<T>::remove(unsigned int index)
{

}

template<typename T>
unsigned int MyVector<T>::find(T &)
{

}


template<typename T>
T & MyVector<T>::at(unsigned int)
{

}

template<typename T>
T &  MyVector<T>:: operator [](unsigned int index)
{
	return m_Data[index];
}

