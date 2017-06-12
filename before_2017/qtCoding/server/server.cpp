#include "server.h"

MyServer::MyServer()
{
  server =  new QTcpServer();
  QObject::connect(server, SIGNAL(newConnection()), this,SLOT(newConnection()));
}


void MyServer::newConnection()
{
    //QTcpSocket socket(this);
}



