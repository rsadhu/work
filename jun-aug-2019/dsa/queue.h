#ifndef Queue_H
#define Queue_H
#pragma once
namespace MyQueue {
template<typename T>
class Node
{
public:
    Node(const T &rhs):data(rhs),next(nullptr) {}
    T data;
    Node<T> *next = nullptr;
};

template<typename T>
class Queue
{
public:
    void enQueue(const T &rhs);
    T deQueue();
    bool empty();
private:
    Node<T> *m_root =  nullptr, *m_tail= nullptr;
};

template<typename T>
void Queue<T>::enQueue(const T &rhs)
{
    if (m_root == nullptr) {
        m_root = new Node<T>(rhs);
        m_tail = m_root;
    }
    else {
        auto it = m_root;
        for(;it->next;it =  it->next);
        it->next = new Node<T>(rhs);
        m_tail =  it->next;
    }
}

template<typename T>
T Queue<T>::deQueue()
{
    if (empty())
        return T() ;

    if(m_root == nullptr)
    {
        auto d =  m_root->data;
        delete m_root;
        m_root =  nullptr;

        delete m_tail;
        m_tail =  nullptr;
        return  d;
    }

    Node<T> *cur = m_root, *prev = cur;

    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }

    m_tail = prev;
    auto val = cur->data;
    delete cur;
    prev->next = nullptr;
    return val;
}

template<typename T>
bool Queue<T>::empty()
{
    return m_root == nullptr;
}
}

#endif // Queue_H
