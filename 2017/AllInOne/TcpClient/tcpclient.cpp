#include "tcpclient.h"
#include<qtextedit.h>

TcpClient::TcpClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->hide();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotSendData()));
	mSocket = new QTcpSocket();
	mSocket->connectToHost("10.0.0.233", 27482);
	connect(mSocket, SIGNAL(connected()), this, SLOT(slotIamConnected()));
	connect(mSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));	
}

TcpClient::~TcpClient()
{
	delete mSocket;
}


void TcpClient::slotIamConnected()
{
	ui.pushButton->show();
}

void TcpClient::slotError(QAbstractSocket::SocketError err)
{

}

void TcpClient::slotSendData()
{
	QByteArray d = ui.textEdit->toPlainText().toStdString().c_str();;
	mSocket->write(d);
}