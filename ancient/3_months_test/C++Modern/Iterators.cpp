#include <initializer_list>
#include <iostream>
#include <vector>

template <typename T>
class MyList {
public:
    MyList() { }
    MyList(std::initializer_list<T> rhs)
    {
        for (auto it : rhs) {
            m_arr[++m_index] = it;
        }
    }
    MyList(T arg) { }
    void push_back(T arg)
    {
        //auto new_Arg = std::forward<T> (arg);
        // if (m_index < m_capacity)
        m_arr[++m_index] = arg;
    }

    inline size_t size() { return m_index + 1; }

    class Iterator {
    public:
        Iterator(T* ptr)
        {
            _ptr = ptr;
        }

        Iterator operator++(int postincrement)
        {
            std::ignore = postincrement;
            auto tmp = this;
            _ptr++;
            return *this;
        }

        Iterator operator++()
        {
            _ptr++;
            return *this;
        }

        Iterator operator--(int postincrement)
        {
            std::ignore = postincrement;
            auto tmp = this;
            _ptr--;
            return *tmp;
        }

        Iterator operator--()
        {
            _ptr--;
            return *this;
        }

        bool operator!=(const Iterator& rhs)
        {
            return _ptr != rhs._ptr;
        }

        T operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

    private:
        T* _ptr = nullptr;
    };

    Iterator begin() { return Iterator(&m_arr[0]); }
    Iterator end() { return Iterator(&m_arr[m_index + 1]); }

    Iterator rbegin() { return Iterator(&m_arr[m_index]); }
    Iterator rend() { return Iterator(&m_arr[0]); }

private:
    static constexpr size_t LISTSIZE = 100;
    size_t m_capacity = LISTSIZE;

    int m_index = -1;
    T m_arr[LISTSIZE];
};

class Animal {
    std::string _kind = "human";

public:
    Animal(std::string kind = "")
        : _kind(kind)
    {
    }

    void display() const
    {
        std::cout << "\nI am " << _kind << "\n";
    }
};

int main(void)
{
    MyList<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    v.push_back(-1);

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "  ";
    }

    std::cout << "\n\n";

    for (auto it : v) {
        std::cout << " " << it;
    }

    for (auto it = v.rbegin(); it != v.rend(); it--) {
        std::cout << " " << *it;
    }

    MyList<Animal> animals = { Animal("Dog"), Animal("Cat"), Animal("Cow") };

    // for (auto it : animals) {
    //     it.display();
    // }


    // for (auto it = animals.begin(); it != animals.end(); it++)
    // {
    //  it->display();
    // }

    std::cout<<"\n\n";
    for (auto it = animals.rbegin(); it!=animals.rend(); it--)
    {
        it->display();
    }

    return 0;
}