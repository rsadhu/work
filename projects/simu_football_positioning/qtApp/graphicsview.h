#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QRandomGenerator>
#include <QObject>
#include <QWidget>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget *parent = nullptr);

    void setupScene();
    virtual ~MyGraphicsView();

public slots:
    void updatePositions();

private:
    QGraphicsScene *scene{nullptr};
    QList<QGraphicsEllipseItem *> circles;
    QTimer *timer = nullptr;
};

#endif // MYGRAPHICSVIEW_H
