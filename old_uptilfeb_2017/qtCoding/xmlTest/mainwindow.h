#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QtXML>

namespace Ui {
class MainWindow;
}

class MainWindow : public  QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void retrievElements(QDomElement root,QString tag, QString att);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
