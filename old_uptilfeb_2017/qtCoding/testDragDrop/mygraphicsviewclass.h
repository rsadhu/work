#ifndef MYGRAPHICSVIEWCLASS_H
#define MYGRAPHICSVIEWCLASS_H

#include <QWidget>
#include<QDrag>
#include<QMouseEvent>
#include<QMimeData>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPixmap>
#include<QList>
#include<QDebug>

//template<typename T>
class MyGraphicsViewClass : public QGraphicsView
{
public:
    MyGraphicsViewClass();

    //void registerYourSelf(T *);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private:
  //  QList<T> mList;
    QGraphicsScene mScene;
    QPixmap mPixmap;
};

#endif // MYGRAPHICSVIEWCLASS_H
