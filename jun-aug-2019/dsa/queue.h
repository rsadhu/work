#ifndef QUEUE_H
#define QUEUE_H

/*enqueue(value) - adds value at position at tail
dequeue() - returns value and removes least recently added element (front)
empty()*/

template<typename T>
class Node
{
  public:
    Node(T &rhs):m_data(rhs),m_next(nullptr) {}
    T m_data;
    Node<T> m_next = nullptr;
};

template<typename T>
class QUEUE
{
public:
   void enqueue(const T &rhs);
   T dequeue();
   bool empty();
private:
   Node<T> m_root =  nullptr;
};

#endif // QUEUE_H
