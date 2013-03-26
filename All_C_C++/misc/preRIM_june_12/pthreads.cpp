#include<pthread.h>
//#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void
mysleep (unsigned mseconds)
{
  clock_t goal = mseconds + clock ();
  while (goal > clock ());
}

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int globalCount;

void *
threadFunc (void *para)
{
  pthread_mutex_lock (&mutex1);
  const char *msg = " return valye";
  int val = *((int *) para);
  if (val == 1)
    globalCount += 20;
  else
    globalCount += 100;

  printf (" \n %d ::  .... threadFunc ......\n", globalCount);
  pthread_mutex_unlock (&mutex1);
  return (void *) msg;
}


int
main (void)
{
  pthread_t thread1, thread2;
  int *msg;
  int val = 1;
  msg = &val;
  printf ("\n Main::GlobalCount :: %d \n", globalCount);
  int iret1 = pthread_create (&thread1, NULL, threadFunc, (void *) msg);
  pthread_join (thread1, NULL);
  val = 2;
  printf ("\n Main::GlobalCount :: %d \n", globalCount);
  int iret2 = pthread_create (&thread2, NULL, threadFunc, (void *) msg);
  pthread_join (thread2, NULL);
  printf ("\n Main::GlobalCount :: %d \n", globalCount);
  // mysleep (100);
  return 0;
}
