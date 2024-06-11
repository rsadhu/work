#ifndef DATA_PUBLISHER_H
#define DATA_PUBLISHER_H

#include <string>

class IPublisher
{
public:
    virtual void publish(std::string &) = 0;
    virtual ~IPublisher() {}
};

#endif //