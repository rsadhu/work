#ifndef __THREAD__H__
#define __THREAD__H__

namespace myprog
{
    class Thread_P;
    class Thread
    {
        public:
            static Thread_P * getInstance (char *threadType = "linux");
        private:  
            Thread ();
            Thread (const Thread &);
            Thread & operator = (const Thread &);
            static Thread_P *mImpl;
    };
};
#endif //
