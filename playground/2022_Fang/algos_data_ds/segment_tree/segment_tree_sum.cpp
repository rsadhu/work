#include <cmath>
#include <iostream>
#include <vector>

class SegmentTree {
public:
    SegmentTree(std::vector<int>& rlist);
    int getSum(int low, int high);
    void update(int index, int value)
    {
        update(0, size_ - 1, 0, index, value);
    }

private:
    size_t generateSize(size_t sz);
    bool isPowerOfTwo(size_t sz);
    size_t nextPowerOfTwo(size_t sz);
    void constructSegmentTree(std::vector<int>& list, int beg, int end, int pos);
    int query(int qbeg, int qend, int beg, int end, int pos);
    void update(int beg, int end, int pos, int index, int val);

    std::vector<int> arr_;
    size_t size_;
};

void SegmentTree::update(int beg, int end, int pos, int index, int val)
{
    if (beg == end) {
        arr_[pos] = val;
        return;
    }
    int mid = (beg + end) / 2;
    if (mid >= index) {
        update(beg, mid, 2 * pos + 1, index, val);
    } else {
        update(mid + 1, end, 2 * pos + 2, index, val);
    }
    arr_[pos] = arr_[2 * pos + 1] + arr_[2 * pos + 2];
}

int SegmentTree::query(int qbeg, int qend, int beg, int end, int pos)
{
    if (qbeg <= beg && qend >= end)
        return arr_[pos];
    //    if (qbeg < beg && qend > end)
    if (qbeg > end || qend < beg)
        return 0;

    int mid = (beg + end) / 2;

    return query(qbeg, qend, beg, mid, 2 * pos + 1) + query(qbeg, qend, mid + 1, end, 2 * pos + 2);
}

void SegmentTree::constructSegmentTree(std::vector<int>& list, int beg, int end, int pos)
{
    if (beg == end) {
        arr_[pos] = list[beg];
        return;
    }

    auto mid = (beg + end) / 2;
    constructSegmentTree(list, beg, mid, pos * 2 + 1);
    constructSegmentTree(list, mid + 1, end, pos * 2 + 2);
    arr_[pos] = arr_[2 * pos + 1] + arr_[2 * pos + 2];
}

// if n is power of 2
bool SegmentTree::isPowerOfTwo(size_t n)
{
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            return false;
        }
    }
    return true;
}

size_t SegmentTree::nextPowerOfTwo(size_t n)
{
    size_t m = 2;
    while (m <= n) {
        m = m << 1;
    }
    return m;
}

size_t SegmentTree::generateSize(size_t sz)
{
    size_t new_size = 0;
    if (isPowerOfTwo(sz)) {
        std::cout << "yes it is power of 2\n";
        new_size = sz * 2 - 1;
    } else {
        size_t m = nextPowerOfTwo(sz);
        std::cout << " nein es ist nicht power von 2   " << m << "\n";
        new_size = m * 2 - 1;
    }
    return new_size;
}

SegmentTree::SegmentTree(std::vector<int>& list)
{
    if (list.size() > 0) {
        size_t sz = generateSize(list.size());
        std::cout << " the size of segment tree would be " << sz << "\n";
        arr_.resize(sz, 0);

        size_ = list.size();

        constructSegmentTree(list, 0, list.size() - 1, 0);
    }
}

int SegmentTree::getSum(int l, int h)
{
    return query(l, h, 0, size_, 0);
}

int main(int argc, char* argv[])
{
    std::cout << "\n Start the Segment \n";
    std::vector<int> arr { 1, 2, 4, 0, -100, 9, -200, 300, 8, 1, 500, 6 };
    SegmentTree st = arr;
    int l = 0, h = 6;

    if (argc == 3) {
        l = std::stoi(argv[1]);
        h = std::stoi(argv[2]);
    }

    if (l >= 0 && h <= arr.size() - 1) {
        std::cout << "\n sum is   " << st.getSum(l, h) << "\n";
        st.update(0, 1);
    } else {
        std::cout << " \n range is wrong\n";
    }
    return 0;
}