#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <qtimer.h>

class MyClient : public QWidget
{
    Q_OBJECT
public:
    MyClient(QWidget *parent = 0);
    ~MyClient();
    void wheelEvent(QWheelEvent *);

private:
    void init();
public slots:
    void slotReadFromServer();
    void slotSendToServer();
    void slotDisconnect();
    void slotSendDateAsJsOn();

private:
    QTcpSocket *mClient;
    QPushButton *mButton;
    QVBoxLayout *mVLayout;
    QLineEdit *mTextEditorUserName;
    QLineEdit *mTextEditorPassWord;
    QTimer *mTimer; // = new QTimer(this);
};

#endif // MYCLIENT_H
