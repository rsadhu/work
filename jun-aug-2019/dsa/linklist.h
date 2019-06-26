#ifndef LINKLIST_H
#define LINKLIST_H
#pragma once
#include <initializer_list>
#include <iostream>

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

    void display();

    unsigned int size() const;
    bool empty() const;
    T value_at(unsigned int index);
    void push_front(const T &rhs);
    T pop_front();
    void push_back(const T &value);
    T pop_back();
    T front();
    T back();
    void insert(int index, const T &rhs);
    void erase(int index);
    T value_n_from_end(int n);
    void reverse();
    void remove_value(const T &rhs);
    void removeAllSentItems(const T &rhs);
private:
    Node<T> *m_root=nullptr;
    unsigned int  m_size = 0;
};

//#include "linklist.h"


template<typename T>
unsigned int LinkList<T>::size() const
{
    return m_size;
}

template<typename T>
bool LinkList<T>::empty() const
{
    return m_size == 0;
}

template<typename T>
T LinkList<T>::value_at(unsigned int index)
{
    if ( index >= 1 && index <= m_size )
    {
        int cnt = 1;
        Node<T> *tmp = m_root;
        while(tmp)
        {
            if(index == cnt)
            {
                return tmp->data;
            }
            tmp =  tmp->next;
            cnt++;
        }
    }
}

template<typename T>
void LinkList<T>::push_front(const T &rhs)
{
    Node<T> *tmp = new Node<int> (rhs);
    tmp->next = m_root;
    m_root =  tmp;
    m_size++;
}

template<typename T>
T LinkList<T>::pop_front()
{
    Node<int> *tmp = nullptr;
    if(m_root)
    {
        tmp = m_root;
        m_root =  m_root->next;
    }
    m_size--;
    auto ret = tmp->data;
    delete tmp;
    return ret;
}

template<typename T>
void LinkList<T>::push_back(const T &value)
{
    if (m_root){
        Node<int> *tmp  = nullptr;
        for(tmp =  m_root; tmp->next; tmp = tmp->next);

        tmp->next = new Node<int>(value);
        m_size++;
    }
    else {
        push_front(value);
    }
}

template<typename T>
T LinkList<T>::pop_back()
{
    Node<int> *tmp  = m_root, *prev = tmp;
    for(; tmp->next; prev= tmp,tmp = tmp->next);
    prev->next = nullptr;
    delete tmp;
    m_size--;
}

template<typename T>
T LinkList<T>::front()
{
    return m_root ? m_root->data : T();
}

template<typename T>
T LinkList<T>::back()
{
    Node<int> *tmp  = nullptr;
    for(tmp =  m_root; tmp->next; tmp = tmp->next);

    if(tmp)
        return tmp->data;
    else {
        return T();
    }
}

template<typename T>
void LinkList<T>::insert(int index, const T &rhs)
{
    if(index == 1)
        push_front(rhs);
    else {
        auto cnt = 0;
        for(auto prev = m_root, cur = m_root->next;cur->next;prev =  cur,cur = cur->next)
        {
            cnt++;
            if(cnt==index)
            {
                prev->next = new Node<int> (rhs);
                prev->next->next = cur;
                break;
            }
        }
        m_size++;
    }
}

template<typename T>
void LinkList<T>::erase(int index)
{
    if(index == 1)
        pop_front();
    else {
        auto cnt = 0;
        for(auto prev = m_root, cur = m_root->next;cur->next;prev =  cur,cur = cur->next)
        {
            cnt++;
            if(cnt==index)
            {
                auto tmp = cur;
                prev->next = cur->next;
                delete tmp;
                break;
            }
        }
        m_size--;
    }
}

template<typename T>
T LinkList<T>::value_n_from_end(int n)
{
    auto index =  m_size - n;
    return value_at(index);
}

template<typename T>
void LinkList<T>::reverse()
{
    if(!m_root)
        return;

    Node<T> *cur =  m_root->next, *prev = m_root, *tmp = nullptr;
    while(cur)
    {
        prev->next = tmp;
        tmp =  prev;
        prev = cur;
        cur = cur->next;
    }

    prev->next=tmp;
    m_root = prev;
}

template<typename T>
void LinkList<T>::remove_value(const T &rhs)
{
    if (m_root) {
        if (rhs == m_root->data) {
            pop_front();
        }
        else {
            for (auto prev = m_root, cur = m_root->next;cur->next;prev =  cur,cur = cur->next) {
                if (cur->data == rhs) {
                    auto tmp = cur;
                    prev->next = cur->next;
                    delete tmp;
                    break;
                }
            }
        }
        m_size--;
    }
}


template<typename T>
void LinkList<T>::display()
{
    std::cout<<"\n";

    for(auto tmp = m_root;tmp;tmp = tmp->next)
        std::cout<< tmp->data <<" ";

    std::cout<<"\n";
}

template<typename T>
void LinkList<T>::removeAllSentItems(const T &rhs)
{
    for(Node<T>* prev = nullptr, *cur = m_root; cur; cur=cur->next)
    {
        if(cur->data == rhs)
        {
            if(prev==nullptr)
            {
                m_root = cur->next;
                Node<T> *tmp  = cur;
                delete tmp;
            }
            else{
                //prev = cur;
                prev->next = cur->next;
                delete cur;
            }
            m_size--;
        }
        else {
            prev = cur;
        }
    }
}



#endif // LINKLIST_H
