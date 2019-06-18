#include "linklist.h"


template<typename T>
unsigned int LinkList<T>::size() const
{
 return m_size;
}

template<typename T>
bool LinkList<T>::empty() const
{

}

template<typename T>
T LinkList<T>::value_at(unsigned int index)
{
 return m_root->data;
}

template<typename T>
void LinkList<T>::push_front(T &rhs)
{

}

template<typename T>
T LinkList<T>::pop_front()
{
    return m_root->data;
}

template<typename T>
void LinkList<T>::push_back(T &value)
{

}

template<typename T>
T LinkList<T>::pop_back()
{
    return m_root->data;
}

template<typename T>
T LinkList<T>::front()
{
    return m_root->data;
}

template<typename T>
T LinkList<T>::back()
{
    return m_root->data;
}

template<typename T>
void LinkList<T>::insert(int index, T &rhs)
{

}

template<typename T>
void LinkList<T>::erase(int index)
{

}

template<typename T>
T LinkList<T>::value_n_from_end(int n)
{
    return m_root->data;
}

template<typename T>
void LinkList<T>::reverse()
{

}

template<typename T>
void LinkList<T>::remove_value(T &rhs)
{

}
