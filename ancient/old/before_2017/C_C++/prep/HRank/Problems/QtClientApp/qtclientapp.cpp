#include "qtclientapp.h"
#include <QGraphicsScene>

QtClientApp::QtClientApp(QString host, QString datatobewritten, int portNumber, QWidget *parent)
	: QWidget(parent), mIsConnected(false), isReadFromServer(false)
{
	ui.setupUi(this);
	connect(&mClient, SIGNAL(connected()), this, SLOT(slotIsConnectedToHost()));
	connect(&mClient, SIGNAL(readyRead()), SLOT(slotReadyRead()));
	connect(ui.Connect, SIGNAL(clicked()), this, SLOT(slotConnectToHost()));
	connect(ui.SendData, SIGNAL(clicked()), this, SLOT(slotWriteDate()));
	mHostAddress = host;
	mDataToBeWritten = datatobewritten;
	mPortNumber = portNumber;
}

QtClientApp::~QtClientApp()
{
}

void QtClientApp::slotWriteDate()
{
	if (mIsConnected)
		mClient.write(mDataToBeWritten.toStdString().c_str(), mDataToBeWritten.size());
}

void QtClientApp::slotReadyRead()
{
	if (!isReadFromServer)
	{
		ui.wDisplay->setStyleSheet("background-color:white;");
		int sz = mClient.size();
		QByteArray rData = mClient.readAll();
		QImage img((uchar *)rData.data(), 1024, 768, QImage::Format_RGB32);

		QGraphicsScene *scene = new QGraphicsScene(ui.wDisplay);
		scene->addPixmap(QPixmap::fromImage(img));
		scene->setSceneRect(img.rect());
		isReadFromServer = true;
	}
}

void QtClientApp::slotConnectToHost()
{
	mClient.connectToHost(mHostAddress, mPortNumber);
}

void QtClientApp::slotIsConnectedToHost()
{
	mIsConnected = true;
	ui.wDisplay->setStyleSheet("background-color:red;");
}