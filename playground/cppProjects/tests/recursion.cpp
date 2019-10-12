#include<iostream>
#include<vector>


void
bifurcate (std::vector < int >src, std::vector < int >&odd,
	   std::vector < int >&even, int i)
{
  if (i < src.size ())
    {
      if (src.at (i) % 2 == 0)
	{
	  even.push_back (src.at (i));
	}
      else
	{
	  odd.push_back (src.at (i));
	}

      i++;
      bifurcate (src, odd, even, i);
    }

}



int
main (void)
{
  std::vector < int >src = { 1, 2, 3, 4, 5, 6, 7, 8 }, even, odd;
  bifurcate (src, odd, even, 0);


for (auto it:even)
    {
      std::cout << it;
    }


for (auto it:odd)
    {
      std::cout << it;
    }

  return 0;
}
