#pragma once
namespace dsa
{
#define CAPACITY 10

    using uint = unsigned int;
    template <typename T>
    class Vector
    {
    public:
        Vector();
        // Vector(uint , T);
        ~Vector();
        void push_back(T);
        void push_front(T);

        void pop_back();
        void pop_front();
        T front();
        T back();
        uint size();
        uint capacity();

        T at(int index);
        T operator[](int index);

    protected:
        void resize();

    private:
        T *m_arr;
        uint m_capacity;
        uint m_size;
    };

    template <typename T>
    class Iterator : public Vector<T>
    {
    public:
        // Iterator();
    private:
    };

    template <typename T>
    T Vector<T>::at(int index)
    {
        if (index < m_size)
        {
            return m_arr[index];
        }
        return 0;
    }

    template <typename T>
    T Vector<T>::operator[](int index)
    {
        if (index < m_size)
        {
            return m_arr[index];
        }
        return 0;
    }

    template <typename T>
    void Vector<T>::resize()
    {
        int oldsize = m_capacity;
        m_capacity += m_capacity;
        T *tmp = new T[m_capacity];
        for (int i = 0; i < oldsize; i++)
        {
            // tmp[i] = std::move(m_arr[i]);
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    template <typename T>
    Vector<T>::Vector() : m_capacity(CAPACITY), m_size(0)
    {
        m_arr = new T[m_capacity]();
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] m_arr;
    }

    template <typename T>
    void Vector<T>::push_front(T d)
    {
        if (m_size >= m_capacity)
        {
            resize();
        }
        else
        {
            m_arr[m_size++] = d;
        }
    }

    template <typename T>
    void Vector<T>::push_back(T d)
    {
    }

    template <typename T>
    void Vector<T>::pop_back()
    {
    }

    template <typename T>
    T Vector<T>::front()
    {
    }

    template <typename T>
    unsigned int Vector<T>::size()
    {
        return m_size;
    }

    template <typename T>
    unsigned int Vector<T>::capacity()
    {
        return m_capacity;
    }

}
