#include <algorithm>
#include <iostream>
#include <vector>

class Searching {
public:
    Searching &operator<(int d);

    bool search(int item) {
        std::sort(__data.begin(), __data.end());
        return searchIter(__data, item) &&
               searchRec(__data, 0, __data.size() - 1, item);
    }

    void display() {
        for (auto it : __data) {
            std::cout << it << " ";
        }
    }

private:
    bool searchRec(std::vector<int> &arr, int start, int end, int item);

    bool searchIter(std::vector<int> &arr, int item);

    std::vector<int> __data;
};

Searching &Searching::operator<(int d) {
    __data.push_back(d);
    return *this;
}

bool Searching::searchRec(std::vector<int> &arr, int start, int end, int item) {
    if (start <= end) {
        auto mid = (start + end) / 2;
        if (item < arr[mid])
            searchRec(arr, start, mid, item);
        else if (item > arr[mid])
            searchRec(arr, mid + 1, end, item);
        else if (item == arr[mid])
            return true;
        else
            return false;
    } else
        return false;
}

bool Searching::searchIter(std::vector<int> &arr, int item) {
    bool ret(false);
    int end = arr.size() - 1;
    int start = 0;
    while (start <= end) {
        auto mid = (start + end) / 2;
        if (item < arr[mid]) {
            end = mid;
        } else if (item > arr[mid]) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return ret;
}