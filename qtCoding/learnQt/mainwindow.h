#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<form1.h>
#include<form2.h>
#include<QDialog>
#include<QtWebKitWidgets/qwebview.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void testMixStuff();
    void setUpForms();

public slots:
    void slotSayHello(bool );
    void  slotTestWebView(bool );

private:
    Ui::MainWindow *ui;
    Form1 *m_Form1;
    Form2 *m_Form2;

    QAction * sayHello;
    QAction * openBrowser;
    QMenu *menu;
    QDialog tmpDialog;
    QWebView *mWebView;
};

#endif // MAINWINDOW_H
