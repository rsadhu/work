#ifndef WINDOW_H
#define WINDOW_H
#include<QWidget>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QDebug>
#include<QPainter>
#include<QStyleOption>
#include<QResizeEvent>

class Window:public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parent=0);
 /*   void mousePressEvent(QMouseEvent *event)
    {
        qDebug()<<"Window::mousePressEvent()::    "<<this<<endl;
    }*/
    void setStyle(int colour=0)
    {
        setStyleSheet("background-color:rgb(0,255,255);");
    }

    void paintEvent(QPaintEvent *);
};

#endif // WINDOW_H
