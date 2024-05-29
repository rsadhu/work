#include <iostream>

#include <ecal/ecal.h>
#include <ecal/ecal_publisher.h>

const std::string topic_name = "test.distrubted.systems";

int main(int argc, char** argv)
{
    // initialize eCAL API
    eCAL::Initialize(argc, argv, "client_code");


    // new publisher
    eCAL::CPublisher pub(topic_name);

    std::vector<std::string> list = { "namskaar", "hello", "selam", "satsriakal", "harigato", "merhaba" };
    int i = 0;
    int sz = list.size();
    while (eCAL::Ok())
    {
        // send buffer
        pub.Send(list[i++ % sz]);

        // sleep 100 ms
        eCAL::Process::SleepMS(2000);

    }

    // finalize eCAL API
    eCAL::Finalize();

    return 0;
}
