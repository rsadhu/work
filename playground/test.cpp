#include <fstream>
#include <iostream>
#include <set>
#include <vector>


void moveZeroes(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int j = i;
        if (nums[i] == 0) {
            j++;
            while (j < nums.size() && nums[j] == 0)
                j++;

            std::swap(nums[i], nums[j]);
        }
    }
}

#include <map>
///#include <pair>

using namespace std;

class StreamChecker {

public:
    StreamChecker(vector<string>& words) {

        for (auto it: words)
        {
            //lookup_table[it[it.size()-1]] = it;
            auto pair  = std::make_pair(it[it.size()-1], it);
            lut_.insert(pair);
        }
    }

    bool query(char letter) {
        if(lut_.find(letter)!=lut_.end())
            return true;
        return false;

    }

    std::map<char, string> lookup_table;
    std::multimap<char, string> lut_;
};


int main(void) {
//
//    std::vector <int> tmp{0,1,0,3,12};
//    moveZeroes(tmp);
//    std::ifstream f('README.md');
//    if (f.is_open()) {
//        std::string line, data;
//        while (getline(f, line)) {
//            data += line;
//        }
//
//        std::cout << data;
//    } else {
//        std::cout << ' couldnt open the file';
//    }





std::vector<string> strs =  {"ab","ba","aaab","abab","baa"};
StreamChecker s(strs);

std::vector<char> sss = {'a','a','a','a','a','b','a','b','a','b','b','b','a','b','a','b','b','b','b','a','b','a','b','a','a','a','b','a','a','a'};
for (auto it :sss) {
    auto ret = s.query(it);
    std::cout<<it <<" "<<ret<<"\n";

}
    return 0;
}
