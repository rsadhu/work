#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<destwidget.h>
#include<srcwidget.h>
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
    void init();
private:
    Ui::MainWindow *ui;
    QWidget *mCentralWidget;
    DestWidget *mDestWidget;
    SrcWidget  *mSrcWidget;
    QHBoxLayout *mLayout;
};

#endif // MAINWINDOW_H
