#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgetdest.h"
#include<widgetsrc.h>
#include<QHBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;    
    WidgetDest *mDest;
    WidgetSrc *mSrc;
    QHBoxLayout *layout;
};

#endif // MAINWINDOW_H
