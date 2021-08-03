#include "ChatServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatServerPriv l_ChatServerPriv;
	return a.exec();
}
