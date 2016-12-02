#include "windowovermainwindow.h"

windowOverMainWindow::windowOverMainWindow()
{

}




void windowOverMainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"windowOverMainWindow::mousePressEvent\n";
    //MainWindow::mousePressEvent(event);
}

/*bool windowOverMainWindow:: event(QEvent *event)
{
// qDebug()<<"windowOverMainWindow::event\n";
  // MainWindow::event(event);
   return false;
}*/
