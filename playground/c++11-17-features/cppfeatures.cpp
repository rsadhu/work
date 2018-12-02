#include "cppfeatures.h"
#include <initializer_list>

using namespace utl;

CppFeatureSet::CppFeatureSet(): m_array { 1, 2, 3, 4, 5}
{
 std::cout<<"\n CppFeatureSet::CppFeatureSet\n";
}


CppFeatureSet::CppFeatureSet(const std::initializer_list<int> &s)
{
 std::cout<<"\n CppFeatureSet::CppFeatureSet::initializer_list\n";
 for(auto it: s)
 {
   m_array[m_index++] = it;
 }
}


CppFeatureSet::CppFeatureSet(const CppFeatureSet &rhs)
{
 std::cout<<"\n CppFeatureSet::CppFeatureSet:: copy\n";
	for(auto it:rhs.m_array)
	{
		m_array[m_index++] = it;
	}
}



CppFeatureSet::CppFeatureSet(CppFeatureSet &&rhs)
{
 std::cout<<" \nCppFeatureSet::CppFeatureSet::move\n";
	for(auto &it:rhs.m_array)
	{
		m_array[m_index++] = it;
    //    it =  0;
	}
    //rhs.m_index = 0;    
}



CppFeatureSet::~CppFeatureSet()
{
 std::cout<<" CppFeatureSet::~CppFeatureSet\n";
}

void CppFeatureSet::workOnArray()
{
 std::cout<<std::endl;
 for(int i=0;i<m_index;i++)
 {
  std::cout<<m_array[i] << "  ";
 }
 std::cout<<std::endl;

// char32_t *utfs =  U"سلام";
// std::cout<<utfs;
}
