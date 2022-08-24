#include <cmath>
#include <iostream>
#include <vector>

class SegmentTree
{
public:
    SegmentTree(std::vector<int> &rlist);
    int getMin(int low, int high);

private:
    size_t generateSize(size_t sz);
    bool isPowerOfTwo(size_t sz);
    size_t nextPowerOfTwo(size_t sz);
    void constructSegmentTree(std::vector<int> &list, int beg, int end, int pos);
    int query(int qbeg, int qend, int beg, int end, int pos);

    std::vector<int> arr_;
    size_t size_;
};

int SegmentTree::query(int qbeg, int qend, int beg, int end, int pos)
{
    if (qbeg <= beg && qend >= end)
        return arr_[pos];
    //    if (qbeg < beg && qend > end)
    if (qbeg > end || qend < beg)
        return INT_MIN;

    int mid = (beg + end) / 2;

    return std::max(query(qbeg, qend, beg, mid, 2 * pos + 1),
                    query(qbeg, qend, mid + 1, end, 2 * pos + 2));
}

void SegmentTree::constructSegmentTree(std::vector<int> &list, int beg, int end, int pos)
{
    if (beg == end)
    {
        arr_[pos] = list[beg];
        return;
    }

    auto mid = (beg + end) / 2;
    constructSegmentTree(list, beg, mid, pos * 2 + 1);
    constructSegmentTree(list, mid + 1, end, pos * 2 + 2);
    arr_[pos] = std::max(arr_[2 * pos + 1], arr_[2 * pos + 2]);
}

// if n is power of 2
bool SegmentTree::isPowerOfTwo(size_t n)
{
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            return false;
        }
    }
    return true;
}

size_t SegmentTree::nextPowerOfTwo(size_t n)
{
    size_t m = 2;
    while (m <= n)
    {
        m = m << 1;
    }
    return m;
}

size_t SegmentTree::generateSize(size_t sz)
{
    size_t new_size = 0;
    if (isPowerOfTwo(sz))
    {
        std::cout << "yes it is power of 2\n";
        new_size = sz * 2 - 1;
    }
    else
    {
        size_t m = nextPowerOfTwo(sz);
        std::cout << " nein es ist nicht power von 2   " << m << "\n";
        new_size = m * 2 - 1;
    }
    return new_size;
}

SegmentTree::SegmentTree(std::vector<int> &list)
{
    if (list.size() > 0)
    {
        size_t sz = generateSize(list.size());
        std::cout << " the size of segment tree would be " << sz << "\n";
        arr_.resize(sz, INT_MAX);

        size_ = list.size();

        constructSegmentTree(list, 0, list.size() - 1, 0);
    }
}

int SegmentTree::getMin(int l, int h)
{
    return query(l, h, 0, size_, 0);
}

int main(int argc, char *argv[])
{
    std::cout << "\n Start the Segment \n";
    std::vector<int> arr{-1, 2, 4, 0, -100, 9, -200, 300, 8, 1, 500, 6};
    SegmentTree st = arr;
    int l = 0, h = 10;

    if (argc == 3)
    {
        l = std::stoi(argv[1]);
        h = std::stoi(argv[2]);
    }

    if (l >= 0 && h <= arr.size() - 1)
        std::cout << "\n min is   " << st.getMin(l, h) << "\n";
    else
        std::cout << " \n range is wrong\n";
    return 0;
}