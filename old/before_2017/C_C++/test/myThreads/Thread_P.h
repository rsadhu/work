#ifndef __THREAD__P__
#define __THREAD_P__
class Thread_P
{
public:
  virtual ~ Thread_P ()
  {
  };
  virtual void createThread () = 0;
  virtual void destroyThread () = 0;
  virtual bool isAlive () = 0;
  virtual void wait () = 0;
};


class ThreadLinux:public Thread_P
{

};


class ThreadStdCpp:public Thread_P
{

};

#endif //
