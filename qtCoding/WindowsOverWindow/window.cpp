#include "window.h"


Window::Window(QWidget *parent):QWidget(parent)
{
  parent?parent->setStyleSheet("background-color:rgb(0,0,0);"):qDebug()<<"parent is null";
}


void Window::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init (this);
    QPainter p (this);
    style ()->drawPrimitive (QStyle::PE_Widget, &opt, &p, this);
}
