#include <iostream>
#include <vector>
#include<cmath>

using namespace std;


int f(int c)
{
     return !((c-1) &c);
}


 std::vector<int> tokenizer(string s, string delimiter=".")
 {
        
        std::vector<int> res;        
        size_t pos = 0;        
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) 
        {
            token = s.substr(0, pos);
            res.push_back(std::stoi(token));
            s.erase(0, pos + delimiter.length());
        }
        
        if (res.size()==0)
        {
            res.push_back(std::stoi(s));
        }
        return res;
 }




int main(int argc, char *argv[])
{

    std::cout<< f(8);
    std::cout<< f(7);
    std::cout<< f(4);
    std::cout<< f(1);
    std::cout<<"\n";

    std::cout<< std::stoi("01");
    
    std::cout<<"\n";


    auto v1 =  tokenizer("1.1");


    auto bin2dec = [] (std::string rhs)
    {
        int sum = 0, i = 0;
        for(auto it : rhs)
        {
            if (it == '1')
            {
                sum += pow(2, rhs.size()-1 -i);
            }
            i++;
        }
        return sum;
    };

    
    std::string binstr =  "1111";
    if (argc >=2)
    {
        binstr = argv[1];
    }
    else
    {
        std::cout<<" insufficient args , would fall back to default 1001";
    }
    std::cout<<" dec of "<< binstr<<" is  " << bin2dec(binstr);
 return 0; 
}
