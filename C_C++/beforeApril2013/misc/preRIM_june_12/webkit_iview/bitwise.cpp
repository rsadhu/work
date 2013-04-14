#include<iostream>
using namespace std;


void
setBit (int n=3, unsigned int num = 0)
{
  cout << "setBit:: setBit\n";
  int j = 1;
  int tmp  = j;
  while(n-1 > 0)
{
	j <<= 1;
       n --;
}
 j|=tmp;
 cout<<" j :: "<<n <<"  "<< j<<endl; 
}

int noBitSet()
{
	int num  = 7;
	int cnt = 0;

	while (num > 0)
	{
		if (num & 1 == 1)
			cnt++;
		num = num >> 1;
	}

	cout << " number of bits set are :: " << cnt << endl;
	return cnt;
}

int
main (void)
{
  unsigned int i = 1;
  int j = 1;
  cout << (i >> 2) << (i << 31) << endl;
  cout << (j >> 2) << (j << 31) << endl;
  cout << " set nth bit  :: ";
  int n;
//  cin >> n;
  setBit ();
  return 0;
}
