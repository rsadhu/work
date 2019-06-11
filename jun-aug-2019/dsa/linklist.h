#ifndef LINKLIST_H
#define LINKLIST_H
#pragma once

template<typename T>
class Node
{
public:
    Node(const T&rhs):data(rhs),next(nullptr){}
    T data;
    T *next;
};

template <typename T>
class LinkList
{
private:
    Node<T> m_data;
};

#endif // LINKLIST_H
