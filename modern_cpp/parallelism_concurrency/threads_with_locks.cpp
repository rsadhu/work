#include <functional>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>

using namespace std::chrono_literals;
class Stack
{
    Stack(const Stack &);
    Stack(Stack &&);
    Stack &operator=(const Stack &);
    Stack operator=(Stack &&);

public:
    Stack(int size)
    {
        mu.lock();
        std::cout << std::this_thread::get_id() << " Stack (int size) called\n";
        data.reserve(size);
        mu.unlock();
    }

    void push(int d)
    {
        mu.lock();
        std::cout << std::this_thread::get_id() << " push called\n";
        data.push_back(d);
        mu.unlock();
    }

    int pop()
    {
        int d = 0;

        mu.lock();
        std::cout << std::this_thread::get_id() << " pop called\n";

        if (!data.empty())
        {
            d = data.back();
            data.pop_back();
            mu.unlock();
        }
        else
        {
            throw std::runtime_error("Stack is empty");
        }
        return d;
    }

    int size()
    {
        int d = 0;
        mu.lock();
        std::cout << std::this_thread::get_id() << " size called\n";

        d = data.size();
        mu.unlock();
        return d;
    }

private:
    std::vector<int> data;
    std::mutex mu;
};

int main(void)
{
    Stack s(100);
    std::map<int, std::function<int(int)>> lookup;

    lookup[0] = [&](int d)
    {
        s.push(d);
        return 1;
    };

    lookup[1] = [&](int d)
    {
        if (s.size() > 0)
        {
            return s.pop();
        }
        return -1;
    };

    lookup[2] = [&](int d)
    {
        s.push(10 * d);
        return 1; };

    lookup[3] = [&](int d)
    {
        s.push(d + 10);
        return 1; };

    lookup[4] = [&](int d)
    { return s.pop(); };

    lookup[5] = [&](int d)
    { return s.pop(); };

    unsigned int n = std::thread::hardware_concurrency();

    std::cout << "\nTotal number of threads possible ::  " << n << "\n";

    const int c_size = 10;

    std::thread ts[c_size];
    for (int i = 0; i < c_size; i++)
    {
        ts[i] = std::thread(lookup[i % 5], i);
    }
    for (int i = 0; i < c_size; i++)
        ts[i].join();

    return 0;
}