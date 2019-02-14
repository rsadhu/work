#include<pthread.h>
#include<iostream>
using namespace std;

void* print_message_function(void *p)
{
const char *str =  (const char *)p;
 cout<< str;
 //return const_cast<void *>("hi");
}
int main(void)
{
pthread_t thread1;
char *message1 = "this is my thread";
int  iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
cout<<" after thread\n";
pthread_join( thread1, NULL);

cout<<"\nthe thread1 completes :: "<<iret1;
return 0;
}