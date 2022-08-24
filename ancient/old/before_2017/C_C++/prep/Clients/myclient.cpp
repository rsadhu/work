#include "myclient.h"
#include <qlabel.h>
#include <System.h>

MyClient::MyClient(QWidget *parent)
	: QWidget(parent)
{
	init();
	mVLayout = new QVBoxLayout(this);

	QLabel *userName = new QLabel(this);
	userName->setText(tr("UserName:"));

	mTextEditorUserName = new QLineEdit(this);
	mTextEditorUserName->setFixedHeight(25);

	mTextEditorPassWord = new QLineEdit(this);
	mTextEditorPassWord->setFixedHeight(25);

	QLabel *passWord = new QLabel(this);
	passWord->setText(tr("Password:"));

	mButton = new QPushButton(this);

	mVLayout->addWidget(userName);
	mVLayout->addWidget(mTextEditorUserName);
	mVLayout->addWidget(passWord);

	mVLayout->addWidget(mTextEditorPassWord);

	mVLayout->addWidget(mButton);
	mButton->setText("Send");

	setTabOrder(mTextEditorUserName, mTextEditorPassWord);
	setTabOrder(mTextEditorPassWord, mButton);
	setTabOrder(mButton, mTextEditorUserName);

	connect(mButton, SIGNAL(clicked(bool)), this, SLOT(slotSendToServer()));
}

MyClient::~MyClient()
{
	delete mClient;
}

void MyClient::init()
{
	mClient = new QTcpSocket();
	mClient->connectToHost("10.0.0.221", 1234, QTcpSocket::ReadWrite);
	if (!mClient->isValid())
	{
	}
	else
	{
		connect(mClient, SIGNAL(readyRead()), this, SLOT(slotReadFromServer()));
		connect(mClient, SIGNAL(disconnect()), this, SLOT(slotDisconnect()));

		mTimer = new QTimer();
		connect(mTimer, SIGNAL(timeout()), this, SLOT(slotSendDateAsJsOn()));
		mTimer->start(1 * 60 * 1000);
	}
}

void MyClient::slotReadFromServer()
{
	if (mClient)
	{
		if (mClient->isValid())
		{
			QByteArray data = mClient->readAll();
			qDebug() << " \ndata received ::" << data;
		}
	}
}

void MyClient::slotSendToServer()
{
	if (mClient)
	{
		QByteArray data;

		data = "testing ";

		mClient->write(data);
		mClient->flush();
	}
}

void MyClient::slotSendDateAsJsOn()
{

	if (mClient)
	{
		System s;
		s.GetProcessList();
		QString ss;
		char ram[100];
		itoa(s.getTotalSystemMemory() / (1024 * 1024), ram, 10);
		s.GetDiskSpace();

		ss = "RAM SIZe: ";
		ss += ram;

		char ram1[100];
		int hddSize = s.GetDiskSpace();
		memset(ram1, 0, 100);

		itoa(hddSize, ram1, 10);
		ss += ";HardDisk SIZE::";
		ss += ram1;

		QByteArray send;
		send.setRawData(ss.toStdString().c_str(), ss.length());
		qDebug() << " date to be written:: " << ss;
		mClient->write(send);
		mClient->flush();
	}
}

void MyClient::slotDisconnect()
{
	qDebug() << "Socket:: Disconnecting\n";
	delete mClient;
}

void MyClient::wheelEvent(QWheelEvent *event)
{
	qDebug() << " qwheel event caught here...\n";
}