#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QEvent>
#include<QMouseEvent>
#include<QDrag>
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QMimeData>
#include<QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

private:
    Ui::MainWindow *ui;
    QGridLayout *mGridLayout;
    QWidget *mCentralWidget;
};

#endif // MAINWINDOW_H
