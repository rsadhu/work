#include<thread>
#include<mutex>
#include<memory>
#include<condition_variable>
#include<iostream>

namespace utl
{
enum  class NumberSystem
{
    DEC,
    HEX,
    BIN,
    OCT
};
class CppFeatureSet
{
public:
    CppFeatureSet();
    CppFeatureSet(const CppFeatureSet &);
    CppFeatureSet(CppFeatureSet &&);
    explicit CppFeatureSet(int d){}
    CppFeatureSet(const std::initializer_list<int> &s);
    virtual ~CppFeatureSet();
    void workOnArray();
private:
    int m_array[100];
    int m_index = 0;
    NumberSystem m_numsys  = NumberSystem::DEC;
};
}


