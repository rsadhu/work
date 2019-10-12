#ifndef HASHTABLE_H
#define HASHTABLE_H

const int N =  1000;

template<typename T=int, typename U>
class Map
{
public:
    T key;
    U value;
};

template<typename T>
class HashTable
{
public:
    void add(T key, T value);
    bool exists(T key);
    T get(T key);
    bool remove(T key);
private:
     Map<T, U> m_lookup[N];
};

#endif // HASHTABLE_H
