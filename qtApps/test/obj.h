#ifndef OBJ_H
#define OBJ_H
#include<QDebug>
#include<pthread.h>

class Thread
{
public:
    Thread(int d);
    void start();
    void stop();
    virtual void run()=0;
    static void * threadFun(void *th)
    {
        static_cast<Thread*>(th)->run();
    }

private:
    pthread_t pThread;
    pid_t pid;
    int data;

};


class Obj:public Thread
{
public:
    Obj(int d):Thread(d){}
    void run(void){ qDebug()<<"Obj::run\n";}

};




Thread::Thread(int  d):data(d)
{

}


void Thread::start()
{
  pid = pthread_create(&pThread,0,Thread::threadFun,this);
}

void Thread::stop()
{
    qDebug()<<"Thread::stop\n";
    pthread_exit(&pThread);
}



class Base
{
 public:
//    virtual ~Base(){}
};


class Derived:public Base
{
 public:
  //  ~Derived(){}
};




#endif // OBJ_H
