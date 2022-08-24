#include <iostream>
using namespace std;

int main(void)
{
  int n = 9;
  int r[n];
  int m;
  cout << "size of an array ::";
  cin >> m;
  int s[m], t[m];
  for (int i = 0; i < m; i++)
    cout << s[i] << " ";

  cout << " \n";
  for (int i = 0; i < m; i++)
    cout << t[i] << " ";
  cout << " \n";
  return 0;
}
