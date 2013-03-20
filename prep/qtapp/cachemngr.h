#ifndef CACHEMNGR_H
#define CACHEMNGR_H

template<typename T>
class Node
{
public:
    Node(T *);
    Node *left,*right;
    T *data;
};


template<typename T>
class Cache
{
    Cache();
    Cache(const Cache &);
    Cache &operator=(const Cache&);
public:
    static Cache *  getCache(){ if(!m_obj) m_obj =  new Cache(); return m_obj;}
    void add(Node<T> *);
    void remove(Node<T> *);
    bool find(Node<T> *);
    static Cache *m_obj;
};

template<typename T>
Cache<T> *Cache<T>::m_obj;

#endif // CACHEMNGR_H
