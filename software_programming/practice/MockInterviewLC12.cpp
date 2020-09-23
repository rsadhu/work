#include <vector>
#include <iostream>

using namespace std;


vector < int >
prisonAfterNDays (vector < int >&cells, int N)
{

  std::vector < int >res (8, 0);
  while (1)
    {
      for (int i = 2; i < cells.size (); i++)
	{
	  if (cells[i - 2] == cells[i])
	    res[i] = 1;
	  else
	    res[i] = 0;
	}


      if (N > 0)
	{
    
           for (auto it:res)
    {
      std::cout << it << " ";
    }

        std::cout<<" \n========================\n";
      
	  cells = res;
	  std::fill (res.begin (), res.end (), 0);
      N--;
	}
      else
	{
	  break;
	}
    }

  return res;
}


int
main (void)
{
  std::vector < int >data = { 0, 1, 0, 1, 1, 0, 0, 1 };
  auto res = prisonAfterNDays (data, 7);
for (auto it:res)
    {
      std::cout << it << " ";
    }

  return 0;
}
