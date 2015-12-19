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

class SrcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SrcWidget(QWidget *parent = 0);
signals:
public slots:
public:
    void mousePressEvent(QMouseEvent *);
    //void dragLeaveEvent(QDragLeaveEvent *);
    void dragEnterEvent(QDragEnterEvent *);

private:
    QGraphicsView *mView;
    QGraphicsScene *mScene;
    QPixmap *mPixmap;
    QGraphicsPixmapItem *mPixmapItem;
};

#endif // SRCWIDGET_H
