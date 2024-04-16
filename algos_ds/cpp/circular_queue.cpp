#include <iostream>
#include <vector>

template <typename T = int>
struct RingBuffer
{
    std::vector<T> m_data;
    int m_front = 0, m_rear = 0, m_size = 0;

    RingBuffer(int cap) : m_data(cap)
    {
    }

    bool empty() const
    {
        return m_size == 0;
    }

    bool full() const
    {
        return m_size == m_data.size();
    }

    void push(T &d)
    {
        if (this->full())
        {
            std::cerr << " RBuffer is full\n";
        }
        m_data[m_front] = d;
        m_front = (m_front + 1) % m_data.size();
        m_size++;
    }

    T pop()
    {
        if (this->empty())
        {
            std::cerr << " RBuffer is empty\n";
        }
        auto d = m_data[m_rear];
        m_rear = (m_rear + 1) % m_data.size();
        m_size--;
        return d;
    }
};
int main(void)
{

    RingBuffer r(15);
    for (int i = 0; i < 20; i++)
    {
        r.push(i);
    }

    for (int i = 0; i < 20; i++)
    {
        std::cout << r.pop() << " ";
    }

    return 0;
}