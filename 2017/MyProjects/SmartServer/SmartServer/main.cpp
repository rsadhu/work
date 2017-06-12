
#include <QtCore/QCoreApplication>
#include"tcpserver.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	TcpServer ts;

	return a.exec();
}
