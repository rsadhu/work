#include <iostream>
using namespace std;

int main(void)
{
    char const *pt = " disco ";
    const char *cc = "hi";
    char *const ch1 = "hello";
    cout << " 1st one :: " << pt;
    cout << " 2nd one :: " << cc;
    pt = " hola";
    cc = " adios";
    cout << " \n1st one :: " << pt;
    cout << " \n2nd one :: " << cc << endl;
    ch1 = " ";
    return 0;
}
