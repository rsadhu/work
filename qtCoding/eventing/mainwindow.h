#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>

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
   // bool event(QEvent *event);
public slots:
    void openAnotherMenu();

    void moveContentToAnotherWidget();



private:
      Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
