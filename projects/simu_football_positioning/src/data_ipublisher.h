#ifndef I_DATA_PUBLISHER_H
#define I_DATA_PUBLISHER_H

#include <string>

class IPublisher
{
public:
    virtual void publish(const std::string &) = 0;
    virtual ~IPublisher() {}
};

#endif // I_DATA_PUBLISHER_H