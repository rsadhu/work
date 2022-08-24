//
// Created by rsadhu on 18.03.20.
//

#ifndef GPREP_LINKLIST_H
#define GPREP_LINKLIST_H
#pragma once

#include <memory>
#include <stack>

template <typename T>
struct Node
{
    Node(T &d) : __data(d) {}

    T __data;
    Node *__next = nullptr;
};

template <typename T>
class LinkList
{
public:
    LinkList &operator<(T d);

    void display();

    uint size() const { return __size; }

    bool empty() const { return __size == 0; }

    T value_at(int index);

    void push_front(T value);

    T pop_front();

    void push_back(T value);

    T pop_back();

    T front() const;

    T back() const;

    void insert(int index, T value);

    void erase(int index);

    T value_n_from_end(int n);

    void reverse();

    void remove_value(T value);

private:
    void valueRec(Node<T> *, int &, int &);

    T valueIter(Node<T> *, int);

    Node<T> *__root = nullptr;
    uint __size = 0;
};

template <typename T>
T LinkList<T>::front() const
{
    return __root ? __root->__data : -1;
}

template <typename T>
T LinkList<T>::back() const
{
    if (__root)
    {
        Node<T> *tmp = __root;
        while (tmp->__next)
        {
            tmp = tmp->__next;
        }
        return tmp->__data;
    }
    return -1;
}

template <typename T>
void LinkList<T>::insert(int index, T value)
{
    if (index == 0)
    {
        Node<T> *tmp = new Node<T>(value);
        tmp->__next = __root;
        __root = tmp;
    }
    else
    {
        Node<T> *prev, *cur = __root;
        if (cur)
        {
            prev = cur;
            cur = cur->__next;
            int i = 1;
            while (cur)
            {
                if (index == i)
                {
                    Node<T> *tmp = new Node<T>(value);
                    tmp->__next = cur;
                    prev->__next = tmp;
                    break;
                }
                i++;
                prev = cur;
                cur = cur->__next;
            }
        }
    }
}

template <typename T>
void LinkList<T>::erase(int index)
{
    if (!__root)
        return;
    if (index == 0)
    {
        auto tmp = __root;
        __root = __root->__next;
        delete tmp;
    }
    else
    {
        Node<T> *prev, *cur = __root;
        if (cur)
        {
            prev = cur;
            cur = cur->__next;
            int i = 1;
            while (cur)
            {
                if (index == i)
                {
                    prev->__next = cur->__next;
                    delete cur;
                    break;
                }
                i++;
                prev = cur;
                cur = cur->__next;
            }
        }
    }
}

template <typename T>
T LinkList<T>::valueIter(Node<T> *root, int n)
{
    std::stack<T> st;
    while (root)
    {
        st.push(root->__data);
        root = root->__next;
    }

    if (!st.empty())
    {
        while (n--)
        {
            st.pop();
        }
        return st.top();
    }
    return T();
}

template <typename T>
void LinkList<T>::valueRec(Node<T> *root, int &cnt, int &value)
{
    if (root)
    {
        valueRec(root->__next, cnt, value);
        if (0 == cnt--)
            value = root->__data;
    }
}

template <typename T>
T LinkList<T>::value_n_from_end(int n)
{
    T val;
    // valueRec(__root, n, val);
    val = valueIter(__root, n);
    return val;
}

template <typename T>
void LinkList<T>::reverse()
{
    Node<T> *cur = __root, *prev, *tmp = nullptr;
    while (cur)
    {
        prev = cur;
        tmp = cur->__next;
        cur->__next = prev;
        cur = tmp;
    }
    __root = prev;
}

template <typename T>
void LinkList<T>::remove_value(T value)
{
    if (!__root)
        return;
    Node<T> *prev, *cur = __root;
    prev = cur;
    cur = cur->__next;
    if (value == prev->__data)
    {
        __root = __root->__next;
        delete prev;
    }
    else
    {
        while (cur->next)
        {
            if (cur->__data == value)
            {
                prev->__next = cur->__next;
                delete cur;
                break;
            }
            prev = cur;
            cur = cur->__next;
        }
    }
}

template <typename T>
void LinkList<T>::push_front(T value)
{
    Node<T> *tmp = new Node<T>(value);
    tmp->__next = __root;
    __root = tmp;
}

template <typename T>
T LinkList<T>::pop_front()
{
    if (__root)
    {
        Node<T> *tmp = __root->__data;
        __root = __root->__next;
        auto d = tmp->__data;
        delete tmp;
        return d;
    }
    return -1;
}

template <typename T>
void LinkList<T>::push_back(T value)
{
    Node<T> *it;
    for (it = __root; it->__next; it = it->__next)
        ;
    it->__next = new Node<T>(value);
}

template <typename T>
T LinkList<T>::pop_back()
{
    Node<T> *cur, *prev = __root;
    int d = -1;
    if (prev)
    {
        cur = prev->__next;
        if (cur)
        {
            while (cur->__next)
            {
                prev = cur;
                cur = cur->__next;
            }
            d = cur->__data;
            delete cur;
            prev->__next = nullptr;
        }
        else
        {
            d = prev->__data;
            delete prev;
            __root = nullptr;
        }
    }
    return d;
}

template <typename T>
T LinkList<T>::value_at(int index)
{
    int i = 0;
    for (auto it = __root; it; it = it->__next)
    {
        if (index == i++)
            return new Node<T>(it->__data);
    }
    return nullptr;
}

template <typename T>
LinkList<T> &LinkList<T>::operator<(T d)
{
    __size++;
    if (!__root)
    {
        __root = new Node<T>(d);
    }
    else
    {
        Node<T> *tra;
        for (tra = __root; tra->__next; tra = tra->__next)
            ;
        tra->__next = new Node<T>(d);
    }

    return *this;
}

template <typename T>
void LinkList<T>::display()
{
    std::cout << "\n";
    for (auto it = __root; it; it = it->__next)
        std::cout << " " << it->__data;
    std::cout << "\n";
}

#endif // GPREP_LINKLIST_H
