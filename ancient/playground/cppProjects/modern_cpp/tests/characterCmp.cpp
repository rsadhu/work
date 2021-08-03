#include <iostream>
#include <string>
#include <map>


std::string findHyperlink(std::string text) 
{
    std::string res;
    auto cnt =  0;
   // for(auto it:text)
	for(int i = 0;i< text.length();i++)
    {
        if(text[i] == '\"')
        {
            cnt++;
			i++;
        }
        
        if(cnt==1)
        {
            res+=text[i];
        }
    }
    
    return res;
}

int main(void)
{
//  char ch =  '\"';
 // std::cout<<ch;

  auto r = findHyperlink("<a href=\"http://www.example.org\">Example1</a>");
  std::cout<<r<<std::endl;

  std::map<std::string , int> registers;

    for(int i = 0;i<43;i++)
    {
        std::string str;
        char ch = (i + '0');
        if( i < 10 ) {
            str = "R0" + ch;
        } else {
            str = "R" + ch;
        }
        registers[str] = 0;
    }
 return 0;
}
