#include<map>
#include<iostream>
#include<vector>
#include<functional>


int
main (void)
{
/*  std::multimap < int, int >lookup;
  std::vector < int >a = { 2, 1, 3, 5, 3, 2 };

  for (int i = 0; i < a.size (); i++)
    {
      lookup.insert (std::pair < int, int >(a[i], i));
    }

  int c = 0, index = 99999, num = 0;

for (auto it:lookup) {
      
if (lookup.count (it.first) == 2)
	{

	  if (c++ % 2 == 1)
	    {
	      if (it.second < index)
		{
		  num = it.first;
		  index = it.second;

		}
	    }
	  std::cout << c++ << ".first   " << it.first << "   " << it.
	    second << "   \n";
	}
    }

  std::cout << "\n number is " << num << "\n";

*/

auto index1 = std::hash<int> {}(199);
std::cout<<" index is >> "<< index1<<"\n";


auto index2 = std::hash<std::string> {}("this is a test");
std::cout<<" index is >> "<< index2<<"\n";

std::map<int, int> lu;

for(int i = 0;i < 10;i++)
{
 lu[i]+= i;;
}


auto it1 =  lu.lower_bound(-11);
auto it2 =  lu.lower_bound(19);





  return 0;
}
