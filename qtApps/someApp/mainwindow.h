#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebView>
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
    void openPage(char *url);
public slots:
    void loadPage(); // slot attached to GO button
    void openPreviousUrl() ;// slot attached to backward button
    void openNextUrl(); // slot attached to forward button;

    void pageLoaded(bool);
    void pageLoading(int);    
    void pageLoadStarted();
    void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui;
    QWebView *mView;
    QPushButton *mGo,*mForward,*mBackward,*mRefresh;
    QList<QUrl> listofUrls;
    int mIndex;

};

#endif // MAINWINDOW_H
