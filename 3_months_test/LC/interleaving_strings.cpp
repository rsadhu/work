#include <iostream>
#include <string>
using namespace std; 


class Solution {
public:
  
    bool isInterleave(string s1, string s2, string s3) {
        bool s1_p = false, s2_p = false;
        
        int i = 0, j = 0, k = 0 ;
        do
        {
            while ( i < s3.length()  && j < s1.length() )
            {
                if (s3[i] != s1[j])
                {
                    s1_p = false;
                    break;
                }  
                s2_p = true;  
                i++;
                j++;
            }
            
                        
           while ( i < s3.length()  && k < s2.length() )
            {
                if (s3[i] != s2[k])
                {
                    s2_p = false;
                    break;
                } 
                s1_p = true;   
                i++;
                k++;
            }        
         } while(i < s3.length() && (s1_p || s2_p));
       return  (s1_p || s2_p);
           
       }

};


int main(void)
{
    std::string s1="a", s2="", s3="aa";
  
    Solution s;
    std::cout<<"string are interleaved ->>  "<<s.isInterleave(s1, s2, s3);

    return 0;
}