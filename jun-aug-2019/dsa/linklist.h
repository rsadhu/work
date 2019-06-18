#ifndef LINKLIST_H
#define LINKLIST_H
#pragma once
#include <initializer_list>

template<typename U>
class Node
{
public:
    Node(){}
    Node(const U&rhs):data(rhs)
    {

    }

    U data;
    Node<U> *next = nullptr;
};

template <typename T>
class LinkList
{
public:
    LinkList() {

    }

    LinkList(const std::initializer_list<int> &rhs) {
        for(auto it: rhs)
        {
            //push_back(it);
        }
    }

    ~LinkList()
    {
        while(m_root)
        {
            auto tmp = m_root;
            m_root =  m_root->next;
            delete tmp;
        }
    }

    unsigned int size() const;
    bool empty() const;
    T value_at(unsigned int index);
    void push_front(T &rhs);
    T pop_front();
    void push_back(T &value);
    T pop_back();
    T front();
    T back();
    void insert(int index, T &rhs);
    void erase(int index);
    T value_n_from_end(int n);
    void reverse();
    void remove_value(T &rhs);
private:
    Node<T> *m_root=nullptr;
    unsigned int  m_size;
};

#endif // LINKLIST_H
