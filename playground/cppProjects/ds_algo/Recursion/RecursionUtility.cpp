#include "RecursionUtility.h"
#include <iostream>
using namespace utl;

void RecursionUtility::reverseString(char *str)
{
   if(*str=='\0')
  	 return ;
   str++;
   reverseString(str);
   std::cout<<*str;
}
