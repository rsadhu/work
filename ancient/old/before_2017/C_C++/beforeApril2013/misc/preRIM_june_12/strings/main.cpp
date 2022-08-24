#include "string.h"

int main(int argc, char *argv[])
{
  if (argc == 2)
    cout << "strlen of    " << argv[1] << "   " << String::strlen(argv[1]) << endl;
  else if (argc < 2)
  {
    argv[1] = "testing";
  }

  String s(argv[1]);
  cout << "\n"
       << s.ascii();

  String t = s;

  cout << "\n"
       << t.ascii();

  String x;
  x = t;

  cout << "\n"
       << x.ascii();

  cout << "\n";
  if (x == t)
    cout << "\n Equal \n";

  String z = "copyConstructor";
  if (z != x)
    cout << "\n Yes not equal\n";

  return 0;
}
