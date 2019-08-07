#include<string>
#include<iostream>



void
reverse (std::string str)
{

}



void
reverseCPtr (char *str)
{
  if (*str == '\0')
 	return ;      
   
  reverseCPtr (++str);
  std::cout << *str;
}



//   (( 6 + 8 ) * ( 1 + 2 + 3 ) * (( 4/ 2 ) * (18 /  3 ))


int
main (void)
{
  char *str = "This is test string";

  reverse (str);
  reverseCPtr (str);

  return 0;
}
