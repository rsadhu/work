#include<pthread.h>
#include<iostream>

using namespace std;

void * fptr(void*p)
{
char *m = (char *) p;
cout<<p;
}
int main(void)
{
	pthread_t thread1;
	char *msg = " this is test";
	int pid =  pthread_create(&thread1,NULL,fptr,(void*)msg);
	cout<<"after htread";
	pthread_join(thread1,NULL);
	 return 0;
}
