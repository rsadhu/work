#ifndef RTSPPLAYER_H
#define RTSPPLAYER_H

#include <QtWidgets/QWidget>
#include<QNetWorkReply.h>
#include<QAuthenticator>
#include<QNetworkAccessManager>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include<QUrl>
#include "ui_rtspplayer.h"

class rtspPlayer : public QWidget
{
	Q_OBJECT

public:
	rtspPlayer(QWidget *parent = 0);
	~rtspPlayer();
public slots:
	void slotReplyFinished(QNetworkReply *);	
	void onAuthenticationRequestSlot(QNetworkReply*, QAuthenticator*);
	
	void slotError(QMediaPlayer::Error);
	void slotStateChanged(QMediaPlayer::State);
protected:
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QPixmap mPix;
	QRect mRect;

private:
	QNetworkAccessManager *m_netman;
	QNetworkReply *m_netReply;
private:
	Ui::rtspPlayerClass ui;
};

#endif // RTSPPLAYER_H
