#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
#include<future>
#include<thread>
#include<functional>
#include<chrono>

template<typename T>
class MyThread
{
        using callbackFunction = std::function<void (T)>;
    public:
        void start();
        void start(T,callbackFunction cb);
        void wait();
    protected:
        void run();
    private:
        std::thread mThread;
        callbackFunction mCb;
        T mData;
};

template<typename T>
void MyThread<T>::start(T data,callbackFunction cb)
{
    mData = std::move(data);
    mCb = cb;
    mThread = std::thread(&MyThread::run, this);
}

template<typename T>
void MyThread<T>::wait()
{
    mThread.join();
}

// thread function
template<typename T>
void MyThread<T>::run()
{
    mData++;
    std::this_thread::sleep_for(std::chrono::seconds(5)); //td::chrono::seconds(1)
    mCb(mData);
}

int processDataAsync(std::future<int> &data){

    int sum=0;
    int n =  data.get();
    for(int i=0 ;i<n;i++)
    {
        sum+=i;
    }
    return sum;
}


int main(void){
    std::cout<<" Main starts\n";
    std::map<int,int> lu ;//={1,2};
    lu.insert(std::pair<int,int>(1,2));
    lu.insert(std::pair<int,int>(0,1));
    std::cout<<lu[1];
    std::cout<<"\n 0,1"<<lu[0];
    std::cout<<lu[10];
    lu.insert(std::pair<int,int>(0,3));
    std::cout<<"\n 0,3"<<lu[0];
    std::vector<int> v = {1,2,3,4};
    auto s =  std::find(v.begin(),v.end(),2)!=v.end();
    std::cout<<" \n resu  "<<s<<"\n";



    std::promise<int> pr;
    std::future<int> f =  pr.get_future();

    std::future<int> recd =  std::async(std::launch::async, processDataAsync,std::ref(f));
    pr.set_value(10);
    auto data = recd.get();
    std::cout<<"data received is "<< data<<"\n";


    MyThread<int> t;

    auto cb  =  [](int d) { std::cout<< " data arrived is "<<d<<"Thread Id "<<std::this_thread::get_id()<<"\n";   };
    t.start(9,cb);

    std::cout<<" MainThread id:: "<<std::this_thread::get_id()<<"\n";
    int i=0;
    while(i++<10)
    std::cout<<" i am doing disco dance\n";



    t.wait();

    return 0;
}

