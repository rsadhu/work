
//  Weather update client in C++
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
//

#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

void example()
{
    zmq::context_t context(1);

    //  Socket to talk to server
    std::cout << "Collecting updates from weather server...\n"
              << std::endl;
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");

    //  Subscribe to zipcode, default is NYC, 10001
    // const char *filter = (argc > 1) ? argv[1] : "10001 ";
    subscriber.set(zmq::sockopt::subscribe, "");

    //  Process 100 updates
    int update_nbr;
    long total_temp = 0;
    for (update_nbr = 0; update_nbr < 100; update_nbr++)
    {

        zmq::message_t update;
        int zipcode, temperature, relhumidity;

        subscriber.recv(update, zmq::recv_flags::none);

        std::istringstream iss(static_cast<char *>(update.data()));
        iss >> zipcode >> temperature >> relhumidity;

        total_temp += temperature;
    }
}

int main(int argc, char *argv[])
{
    zmq::context_t context(1);

    //  Socket to talk to server
    std::cout << "Collecting updates from weather server...\n"
              << std::endl;
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");

    subscriber.set(zmq::sockopt::subscribe, "");

    while (true)
    {
        zmq::message_t update;
        std::string data;

        subscriber.recv(update, zmq::recv_flags::none);

        std::cout << update.str() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}