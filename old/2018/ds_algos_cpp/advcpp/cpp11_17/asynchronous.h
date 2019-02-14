#ifndef ASYNCHRONOUS_H
#define ASYNCHRONOUS_H
#include<future>
#include<thread>

using  functinCallback= std::function<void(int)>;

class Asynchronous
{
public:
    Asynchronous();
    void start(int,functinCallback cb);
    int getValue();
private:
    int workerFunction(int & );
    std::future<int> mData;
    functinCallback m_cb;

};

#endif // ASYNCHRONOUS_H
