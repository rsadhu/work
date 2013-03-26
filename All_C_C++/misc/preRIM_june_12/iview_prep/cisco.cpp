#include<iostream>

using namespace std;

class T
{
public:
      //T(){cout << a<< " " << b << " " << ret << " " <<endl;}//} << c;}
  T (int x, float y, bool z, const int l):a (x), b (y), ret (z), c (l)
  {
    cout << a << " " << b << " " << ret << " " << c << endl;
  }


  void display ()
  {
    cout << a << " " << b << " " << ret << " ";
  }				//  << c;}

private:
  int a;
  float b;
  bool ret;
  const int c;
};

class test
{
public:
	test(){ cout<< " \nret :: "<< ret;}
	void display(){ cout<<" \ntest:: display "<<ret<<endl;}
private:
 bool ret;
};

int
main (void)
{
  char *tmp = " testing ";
  //cout << sizeof (tmp++) << sizeof (++tmp);
//  T t(1,2.0,0,9);
 // t.display ();
 test t;
 t.display();
  return 0;
}
