#pragma once
#include<qtcpserver.h>
#include<qtcpsocket.h>
#include<QThread>

class ChatClientConnection :public QThread
{
	Q_OBJECT
public:
	ChatClientConnection(int);
	ChatClientConnection();
	void run();
	QTcpSocket *m_Socket = nullptr;
	int  m_SocketDescriptor = 0;
};
class ChatServerPriv :public QTcpServer
{
	Q_OBJECT
public:
	ChatServerPriv();
	~ChatServerPriv();
private:
	void incomingConnection(qintptr  socketDescriptor);
private:
	std::map<uint, QTcpSocket> m_LookUpChatClients;
};
