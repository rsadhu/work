#include <iostream>
#include <set>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        
        for(auto it:nums)
            data_.insert(it);
        
        k_ = k;
    }
    
    int add(int val) {
        data_.insert(val);
        
        int d = 0, i = k_;
        for(auto it =  data_.rbegin(); i >=0 && it!=data_.rend();it++, i--)
        {
            //td::cout<< *it<< " ";
            d =  *it;
        }
        return d;        
        
    }
    std::set<int> data_;
    int k_;
};


int main() {
  std::vector<int> v{4,5,8,2};
  KthLargest obj (3 , v );
  obj.add(3);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
