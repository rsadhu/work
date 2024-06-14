#include "graphicsview.h"
#include "../src/schemas/position.pb.h"
#include <QDebug>
#include "zeromq_Client.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, 100, 100, this);
    setScene(scene);
    setupScene();

    // timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &MyGraphicsView::updatePositions);
    // timer->start(1000); // Update positions every 100 ms
    connect(&data_receiver_, &DataReceiver::sendData, this, &MyGraphicsView::slotDataReceived);

    worker_ = std::thread([this]
                          { data_receiver_.run(); });
}

void MyGraphicsView::slotDataReceived(myprotobuf::Position position)
{
    static int cnt = 0;

    circles[cnt++ % 10]->setPos(position.position_m().x(), position.position_m().y());
}

MyGraphicsView::~MyGraphicsView()
{
    worker_.join();
}

void MyGraphicsView::setupScene()
{

    std::map<int, QColor> colorMap;

    // Initialize the map with ten elements
    colorMap[0] = Qt::blue;
    colorMap[1] = Qt::red;
    colorMap[2] = Qt::green;
    colorMap[3] = Qt::yellow;
    colorMap[4] = Qt::cyan;
    colorMap[5] = Qt::magenta;
    colorMap[6] = Qt::gray;
    colorMap[7] = Qt::black;
    colorMap[8] = Qt::white;
    colorMap[9] = Qt::darkBlue;

    for (int i = 0; i < 10; ++i)
    {
        int x = QRandomGenerator::global()->bounded(100);
        int y = QRandomGenerator::global()->bounded(100);
        QGraphicsEllipseItem *circle = scene->addEllipse(x, y, 5, 5, QPen(), colorMap[i]);
        circles.append(circle);
    }
}

// void MyGraphicsView::updatePositions()
// {

// }
