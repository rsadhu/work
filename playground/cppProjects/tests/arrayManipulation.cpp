#include<iostream>
#include<vector>
#include<stack>

int
main (void)
{
  std::vector < int >arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, res;
  int k = 2;
  int i = 0;
  std::stack < int >st;
  
  std::cout << "values are ";
	
  for (auto it:arr)
  {
  	std::cout << it << " ";
  }
  
 std::cout << "\n";

 for (auto it:arr)
 {   
 	i++;
    if (i <= k)
	{
	  st.push (it);
	}
    else
	{
	  while (!st.empty ())
	    {
	      res.push_back (st.top ());
	      st.pop ();
	    }
	  i = 0;
	}
  }

  std::cout << "values are ";
  for (auto it:res)
  {
  	std::cout << it << " ";
  }
  std::cout << "\n";
  
  return 0;
}
