#ifndef LIST_H
#define LIST_H

#include<exception>
#include<string>

template<typename T>

class Node
{
public:
    Node(T d): data(d), left(nullptr),right(nullptr){}
    Node *right=nullptr,*left=nullptr;
    T data;
};


template<typename T>
class List
{
public:
    List(){}
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    int length();
    T front();
    T back();

    //    T operator *();
    //    T & operator &();
    //    void operator ++();
    //    bool operator !=();
    //    bool operator ==();
    List begin();
    List end();

private:
    Node<T> *m_root=nullptr;
};


//template<typename T>
//T List<T>::operator *()
//{
////    if(m_root)
////        return m_root->data;
////    else

//}

//template<typename T>
//List & List<T>::operator &()
//{

//}

//template<typename T>
//void List<T>:: operator ++()
//{

//}

//template<typename T>
//bool List<T>::operator !=()
//{

//}

//template<typename T>
//bool List<T>::operator ==()
//{

//}

template<typename T>
List<T> List<T>::begin()
{

}

template<typename T>
List<T> List<T>::end()
{

}



template<typename T>
void List<T>::push_back(T d)
{
    Node <T> *tmp =  new Node<T>(d);
    if(m_root)
    {
        Node<T> *tra =  m_root;
        for(;tra->right;tra =  tra->right);
        tra->right =  tmp;
        tmp->left  = tra;
    }
    else
    {
        m_root =  tmp;
    }
}


template<typename T>
void List<T>::push_front(T d)
{
    Node <T> *tmp =  new Node<T>(d);
    if(m_root)
    {
        tmp->right = m_root;
        m_root->left =  tmp;
        m_root =  tmp;
    }
    else
    {
        m_root =  tmp;
    }
}


template<typename T>
void List<T>::pop_back()
{
    Node<T> *tra =  m_root,*prev;
    if(tra)
    {
        while(tra->right)
        {
            prev = tra;
            tra =  tra->right;
        }

        if(tra)
        {
            delete tra;
            prev->right =  nullptr;
        }
    }
    else
    {
        throw new std::exception();
    }
}


template<typename T>
void List<T>::pop_front()
{
    if(m_root)
    {
        Node<T> *tra =  m_root;
        m_root = tra->right;
        delete tra;
    }
    else
    {
        throw new std::exception();
    }
}


template<typename T>
int List<T>::length()
{
    int len = 0;
    for(Node<T> *tra =  m_root;tra->right;tra=tra->right,len++);
    return len;
}


template<typename T>
T List<T>::front()
{
    if(m_root)
        return m_root->data;
    else
        throw new std::exception();
}


template<typename T>
T List<T>::back()
{
    if(m_root)
    {
        Node<T> *tra =  m_root;

        while(tra->right)
        {
            tra =  tra->right;
        }
        return tra->data;
    }
    else
    {
        throw new std::exception();
    }
}



#endif // LIST_H
