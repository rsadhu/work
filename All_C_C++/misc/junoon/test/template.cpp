#include<iostream>
using namespace std;
template < typename T > 
class MyClass
{
	public:
		MyClass ():data (0)
	{
	}
		MyClass *operator  ->();
		void display ();
	private:
		T * data;
};

template < typename T > 
MyClass  *Myclass < T >::operator->()
{
  return this;
}

template < typename T > 
void MyClass < T >::display ()
{
  cout << " MyClass:: display .. " << data;
}


int
main (void)
{
  MyClass < int >*obj = new MyClass < int >;
  obj->display ();
  delete obj;
  MyClass < int >t;
  t->display ();
  return 0;
}
