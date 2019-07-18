#ifndef Queue_H
#define Queue_H
#pragma once
namespace MyQueue {

template<typename T>
class QueueIntf {
public:
    virtual void enQueue(const T &) = 0;
    virtual T deQueue() = 0;
    virtual bool empty() const = 0;
    virtual bool full() const  { return false;}
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
    T deQueue();
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
T DQueue<T>::deQueue()
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
    T deQueue(void );
    bool empty() const;
    bool full() const;
    ~SQueue(){}
private:
    T m_arr[N];
    int m_front = -1 , m_end = -1;
};

template<typename T>
void SQueue<T>::enQueue(const T &rhs)
{
    if(!full())
    {
        m_arr[++m_end] = rhs;
    }
}

template<typename T>
T SQueue<T>::deQueue(void )
{
    if(!empty())
    {
        return m_arr[++m_front];
    }
    return T();
}

template<typename T>
bool SQueue<T>::empty() const
{
  return m_front == m_end;
}

template<typename T>
bool SQueue<T>::full() const
{
    return m_front == N-1;
}

}






#endif // Queue_H
