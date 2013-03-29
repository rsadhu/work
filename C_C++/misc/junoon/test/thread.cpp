#include<pthread.h>
#include<iostream>
#include<sys/types.h>
using namespace std;

void *
threadFunction1 (void *p)
{
  cout << " thread 2:: " << (char *) p;
  char ch=' ';
 while(ch!='e'){
  cin>>ch;
}
}
int  =19;
void *
threadFunction (void *p)
{
  cout << " msg:: " << (char *) p;
 return (void*) &i;
}


int
main (int argc, char *argv[])
{
  char *msg = "hello Dear Thread";
  pthread_t thread,thread1;
  int tid = pthread_create (&thread, NULL, threadFunction, (void *) msg);
 cout<<" thread2";
  pthread_join (thread, NULL);
/*char *msg1 =  " next one";
  int tid1 = pthread_create (&thread1, NULL, threadFunction1, (void *) msg1);
  pthread_join (thread1, NULL);*/
  
  cout << " Exittting ..";
  return 0;
}
