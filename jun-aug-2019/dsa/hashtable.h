#ifndef HASHTABLE_H
#define HASHTABLE_H

/*hash(k, m) - m is size of hash table
add(key, value) - if key already exists, update value
exists(key)
get(key)
remove(key)*/

const int N =  1000;

template<typename T, typename U>
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
     m_lookup[N];
};

#endif // HASHTABLE_H
