#include <iostream>
#include <list>

template <typename T>
class Stack
{
public:
    void push(T d) { __data.push_back(d); }

    T pop()
    {
        auto d = __data.front();
        __data.pop_back();
    }

    bool empty() { return __data.empty(); }

    uint size() { return __data.size(); }

private:
    std::list<T> __data;
};
