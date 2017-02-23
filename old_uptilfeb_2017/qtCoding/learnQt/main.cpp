#include "mainwindow.h"
#include <QApplication>
#include<QTextEdit>
#include<QPushButton>
#include<QLayout>
#include<QWidget>
#include<QDialog>
#include<QAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
