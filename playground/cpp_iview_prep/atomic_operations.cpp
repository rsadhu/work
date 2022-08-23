#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <deque>
#include <initializer_list>
#include <exception>
#include <vector>

constexpr size_t SIZE = 100;

class List
{
    int m_arr[SIZE];
    int m_index = -1;

public:
    List(const List &) = delete;
    List(List &&) = delete;
    List operator=(const List &) = delete;
    List operator=(List &&) = delete;

    List() = default;
    List(std::initializer_list<int> rhs)
    {
        for (auto item : rhs)
        {
            this->add(item);
        }
    }

    void add(int d)
    {
        m_index = (m_index++) % SIZE;
        m_arr[m_index] = d;
    }

    bool empty()
    {
        return m_index == -1;
    }
    int get()
    {
        if (m_index > 0)
            return m_arr[m_index--];
        else
            throw std::runtime_error("out of bound error");
    }
};

std::atomic<List> list;
List l;

void runner(void)
{
    int val = 0;
    while (val > 0)
    {
        auto cont = list.load();
        val = cont.get();
        std::cout << val;
    }
}

int main(void)
{

    // List d{1, 2, 3};
    std::thread th(runner);
    std::vector<int> input(100, random());
    int i = 0;
    while (i < input.size())
    {
        // list.store({1, 2, 3});
        list.store({input[i++]});
    }
    th.join();
    return 0;
}