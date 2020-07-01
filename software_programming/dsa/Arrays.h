#include <cmath>
#include <iostream>
#include <memory>

#define N 100

namespace GPrep {

    class Exception : public std::exception {
    public:
        Exception(std::string str = std::move("Unknown Exception")) {
            __message = str;
        }

        const char *what() const noexcept override { return __message.c_str(); }

        std::string __message;
    };

    template<typename T>
    class Vector {
    public:
        Vector(int capacity = 0, int element = 0);

        Vector(std::initializer_list<T> &rhs);

        void push_back(const T &data);

        T operator[](int index);

        T at(int index) const { return __data[index]; }

        inline int size() const { return __size; }

        inline int capacity() const { return __capacity; }

        bool is_empty() { return __size == 0; }

        T pop_back();

        void insert(int index, T item);

        bool remove(int index);

        int find(T item);

    private:
        void resize();

        int __capacity = 0;
        int __size = 0;
        T *__data = nullptr;
    };

    template<typename T>
    Vector<T>::Vector(int capacity, int element) {
        if (capacity == 0) capacity = N;
        __capacity = capacity;
        __data = new T[capacity];
    }

    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> &rhs) {
        Vector(rhs.size());
        for (auto it : rhs) {
            __data[__size++] = it;
        }
    }

    template<typename T>
    void Vector<T>::resize() {
        if (__size >= __capacity) {
            __capacity = std::pow(__capacity, 2);
            auto *tmp = new T[__capacity];
            for (int i = 0; i < __size; i++) {
                tmp[i] = __data[i];
            }
            delete __data;
            __data = tmp;
        }
    }

    template<typename T>
    void Vector<T>::push_back(const T &data) {
        resize();
        __data[__size++] = data;
    }

    template<typename T>
    T Vector<T>::operator[](int index) {
        if (index <= __size) return __data[index];
        return T();
    }

    template<typename T>
    T Vector<T>::pop_back() {
        if (__size > 0) {
            return __data[--__size];
        } else {
            throw Exception("Vector is empty");
        }
    }

    template<typename T>
    void Vector<T>::insert(int index, T item) {
        if (index <= __size && index >= 0) {
            int cnt = ++__size;
            resize();
            while (cnt > index) {
                __data[cnt] = __data[cnt - 1];
                cnt--;
            }
            __data[index] = item;
        } else {
            throw Exception("Out of Range, insertion");
        }
    }

    template<typename T>
    bool Vector<T>::remove(int index) {
        if (index < __size && index >= 0) {
            for (size_t i = index; i < __size - 1; i++) {
                __data[i] = __data[i + 1];
            }
            __size--;
            return true;
        }
        return false;
    }

    template<typename T>
    int Vector<T>::find(T item) {
        for (int i = 0; i < __size; i++) {
            if (__data[i] == item) return i;
        }
        return -1;
    }
}  // namespace GPrep