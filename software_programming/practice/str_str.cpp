#include <iostream>
#include <vector>

using namespace std;


std::vector<string> tokenize(string &s, string delimiter= " ")
    {
        std::vector<string > res;             
        
        size_t pos = 0;
        std::string token;
        
        while ((pos = s.find(delimiter)) != std::string::npos) 
        {
            token = s.substr(0, pos);
            res.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        
        return res;

    }
    
    bool isLetterLog( string &str)
    {
        auto tStr =  tokenize(str);
        return  (tStr[1] >= "0" && tStr[1]== "9");
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        std::vector<string> l_res, d_res;
        for (auto it: logs)
        {
            if (isLetterLog(it)) {
                l_res.push_back(it);                
            }
            else
            {
                d_res.push_back(it);
            }
        }      
        
        return l_res + d_res;
    }



int main(void)
{
     std::vector<string> ogs =  {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
     auto res =  reorderLogFiles(ogs);
}
