#include "mainwindow.h"
#include <QApplication>

#include<srcwidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  /*  QGraphicsView view;
    QGraphicsScene scene;
    QPixmap pixmap("C:\\Users\\rsadhu\\Desktop\\despicable.jpg");
    scene.addPixmap(pixmap);
    view.setScene(&scene);
    view.show();*/
    return a.exec();
}
