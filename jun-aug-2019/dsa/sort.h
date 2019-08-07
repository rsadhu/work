#pragma once
#include <initializer_list>
#include <iostream>

constexpr int NN = 100;
enum class Type
{
    SELECTION,
    INSERTION,
    HEAPSORT,
    QUICKSORT,
    MERGESORT,
    BUBBLESORT
};

template<typename T>
class  Sorter
{
public:
    Sorter(const std::initializer_list<T> &rhs);
    void exec(Type type = Type::QUICKSORT);
    void display();
protected:
    void selection();
    void insertion();
    void mergeSort();
    void quickSort();
    void heapSort();
    void bubbleSort();

    // utility recursive functions
    static void mergeSortRec(T arr, int n);
    static void merge(T arr1, int , T arr2, int );
private:
    T m_arr[NN];
    int m_index = 0;
};

template <typename T>
void Sorter<T>::mergeSortRec(T arr, int n)
{
//    if ( n == 1 )
//        return arr;

//    T arr1[n/2], arr2[n/2];

//    for(int i = 0;i<n;i++)
//    {
//        if(i<n/2)
//        {
//            arr1[i]= arr[i];
//        }
//        else {
//            arr2[i]= arr[i];
//        }
//    }

//    arr1 = mergesort(arr1);
//    arr2 = mergesort(arr2 );
//    return merge(arr1, n/2, arr2, n/2);
}

template <typename T>
void Sorter<T>::merge(T a,int n1, T b,int n2)
{
//    T c[n1+n2];
//    for(int i=0;i<(n1+n2);i++)
//    {
//        if(a[i])
//    }

}

template<typename T>
Sorter<T>::Sorter(const std::initializer_list<T> &rhs)
{
    if(rhs.size() < NN)
    {
        for(auto const &it: rhs)
        {
            m_arr[m_index++] = it;
        }
    }
}


template <typename T>
void Sorter<T>::exec(Type type)
{
    switch (type) {
    case Type::SELECTION:
        selection();
        break;
    case Type::INSERTION:
        break;
    case Type::MERGESORT:
        mergeSort();
        break;
    case Type::QUICKSORT:
        break;
    case Type::HEAPSORT:
        break;
    case Type::BUBBLESORT:
        bubbleSort();
        break;
    default:
        std::cout<<"\n Wrong Sorting Method Choosen\n";
        break;
    }
}

template <typename T>
void Sorter<T>::display()
{
    for(int i=0;i<m_index;i++)
    {
        std::cout<<m_arr[i]<<"  ";
    }
}

template <typename T>
void Sorter<T>::bubbleSort()
{
    auto flag = false;
    for(int i=0;i<m_index;i++)
    {
        for(int j = 0; j < (m_index-i-1);j++)
        {
            if(m_arr[j] > m_arr[j+1])
            {
                auto tmp = m_arr[j];
                m_arr[j] =  m_arr[j+1];
                m_arr[j+1]= tmp;
            }
        }
    }
}

// Time-Complexity O(n2)
template <typename T>
void Sorter<T>::selection()
{
    for(int i = 0; i < m_index; i++)
    {
        for(int j = i+1 ; j < m_index - 1 ; j++)
        {
            if(m_arr[i] > m_arr[j]){
                auto tmp  = m_arr[i];
                m_arr[i] =  m_arr[j];
                m_arr[j] = tmp;
            }
        }
    }
}

template <typename T>
void Sorter<T>::insertion()
{

}

template <typename T>
void Sorter<T>::mergeSort()
{
   // mergeSortRec(m_arr, m_index);
}

template <typename T>
void Sorter<T>::quickSort()
{

}

template <typename T>
void Sorter<T>::heapSort()
{

}
