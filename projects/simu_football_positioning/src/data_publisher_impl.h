#ifndef DATA_PUBLISHER_IMPL_H
#define DATA_PUBLISHER_IMPL_H

#include "data_ipublisher.h"
#include <zmq.hpp>

class Publisher : public IPublisher
{
public:
    Publisher()
    {
        socket_.bind("tcp://*:5556");
    }

    void publish(const std::string &buf) override;

private:
    zmq::context_t context_{1};
    zmq::socket_t socket_{context_, zmq::socket_type::pub};
};
#endif // DATA_PUBLISHER_IMPL_H