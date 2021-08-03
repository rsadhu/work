#include "myclient.h"
#include<qnetworkinterface.h>
#include<qbuffer.h>

QByteArray data;
MyClient::MyClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	mClientSocket = new QTcpSocket(this);
	mClientSocket->setSocketDescriptor(10);
	mClientSocket->connectToHost("127.0.0.1", 27482);
	connect(mClientSocket, &QTcpSocket::connected, [=]()
	{
		g_connected = true;
	});

	connect(mClientSocket, &QTcpSocket::readyRead, [=]()
	{		
		QByteArray d  = mClientSocket->readAll();
		QStringList list = QString(d).split(':');
		
		for (auto it : list)
		{

		}
		data += d;
		if (mClientSocket->bytesAvailable() == 0)
		{
			QPixmap *pix1 = new QPixmap();
			pix1->loadFromData(data);


			QPixmap *pix = new QPixmap("D:\\rsadhu\\work_git\\2017\\MyProjects\\SmartServer\\SmartServer\\dp.jpg");
			if (!pix1->isNull())
				ui.label->setPixmap(*pix1);
			else
			{
				qDebug() << "pixmap is nuull";
			}
		}
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
	/*data.append(mIp);
	data.append(":"+mPort);*/
	data.append("foto");
	mClientSocket->write(data);
}