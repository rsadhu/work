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
      std::fstream filereader ("classes.cpp");

      filereader<< "// *****************    disco dance **************  ";
      while (!filereader.eof ())
      {
          std::string data;
          filereader >> data;;
          std::cout << data;

      }
  }
  catch (std::exception e)
  {
        std::cout < " Exception: " << e.what ();
  }
  return 0;
}
