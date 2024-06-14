#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QRandomGenerator>
#include <QObject>
#include <QWidget>
#include "zeromq_client.h"
#include <thread>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = nullptr);
    void setupScene();
    virtual ~MyGraphicsView();

public slots:
    void updatePositions();
    void slotDataReceived(myprotobuf::Position);

private:
    QGraphicsScene *scene{nullptr};
    QList<QGraphicsEllipseItem *> circles;
    QTimer *timer = nullptr;
    std::thread worker_;
    DataReceiver data_receiver_;
};

#endif // MYGRAPHICSVIEW_H
