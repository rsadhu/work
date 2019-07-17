#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#pragma once
#include<initializer_list>

constexpr int M = 100;

template<typename T>
class Searching
{
public:
    Searching(const std::initializer_list<T> &rhs)
    {
        if(rhs.size() <= M) {
            for(auto it: rhs)
            {
                m_arr[++m_index] = it;
            }
        }
    }

    //void heapSort(const T &rhs);
    //void bst(const T &rhs);
    bool findIterItem(const T &rhs);
    bool findRecItem(const T &rhs);
    static bool findBsRec(T *arr, const T &item, int, int);
private:
    T m_arr[M];
    int m_index = -1;
};


template<typename T>
bool Searching<T>::findBsRec(T *arr, const T &item, int start, int end)
{
    if(start > end){
        return false;
    }
    else {
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

#endif
