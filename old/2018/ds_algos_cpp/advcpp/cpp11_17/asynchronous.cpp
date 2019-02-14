#include "asynchronous.h"
#include<chrono>

Asynchronous::Asynchronous()
{

}


void Asynchronous::start(int para,functinCallback cb)
{
    m_cb = cb;
    mData  = std::async(std::launch::async, &Asynchronous::workerFunction,this,std::ref(para));
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    m_cb(mData.get());
}


 int Asynchronous::workerFunction(int & data)
 {
    int n = data;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=i;
    }
    return sum;
}
