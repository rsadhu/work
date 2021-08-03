#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QAction>
#include<QMenu>
#include<QPlainTextEdit>
#include<QWebview>
#include<QWebFrame>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *);
    void createUi();
public slots:
    void openPage();
    void loadStarted();
    void loadFinished(bool);
private:
QMenu *menu;
QAction *open,*play,*pause;
QPlainTextEdit *addressbar;
QWebView *webview;
};

#endif // MAINWINDOW_H
