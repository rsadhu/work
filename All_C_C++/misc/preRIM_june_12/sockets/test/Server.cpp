#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<strings.h>

#include<iostream>
using namespace std;


typedef enum 
{
	SEND,
	RECEIVE
}Type;


class Server
{
	Server()
	{
		init();
	}
	Server(const Server &);
	Server & operator =(const Server &);
	void init();
	public:
	static Server * createSocket()
	{ 
		if(!m_Server)
			m_Server = new Server();
		return m_Server;
	}
	static void deleteSocket()
	{
		delete m_Server;
	}
	void sendReceive(Type);
	private:
	static Server *m_Server;
	static int m_socket_id;
};

Server * Server::m_Server = 0;
int Server::m_socket_id=0;


void Server::init()
{
	m_socket_id = socket(AF_INET,SOCK_STREAM,0);
	cout<<"Server::Server::Socket Created\n"<<m_socket_id<<endl ;

	sockaddr_in serverAddr;
	sockaddr & serverAddrCast = (sockaddr &) serverAddr;	
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port =  htons(13);

	bind(m_socket_id, &serverAddrCast,sizeof(serverAddr));

	listen(m_socket_id,5);
}



void Server::sendReceive(Type t)
{
	char buff[256];
	int rData=0;
	int connectSd =  accept(m_socket_id,(sockaddr*)0,0);
	cout<<"Server::sendReceive::Accept :: "<<connectSd;

	switch(t)
	{
		case SEND:
			break;
		case RECEIVE:
			rData  = read(connectSd,buff,sizeof(buff));
			break;
	}
}



int main(void)
{
	Server *serSocket  = Server::createSocket();
	serSocket->sendReceive(RECEIVE);
	return 0;
}
