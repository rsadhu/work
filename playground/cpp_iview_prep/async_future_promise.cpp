#include <iostream>
#include <future>
#include <algorithm>

class Worker
{
    std::future<std::string> result_;
    std::promise<std::string> input_;
    std::future<std::string> inp;
    public:
        Worker();
        virtual ~Worker()
        {

        }

        std::string  run(std::future<std::string> &);
        std::string getResult();
};


Worker::Worker()
{
    std::cout<<"\nWorker::Worker\n";
    inp =  input_.get_future();

    result_ =  std::async(std::launch::async, &Worker::run, this, std::ref(inp));


}

std::string Worker::run(std::future<std::string> &f)
{
    std::string str = f.get();
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);

    return str;
}

std::string  Worker::getResult()
{
    input_.set_value("Rakesh Sadhu");
    return result_.get();
}

int  main(void)
{
    Worker w;
    auto r = w.getResult();
    std::cout<<" value is "<< r<<"\n";
    return 0;
}