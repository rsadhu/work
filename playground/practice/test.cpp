#include <set>
#include <iostream>

int
nthUglyNumber (int n)
{
  int j = 0;
  std::set < int >l;
  while (l.size () <= n)
    {
      j++;

      if (j % 2 == 0 || j % 3 == 0 || j % 5 == 0)
	{
	  l.insert (j);
	}

    }

  return *l.end ();
}

#include<map>
#include <vector>

using namespace std;


bool
wordPattern (string pattern, string str)
{

  std::vector < char > pl;

    for (auto it:pattern)
    {
        if (pl.find (it) == pl.end ())
	    {
	        pl.push_back (it);
	    }
    }

  
    std::vector < string > sl;

    for (auto it:str)
    {
        if (str != " ")
	    {
	        if (std::find (sl.begin(), sl.end(), it) == sl.end ())
	        {
	            sl.push_back (it);
	        }
	    }
    }


    std::map < char, string > lu;

    if (sl.size () != pl.size ())
        return false;


    for (int i = 0; i < sl.size (); i++)
    {
        lu[pl[i]] = sl[i];
    }

    for (auto[key, val]:lu)
    {
        std::cout << key << "  " << val;
    }

    return true;
}

int
main ()
{
  auto n = nthUglyNumber (10);
  std::cout << n;

  auto p = "abba", q = "dog cat cat dog";
  auto ret = wordPattern (p, q);


  return 0;
}
