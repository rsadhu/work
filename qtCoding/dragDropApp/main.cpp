#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
#ifdef Test
    QGraphicsView view;
    QGraphicsScene scene;
    //QImage img("/home/rsadhu/Desktop/chick.jpg");
    QImage img("/home/rsadhu/Desktop/horse.jpg");
    QGraphicsPixmapItem *item =  new QGraphicsPixmapItem(QPixmap::fromImage(img));
    scene.addItem(item);
    view.setScene(&scene);
    view.show();
#endif

    return a.exec();
}
