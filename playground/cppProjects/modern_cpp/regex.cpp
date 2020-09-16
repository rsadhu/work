#include <regex>
#include <iostream>
#include <set>
#include <string>
using namespace std;

std::set<std::string> dict_;  

bool searchFoo(string word) 
{
        if (word.empty())
            return true;
      
        if (dict_.find(word)!=dict_.end()) {
                return true;     
        }        
        else
        {
            const std::regex reg_txt ("[a-z]*.[a-z]*");
            for (auto it : dict_)
            {
                return std::regex_match(it, reg_txt) == 1;
            }
        }
        return false;
        
}

int main(void)
{
 dict_.insert("bad");
 dict_.insert("dad");
 dict_.insert("mad");
 
 auto a = searchFoo("pad");
 auto b = searchFoo("bad");
 auto c = searchFoo(".ad");
 auto d = searchFoo("b..");

 return 0;
}

