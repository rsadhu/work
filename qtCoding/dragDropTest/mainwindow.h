#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QEvent>
#include<QMouseEvent>
#include<QDrag>
#include<QDropEvent>
#include<QMimeData>


namespace Ui {
class MainWindow;
}

#define NPICS 2
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *mEvent);
    void mouseMoveEvent(QMouseEvent *mEvent);
    void dragMoveEvent(QDragMoveEvent *dragmoveEvent);
    void dropEvent(QDropEvent *dropEvent);

protected:
    void init();
private:
    QGraphicsScene *mScene[NPICS];
    QImage *mImages[NPICS];
    QGraphicsPixmapItem *mPixmapItems[NPICS];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
