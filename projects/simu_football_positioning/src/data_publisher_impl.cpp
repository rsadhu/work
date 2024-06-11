#include "data_publisher_impl.h"

void Publisher::publish(std::string &message)
{
    zmq::message_t zmqMessage(message.size());
    memcpy(zmqMessage.data(), message.data(), message.size());
    socket_.send(zmqMessage, zmq::send_flags::none);
}