#include<pthread.h>
#include<stdio.h>



class Test
{
public:
  void display (void)
  {
    printf ("\n-------- %s  \n", m_str);
  }
  void setString (char *str = "test")
  {
    m_str = str;
  }
  void myThread (char *);
private:
  char *m_str;
};


void
Test::myThread (char *s)
{

}


void *
myThread (void *s)
{
  printf ("\n myThread function ---- parameter passed ----  \n");
  Test *rObj = reinterpret_cast < Test * >(s);
  rObj->display ();
  rObj->setString (const_cast<char *>("fromThread"));
  #ifdef EXIT_TEST
  pthread_exit((void *)-999);
#endif//
  rObj->display ();
  return (void *) 100;

}


int
main (void)
{
  pthread_t thread_id;
  Test t;
  const char *s = "i am trying to learn";
  t.setString (const_cast<char *>("discoDancer"));
  //int ret  =  pthread_create(&thread_id,NULL,t.myThread,(void *)s);
  int ret = pthread_create (&thread_id, NULL, myThread, (void *) &t);
  void *r;
  int j_r = pthread_join (thread_id, &r);
  printf("\n After Join\n");
//  t.display ();
  printf ("\n %d \n", ((int *) r));
  return 0;
}
