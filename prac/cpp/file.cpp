#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<fstream>

int
main (int argc, char *argv[])
{
  try
  {
      std::fstream filereader;
      filereader.open("log.txt", filereader.binary | filereader.trunc | filereader.in | filereader.out) ;

      if(filereader.is_open())
      {
          std::cout<<" file opened\n";
          filereader<< "// *****************    disco dance **************  ";
          while (!filereader.eof ())
          {
              std::string data;
              filereader >> data;;
              std::cout << data;

          }
      }
      else
      {
          std::string str ="File not Found\n";
          throw new std::exception();
      }
  }
  catch (std::exception e)
  {
        std::cout << " Exception: "<<e.what() ;
  }
  return 0;
}
