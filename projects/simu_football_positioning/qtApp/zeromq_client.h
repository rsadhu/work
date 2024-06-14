#ifndef ZEROMQ_CLIENT_H
#define ZEROMQ_CLIENT_H

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

#include <QObject>

#include "../src/schemas/position.pb.h"

class DataReceiver : public QObject
{
    Q_OBJECT
public:
    DataReceiver(QObject *parent = nullptr);
    ~DataReceiver();
    void run();
signals:
    void sendData(myprotobuf::Position);
};
#endif //
       // ZEROMQ_CLIENT_H