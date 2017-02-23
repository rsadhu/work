#ifndef SRCWIDGET_H
#define SRCWIDGET_H

#include <QWidget>
#include<QPixmap>
#include<QDrag>
#include<QMouseEvent>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QImage>
#include<QMimeData>
#include<QGraphicsPixmapItem>
#include<QDebug>

class SrcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SrcWidget(QWidget *parent = 0);
public:
    void mousePressEvent(QMouseEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dragEnterEvent(QDragEnterEvent *);   
    void dropEvent(QDropEvent *event);
    void receivePixMap(QPixmap *);
    ~SrcWidget()
    {
        qDebug()<<"SrcWidget::~SrcWidget\n";
        delete mView;
        delete mScene;
        delete mPixmap;
    }
private:
    QGraphicsView *mView;
    QGraphicsScene *mScene;
    QPixmap *mPixmap;  
};

#endif // SRCWIDGET_H
