#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

class A
{
public:
  A ():a (100)
  {
    cout << "A::A\n";
  }
  void display ()
  {
    cout << " A::display\n" << a << endl;
  }
  int a;
};

class test
{
public:
  //string name;
  vector < int >marks;
};


void
memAlloc2d ()
{
  int **p;
  p = (int **) malloc (sizeof (int *) * 10);

  for (int i = 0; i < 10; i++)
    {
      *(p + i) = (int *) malloc (sizeof (int) * 10);
      for (int j = 0; j < 10; j++)
	{
	  *(*(p + i) + j) = i + j;
	}
    }

  cout << " \n Printing now ...\n";

  for (int i = 0; i < 10; i++)
    {
      cout << endl << i << ". ";
      for (int j = 0; j < 10; j++)
	{
	  cout << p[i][j] << " ";
	}
    }
  cout << endl;


  for (int i = 0; i < 10; i++)
    free (*(p + i));

}



int
main (void)
{ 
test **t  ;
   
t = (test**)malloc(sizeof(test*) * 10);
 for(int i=0;i<10;i++)
 *(t+i) =  (test *) malloc(sizeof(test)*10);
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			t[i][j].marks.push_back(i+j);
		}
	}


	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<t[i][j].marks.back() << "  ";
			t[i][j].marks.pop_back();
		}
		cout<<"\n";
	}

	for(int i=0;i<10;i++)
	free(*(t+i));

  return 0;
}
