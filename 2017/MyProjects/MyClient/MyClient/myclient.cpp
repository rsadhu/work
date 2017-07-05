#include "myclient.h"
#include<qnetworkinterface.h>

MyClient::MyClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	mClientSocket = new QTcpSocket(this);
	mClientSocket->connectToHost("127.0.0.1", 27482);
	connect(mClientSocket, &QTcpSocket::connected, [=]()
	{
		g_connected = true;
	});

	connect(mClientSocket, &QTcpSocket::readyRead, [=]()
	{
		ui.label->setText(mClientSocket->readAll());
	});
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotSendData()));
	
	for (auto inter : QNetworkInterface::allAddresses())
	{			
		mIp = inter.toString();
		mPort = QString::number(27483);		
		break;
	}
}

MyClient::~MyClient()
{

}


void MyClient::slotSendData()
{
	QByteArray data;
	data.append(mIp);
	data.append(":"+mPort);
	mClientSocket->write(data);
}