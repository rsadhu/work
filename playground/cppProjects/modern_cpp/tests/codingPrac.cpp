#include<iostream>

int
main (void)
{

  int n = 4;
  for (int i = 0; i < n; i++)
    {
      for (int j = n - i; j >= 1; j--)
	{

	  for (int k = 1; k <= n; k++)
	    {
	      std::cout << j;
	    }
        std::cout<<" ";
	}

	  std::cout << "\n";
    }
  return 0;
}
