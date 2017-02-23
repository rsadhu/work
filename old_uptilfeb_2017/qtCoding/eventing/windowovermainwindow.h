#ifndef WINDOWOVERMAINWINDOW_H
#define WINDOWOVERMAINWINDOW_H
#include<mainwindow.h>
#include <QObject>
#include<QDebug>

class windowOverMainWindow : public MainWindow
{
public:
    windowOverMainWindow();

    void mousePressEvent(QMouseEvent *event);
   // bool event(QEvent *event);
};

#endif // WINDOWOVERMAINWINDOW_H
