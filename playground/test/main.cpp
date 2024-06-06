#include <functional>

#include <vector>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the class 'xcallable' below.
 */
class xcallable
{
    int count_ = 0;
    int x_ = 0;
    int data_ = 0;

public:
    xcallable(int x) : x_(x)
    {
    }

    xcallable(const xcallable &rhs) = delete;
    xcallable(xcallable &rhs)
    {
        this->x_ = rhs.x_;
        this->data_ = rhs.data_;
    }

    xcallable &operator()(int a)
    {
        if (this->count_ >= this->x_)
        {
            throw -1;
        }
        this->count_++;
        data_ += a;
        return *this;
    }

    int get_sum() const
    {
        return data_;
    }
};

vector<int> get_result(int x, vector<int> arr)
{
    xcallable obj(x);
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        try
        {
            obj = obj(num);
            res.push_back(obj.get_sum());
        }
        catch (int e)
        {
            assert(i + 1 > x);
            assert(e == -1);
            res.push_back(obj.get_sum());
            continue;
        }
        assert(i + 1 <= x);
    }
    return res;
}

int main()
{

    std::vector<int> arr{1, 3, 7, 1};
    vector<int> result = get_result(3, arr);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    return 0;
}
