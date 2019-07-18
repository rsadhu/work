#pragma once
#include <initializer_list>
#include <utility>
#include <algorithm>

constexpr int N = 2;

template<typename T>
class MyVector
{
public:
    MyVector();
    MyVector(const std::initializer_list<T> & rhs);
    void push(const T &rhs);
    void prepend(const T&);
    void insert(const int index, const T &item);
    void remove(const T &item);
    void delIndex(const int index);
    int find(const T &item);
    T at(const int index);
    T pop();
    const bool is_empty();
    const int size();
    const int capacity();
private:
    void resize(bool increase=true);
    T *m_arr=nullptr;
    int m_index = -1;
    size_t m_size = 0;
    size_t m_capacity = N;
};

template<typename T>
MyVector<T>::MyVector()
{
    m_arr = new T[m_capacity]();
}

template<typename T>
MyVector<T>::MyVector(const std::initializer_list<T> & rhs)
{
    if(m_capacity < rhs.size())
        m_capacity = rhs.size();

    if (!m_arr) {
        m_arr =  new T[m_capacity]();
    }

    for (auto it: rhs)
    {
        m_arr[++m_index] = it;
        m_size++;
    }
}

template<typename T>
void MyVector<T>::push(const T &rhs)
{
    if (m_size <= m_capacity)
    {
        m_arr[++m_index] = rhs;
        m_size++;
    }
    else {
        resize();
        push(rhs);
    }
}

template<typename T>
void MyVector<T>::prepend(const T& rhs)
{
    if (m_capacity == m_size) {
        resize();
    }

    for (int i = m_index; i >= 0; i--)
        m_arr[i+1] = m_arr[i];

    m_arr[0] = rhs;
    m_size++;
    m_index++;
}

template<typename T>
void MyVector<T>::insert(const int index, const T &item)
{
    if (index < 0 )
        return ;

    if (index == 0)
    {
        prepend(item);
    }
    else if (index == m_index)
    {
        push(item);
    }
    else {
        for(int i =  m_index ; i >= index ; i--)
            m_arr[i+1] =  m_arr[i];
        m_arr[index] =  item;

        m_index++;
        m_size++;
    }
}

template<typename T>
void MyVector<T>::remove(const T &item)
{
    for(int i = 0; i < m_size; i++)
    {
        if(m_arr[i] == item)
        {
            delIndex(i);
            break;
        }
    }
}

template<typename T>
void MyVector<T>::delIndex(const int index)
{
    if (index < 0 || index > m_index)
        return ;

    for(int i = 0; i < m_index; i++)
    {
        if( i == index)
        {
            for(int j = i ; j < m_index ;j++)
                m_arr[j] = m_arr[j+1];
            m_size--;
            m_index--;
        }
    }
}

template<typename T>
int MyVector<T>::find(const T &item)
{
    for (int i = 0; i < m_index; i++)
    {
        if (m_arr[i] == item)
            return i;
    }
    return -1;
}

template<typename T>
T MyVector<T>::at(const int index)
{
    if ( index >=0 && index <= m_index)
    {
        return m_arr[index];
    }
    return T(0);
}

template<typename T>
T MyVector<T>::pop()
{
    m_size--;
    return m_arr[m_index--];
}

template<typename T>
const bool MyVector<T>::is_empty()
{
    return m_size == 0;
}

template<typename T>
const int MyVector<T>::size()
{
    return m_size;
}

template<typename T>
const int MyVector<T>::capacity()
{
    return m_capacity;
}

template<typename T>
void MyVector<T>::resize(bool increase)
{
    if(increase)
        m_capacity = 2* m_capacity;

    T *tmp = m_arr;

    m_arr =  new T[m_capacity]();

    std::copy(tmp, tmp + m_size, m_arr);
//    for(int i=0;i<m_size;i++)
//        m_arr[i] = tmp[i];
    delete []tmp;
}
