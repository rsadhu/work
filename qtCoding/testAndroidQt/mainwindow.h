#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtWebView/QtWebView>
#include<QWebView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void openPage(char *url);
public slots:
    void pageLoaded(bool);
    void pageLoading(int);
    void pageLoadStarted();
private:
    Ui::MainWindow *ui;
    QWebView *mView;
};

#endif // MAINWINDOW_H
