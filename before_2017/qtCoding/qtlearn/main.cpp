#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow w;



        QImage image("C:\\Users\\rsadhu\\Desktop\\desktop.jpg");

        QGraphicsPixmapItem item( QPixmap::fromImage(image));
        QGraphicsScene* scene = new QGraphicsScene;
        scene->addItem(&item);
        QGraphicsView view;
        view.setScene(scene);
        //view.show();
      w.setCentralWidget(&view);
      w.show();
    return a.exec();
}
