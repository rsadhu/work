#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>

namespace Ui {
class MainWindow;
}

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
  //  bool event(QEvent *);
public slots:
    void slotSwapDisplays();
private:
    void init();
    Ui::MainWindow *ui;
    QImage *mImage1,*mImage2;
    QGraphicsScene *scene1,*scene2;
};

#endif // MAINWINDOW_H

#ifdef test
bool MainWindow::event(QEvent *qEvent)
{
    bool ret(false);
    switch(qEvent->type())
    {
    case QEvent::DragEnter:
        qDebug()<<" dragEnter Event\n";
                  break;
    case QEvent::DragLeave:
        qDebug()<<"DragLeave Event\n";
        break;
    case QEvent::DragMove:
            qDebug()<<"DragMove Event\n";
            break;
    case QEvent::DragResponse:
        qDebug()<<"DragResponse Event\n";
        break;
    }
    return ret;
}
#endif
