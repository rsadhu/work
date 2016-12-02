#include "rtspplayer.h"
#include "opencv\cv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include<qpainter.h>
#include<qevent.h>

using namespace cv;


rtspPlayer::rtspPlayer(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	m_netman = new QNetworkAccessManager(this);
	m_netman->setNetworkAccessible(QNetworkAccessManager::Accessible);
	connect(m_netman, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotReplyFinished(QNetworkReply*)));
	connect(m_netman, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(onAuthenticationRequestSlot(QNetworkReply*, QAuthenticator*)));
	QNetworkRequest netRequest(QUrl("http://10.0.0.9/stw-cgi/media.cgi?msubmenu=sessionkey&action=view"));
	QNetworkReply *netReply = m_netman->get(netRequest);
}

rtspPlayer::~rtspPlayer()
{

}



void rtspPlayer::onAuthenticationRequestSlot(QNetworkReply*aReply, QAuthenticator* aAuthenticator)
{
	aAuthenticator->setUser("admin");
	aAuthenticator->setPassword("admin12.");

}
void rtspPlayer::slotStateChanged(QMediaPlayer::State st)
{
	qDebug() << "Slotchange :: " << st;
}

void rtspPlayer::slotError(QMediaPlayer::Error er)
{
	qDebug() << "Error:: " << er;
}

#include<QMessageBox>

void rtspPlayer::slotReplyFinished(QNetworkReply *response)
{
	QByteArray data = response->readAll();	
	QString sessionId(data.toStdString().c_str());
	QString sId; 
	int f = 0;
	for (int i = 0; i < sessionId.size(); i++)
	{
		if (sessionId[i] == '=')
		{
			f = 1;
			i++;
		}
		if (1 == f)
			sId.append(sessionId[i]);
	}



	//QString str("rtsp://admin@admin12.@10.0.0.9:558/PlaybackChannel/0/media.smp/start=20161021T103000Z&end=20161021T113000Z&overlap=0&session=");
	QString str("rtsp://10.0.0.9:558/PlaybackChannel/0/media.smp/session=");
	str += sId;
	
	cv::VideoCapture capture(str.toStdString());


	if (capture.isOpened()) 
	{
		cv::namedWindow("TEST", CV_WINDOW_AUTOSIZE);
		cv::Mat frame;

		while (true) 
		{
			if (!capture.read(frame)) 
			{
				//Error
			}
			
			cv::imshow("TEST", frame);
			cv::waitKey(30);
		}
	}	
}

bool mousePressed = false;
bool drawStarted = false;
void rtspPlayer::mouseReleaseEvent(QMouseEvent *event)
{
	mousePressed = false;
	update();
}

void rtspPlayer::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.begin(this);
	painter.setPen(Qt::blue);
	QBrush brush(Qt::red, Qt::CrossPattern);

	if (mousePressed){
		painter.drawPixmap(0, 0, mPix);
		drawStarted = true;
		painter.drawRect(mRect);
	}

	else if (drawStarted){
		QPainter tempPainter(&mPix);
		tempPainter.drawRect(mRect);
		painter.drawPixmap(0, 0, mPix);
	}

	painter.fillRect(mRect, brush);
	painter.end();
}

#include<qlabel.h>

QLabel *l = 0;
void rtspPlayer::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		QString str = "coordinates are ::";
		int x, y, x1, y1;
		mRect.getCoords(&x, &y, &x1, &y1);

		str += "x: " + QString::number(x) + "y: " + QString::number(y) + "x1: " + QString::number(x1) + "y1: " + QString::number(y1);
		if (l)
			delete l;
		l = new QLabel(str,this);
		l->show();

	}
	else
	{
		mousePressed = true;
		mRect.setTopLeft(event->pos());
		mRect.setBottomRight(event->pos());
	}
}


void rtspPlayer::mouseMoveEvent(QMouseEvent* event)
{
	if (event->type() == QEvent::MouseMove)
	{
		mRect.setBottomRight(event->pos());
		update();
	}
}
