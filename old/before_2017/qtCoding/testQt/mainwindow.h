#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QPushButton>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void transferContent();
private:
    Ui::MainWindow *ui;
    QHBoxLayout * layout;
    QWidget *centralWidget;
    QWidget *oneWidget;
};

#endif // MAINWINDOW_H
