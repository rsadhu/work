#ifndef Queue_H
#define Queue_H
#pragma once
namespace MyQueue {
/*enqueue(value) - adds item at end of available storage
dequeue() - returns value and removes least recently added element
empty()
full()*/

template<typename T>
class QueueIntf {
public:
    virtual void enQueue(const T &) = 0;
    virtual T deQueue() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const  {}
    virtual ~QueueIntf(){}
};

template<typename T>
class Node
{
public:
    Node(const T &rhs):data(rhs),next(nullptr) {}
    T data;
    Node<T> *next = nullptr;
};

template<typename T>
class DQueue: public QueueIntf<T>
{
public:
    void enQueue(const T &rhs);
    T deQueue() const;
    bool empty() const;
    ~DQueue(){}

private:
    Node<T> *m_root =  nullptr, *m_tail= nullptr;
};

template<typename T>
void DQueue<T>::enQueue(const T &rhs)
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
T DQueue<T>::deQueue() const
{
    if (empty()){
        m_tail = nullptr;
        return T() ;
    }

    auto d =  m_root->data;
    auto tmp = m_root;
    m_root =  m_root->next;
    delete tmp;
    return d;
}

template<typename T>
bool DQueue<T>::empty() const
{
    return m_root == nullptr;
}

constexpr int N = 10;
template<typename T>
class SQueue : public QueueIntf<T>
{
 public:
    void enQueue(const T &rhs);
    T deQueue(void )const;
    bool empty() const;
    bool full() const;
    ~SQueue(){}
private:
    T m_arr[N];
    mutable int m_index = -1;
};

template<typename T>
void SQueue<T>::enQueue(const T &rhs)
{
    if(!full())
    {
        m_arr[++m_index] = rhs;
    }
}

template<typename T>
T SQueue<T>::deQueue(void )const
{
    if(!empty())
    {
        return m_arr[m_index--];
    }
    return T();
}

template<typename T>
bool SQueue<T>::empty() const
{
  return m_index == -1;
}

template<typename T>
bool SQueue<T>::full() const
{
    return m_index == N-1;
}

}






#endif // Queue_H
