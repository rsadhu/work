#ifndef __BASE__
#define __BASE__
#include <QObject>
#include<QGraphicsView>
#include<QImage>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QDebug>
#include<QWidget>

class  Base: public QGraphicsView
{
    Q_OBJECT
public:
    Base(QWidget *parent):QGraphicsView(parent){}
    void init(QGraphicsScene *scene, QGraphicsPixmapItem *item, QImage *img);
private:
    QImage *mImage;
    QGraphicsPixmapItem *mPixmapItem;
    QGraphicsScene *mScene;
};
#endif
