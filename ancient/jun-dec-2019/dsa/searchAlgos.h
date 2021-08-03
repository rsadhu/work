#ifndef SEARCHALGOS_H
#define SEARCHALGOS_H
#pragma once

#include <initializer_list>
#include <memory>

constexpr int M = 100;

template<typename U>
class MyNode
{
public:
    MyNode(const U &rhs):data(rhs) {

    }

    virtual ~MyNode()
    {

    }

    U data;
    MyNode<U> *left =  nullptr, *right =  nullptr;
};

enum class SEARCH_TYPE
{
    BINARY_LINEAR_SEARCH_ITER,
    BINARY_LINEAR_SEARCH_RECU,
    //BINARY_TREE_SEARCH_ITER,
    BINARY_TREE_SEARCH_RECU,
};

template<typename T>
class Searching
{
public:
    Searching(const std::initializer_list<T> &rhs, bool dyn=false);
    bool findItem(const T &rhs, SEARCH_TYPE type);
private:
    void createBST(const T &rhs);
protected:
    bool findIterItem(const T &rhs);
    bool findRecItem(const T &rhs);

    // internal functions for other logic
    static bool findBsRec(T *arr, const T &item, int, int);

    // BST functions
    static bool inOrderRec(MyNode<T> *root, const T &rhs);
    static bool inOrderIter(MyNode<T> *root, const T &rhs);
private:
    T m_arr[M];
    int m_index = -1;
    MyNode<T> *m_root = nullptr;
};

template <typename T>
void Searching<T>::createBST(const T &rhs)
{
    //m_root = createBSTRec(rhs, m_root);
    if(m_root==nullptr)
    {
        m_root =  new MyNode<T>(rhs);
    }
    else {
        for(auto it = m_root; it!= nullptr;) {

            if( rhs > it->data ) {
                if(it->right)
                    it = it->right;
                else{
                    it->right = new MyNode<T> (rhs);
                    break;
                }
            }
            else {
                if(it->left)
                    it = it->left;
                else{
                    it->left = new MyNode<T>(rhs);
                    break;
                }
            }
        }
    }
}

template<typename T>
bool Searching<T>::inOrderRec(MyNode<T> *root, const T &rhs)
{
    static bool ret =  false;
    if(root)
    {
        ret |= inOrderRec(root->left, rhs);
        if(root->data == rhs)
            return true;
        ret |= inOrderRec(root->right, rhs);
    }
    return ret;
}

template <typename T>
Searching<T>::Searching(const std::initializer_list<T> &rhs, bool dyn)
{
    if(rhs.size() <= M) {
        for(auto it: rhs)
        {
            if ( dyn )
                m_arr[++m_index] = it;
            else
                createBST(it);
        }
    }
}

template<typename T>
bool Searching<T>::findBsRec(T *arr, const T &item, int start, int end)
{
    if(start <= end) {

        auto mid  =  (start+end)/2;
        if(item > arr[mid])
        {
            findBsRec(arr, item, mid+1, end);
        }
        else if( item < arr[mid])
        {
            findBsRec(arr, item, start, mid-1);
        }
        else {
            return true;
        }
    }
    return false;
}

template<typename T>
bool Searching<T>::findIterItem(const T &rhs)
{
    int start = 0, end = m_index, mid = 0;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if( rhs > m_arr[mid])
        {
            start = mid+1;
        }
        else if( rhs < m_arr[mid])
        {
            end = mid-1;
        }
        else {
            return true;
        }
    }
    return false;
}


template<typename T>
bool Searching<T>::findRecItem(const T &rhs)
{
    return findBsRec(m_arr, rhs, 0, m_index);
}

template<typename T>
bool Searching<T>::findItem(const T &rhs, SEARCH_TYPE type)
{
    bool ret =  false;
    switch(type)
    {
    case SEARCH_TYPE::BINARY_TREE_SEARCH_RECU:
        ret = inOrderRec(m_root, rhs);
        break;
    case SEARCH_TYPE::BINARY_LINEAR_SEARCH_ITER:
        ret = findIterItem(rhs);
        break;
    case SEARCH_TYPE::BINARY_LINEAR_SEARCH_RECU:
        ret = findRecItem(rhs);
        break;
    }

    return ret;
}

#endif
