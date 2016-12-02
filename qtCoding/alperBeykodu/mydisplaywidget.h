#ifndef MYDISPLAYWIDGET_H
#define MYDISPLAYWIDGET_H
#include<QWidget>
#include<QDrag>
#include<QMouseEvent>
#include<QMimeData>
#include<QDragMoveEvent>>
#include<QDropEvent>
#include<QDebug>
#include"alpervlcptr.h"



class MyDisplayWidget:public QWidget
{
public:
    MyDisplayWidget(QWidget *parent);
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
    void showLocalVideo(){ mVlc->play();}
    void pauseLocalVideo(){ mVlc->pause();}
    void showRtspStream(QUrl & url){ mVlc->playRtps(url);}
private:
    AlperVlcPtr *mVlc;
};

#endif // MYDISPLAYWIDGET_H
