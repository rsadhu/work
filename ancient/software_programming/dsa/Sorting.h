//
// Created by rsadhu on 05.04.20.
//

#ifndef GPREP_SORTINGALGOS_H
#define GPREP_SORTINGALGOS_H

#include <vector>

void bubbleSort(std::vector<int> &list) {
    bool noNeed(true);
    for (uint i = 0; i < list.size(); i++) {
        noNeed = true;
        for (uint j = 0; j < list.size() - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
                noNeed = false;
            }
        }
        if (noNeed)
            break;
    }
}


void selectionSort(std::vector<int> &list) {
    bool noNeed(true);
    for (uint i = 0; i < list.size(); i++) {
        noNeed = true;
        for (uint j = i + 1; j < list.size(); j++) {
            if (list[i] > list[j]) {
                std::swap(list[i], list[j]);
                noNeed = false;
            }
        }
        if (noNeed)
            break;
    }
}

void insertionSort(std::vector<int> &list) {

    for (int i = 1; i < list.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (list[j - 1] > list[j]) {
                std::swap(list[j - 1], list[j]);
            }
        }
    }
}

int partition(std::vector<int> &arr, int low, int high)
{
    int i=low, j = high;
    int piv = arr[i];
    while(i < j)
    {
        do
        {
            i++;
        }while(piv > arr[i] );

        do
        {
            j--;
        }while(piv <  arr[j] );
        if (i < j )
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}

void qsort(std::vector<int> &list, int lo, int hi) {
    if (lo < hi) {
        int p = partition(list, lo, hi);
        qsort(list, lo, p);
        qsort(list, p + 1, hi);
    }
}

void quickSort(std::vector<int> &list) {
    int lo = 0, hi = list.size();
    qsort(list, lo, hi);
}

// make it max heap
void heapify(std::vector<int> &list) {
    for (int i = list.size() - 1; i >= 0; i--) {
        if (list[i] > list[ceil(i / 2)]) {
            std::swap(list[i], list[ceil(i / 2)]);
        }
    }
}

void removeThusSortify(std::vector<int> &list) {
    std::deque<int> tmp;
    for (int i = list.size() - 1; i >= 0;) {
        std::swap(list[0], list[i]);
        tmp.push_front(list[i]);
        list.pop_back();
        heapify(list);
        i = list.size() - 1;
    }
    for (auto it: tmp) {
        list.push_back(it);
    }
}

void heapSort(std::vector<int> &list) {
    auto display = [](std::vector<int> &list) {
        std::cout << "\n";
        for (auto it: list) {
            std::cout << it << "  ";
        }
        std::cout << "\n";
    };

    //display(list);
    heapify(list);
    display(list);

    removeThusSortify(list);
    display(list);
}

void merge(std::vector<int> &arr, int  l , int m , int h)
{
    std::vector<int> arr1, arr2;
    for(int i = 0; i <l;i++)
    {
        arr1.push_back(arr[i]);
    }

    for(int i = m;i < h;i++)
    {
        arr2.push_back(arr[i]);
    }

    int i=0, j=0, k=0;

    while(i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        else
        {
            arr[k++]=arr2[j++];
        }
    }

    while(i < arr1.size())
    {
        arr[k++] = arr1[i++];
    }

    while(j < arr2.size())
    {
        arr[k++]= arr2[j++];
    }
}


void mergeSort(std::vector<int> &arr,int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}




#endif  // GPREP_SORTINGALGOS_H
