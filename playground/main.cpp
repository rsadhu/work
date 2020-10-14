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



bool isPalindrome(string s) {

    auto isChar =  [] (char ch)
    {
        return  (ch >='a'  && ch <='z') ||  (ch >='A' && ch <= 'Z')  ? true: false;
    };

    std::string str;

    for(auto it: s)
    {
        bool ret = isChar(it);
        if (ret)
            str += it;
    }


    int i = 0, j = str.length()-1;
    while(i<=j)
    {
        if (std::tolower(str[i]) != std::tolower(str[j]))
            return false;

        i++;
        j--;
    }

    return true;
}



int main() {
  std::vector<int> v{4,5,8,2};
  KthLargest obj (3 , v );
  obj.add(3);
  std::cout << "Hello, World!" << std::endl;

  std::cout<<isPalindrome("0P");
  return 0;
}
