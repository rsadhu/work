#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
	Vector() : m_size(100), m_length(0) { cout << "Vector::Vector\n"; }
	void push_back(T);
	void pop_back();
	T front();
	T operator[](unsigned int index);
	int size() { return m_length; }

private:
	size_t m_size;
	size_t m_length;
	T *m_data;
};

template <typename T>
void Vector<T>::push_back(T data)
{
	if (m_length < m_size)
	{
		m_data[m_length] = data;
	}
}

template <typename T>
void Vector<T>::pop_back()
{
	if (m_length > 0)
		--m_length;
	else
		cout << "\n vector is empty \n";
}

template <typename T>
T Vector<T>::front()
{
	if (m_length > 0)
		return m_data[m_length];
	else
		cout << "\n vector is empty\n";
}

template <typename T>
T Vector<T>::operator[](unsigned int index)
{
	if (index < m_length)
		return m_data[index];
}

int main(void)
{
	Vector<int> iObj;
	for (int i = 1; i <= 10; i++)
		iObj.push_back(i);

	for (int i = 0; i < iObj.size(); i++)
	{
		//		cout<<iObj.front()<<" "<<iObj.pop_back();
	}
	cout << "\n";
	return 0;
}
