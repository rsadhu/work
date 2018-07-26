#include<iostream>
#include<list>
#include<array>
#include<vector>
#include<algorithm>
#include<map>
//#include<multimap>
#include<set>
//#include<multiset>

int main(void)
{
    std::list<int> s{1,2,3,4};
    std::list<int> *ps = new std::list<int> { 1,2,3,4};

    std::array<int,5> arr ={1,2,3,4,5};

    for(auto &it: arr)
    {
        std::cout << "Date Before : "<< it << "\n";
        it = 1 + it;
    }

    for(auto it: arr)
    {
        std::cout <<" Data After :  "<< it << "\n";
    }

    std::vector<int> arrv={1,2,3,4,5};

    if(std::find(arr.begin(),arr.end(),4)!=arr.end()) {
        std::cout<< "data found in array\n";
    }
    else {
        std::cout<< "data not found in array\n";
    }

    if(std::find(arrv.begin(),arrv.end(),4)!=arrv.end()) {
        std::cout<< "data found\n";
    }
    else {
        std::cout<< "data not found\n";
    }

    std::map<int,std::string> lmap,mmap;
    for(int i=0;i<10;i++) {
        lmap.insert(std::pair<int,std::string>(i,std::to_string(i)));
        mmap[i] = std::to_string(i);
    }


    std::multimap<int, std::string> multiMap;


    for(int i=0,j=0;i<10;i++) {
//        multiMap[i] = std::to_string(i+j);
  //      multiMap[j] = std::to_string(i+1);
          multiMap.insert(std::pair<int,std::string> (i,std::to_string(i)));
          multiMap.insert(std::pair<int,std::string> (j,std::to_string(i+j)));
        j++;
    }

    std::set<int> lset;
    std::multiset<int> lmultiset;

    for(int i=0,j=0;i<10;i++,j++)
    {
        lset.insert(i);
        lmultiset.insert(i+j);
    }

    return 0;
}
