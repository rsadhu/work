#ifndef DESTWIDGET_H
#define DESTWIDGET_H

#include <QWidget>
#include<QDrag>
#include<QMouseEvent>
#include<QMimeData>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QPixmap>


class DestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DestWidget(QWidget *parent = 0);

signals:
public slots:

public:
    void dragEnterEvent(QDragEnterEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *event);
private:
    QGraphicsView *mView;
    QGraphicsScene *mScene;
    QPixmap *mPixmap;
};

#endif // DESTWIDGET_H
