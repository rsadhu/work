
#include <zmq.hpp>
#include "zeromq_client.h"

DataReceiver::DataReceiver(QObject *parent) : QObject(parent)
{
}

DataReceiver::~DataReceiver()
{
}

void DataReceiver::run()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    zmq::context_t context(1);

    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");

    subscriber.set(zmq::sockopt::subscribe, "");

    while (true)
    {
        zmq::message_t update;
        subscriber.recv(update, zmq::recv_flags::none);

        // Now, let's deserialize the string back to a Position message
        myprotobuf::Position position;

        std::string str = update.to_string();
        position.ParseFromString(str);

        // std::cout << "Deserialized Position message:" << std::endl;
        // std::cout << "pos.x: " << position.position_m().x() << std::endl;
        // std::cout << "pos.y: " << position.position_m().y() << std::endl;
        // std::cout << "pos.z: " << position.position_m().z() << std::endl;
        // std::cout << "sensor_id: " << position.sensorid() << std::endl;
        // std::cout << "timestamp: " << position.timestamp_ms() << std::endl;
        emit this->sendData(position);
    }

    google::protobuf::ShutdownProtobufLibrary();
}
