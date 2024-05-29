#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

#include <ecal/ecal.h>
#include <ecal/ecal_publisher.h>

const std::string topic_name = "test.distrubted.systems";

int main(int argc, char** argv)
{
    // initialize eCAL API
    eCAL::Initialize(argc, argv, "client_code");


    // new publisher
    eCAL::CSubscriber sub(topic_name);

    sub.AddReceiveCallback([](const char* topic_name_, const struct eCAL::SReceiveCallbackData* data_) {
        std::stringbuf buf;
        buf.sputn((char*)data_->buf, data_->size);        
        std::cout << "\n" << buf.str();
        });

    while (eCAL::Ok()) std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    // finalize eCAL API
    eCAL::Finalize();

    return 0;
}