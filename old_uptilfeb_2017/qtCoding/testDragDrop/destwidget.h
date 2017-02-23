#ifndef DESTWIDGET_H
#define DESTWIDGET_H

#include <QWidget>
#include<QDrag>
#include<QMouseEvent>
#include<QMimeData>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPixmap>
#include"mygraphicsviewclass.h"



class DestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DestWidget(QWidget *parent = 0);
public:
    void dragEnterEvent(QDragEnterEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void receivePixMap(QPixmap *);
    ~DestWidget()
    {
        qDebug()<<"DestWidget::~DestWidget\n";
        delete mView;
        delete mScene;
        delete mPixmap;
    }
private:
    QGraphicsView *mView;
    QGraphicsScene *mScene;
    QPixmap *mPixmap;
};

#endif // DESTWIDGET_H
