#ifndef TESTQTQML_H
#define TESTQTQML_H
#include<QObject>



class  KVR : public QObject
{
    Q_OBJECT
public:

    KVR(QObject *parent = nullptr);

    Q_SIGNAL void changeAddress(QString address);

    Q_SLOT  void onAddressChanged(QString address);
private:
    QString m_addr;
};



class TestQtQml : public QObject
{
    Q_OBJECT
public:
    TestQtQml();

    void fire()
    {
        QString test("hello how are you!!");
        emit changeAddress(test);
    }
    Q_SIGNAL void changeAddress(QString address);

private:
    KVR m_kvr;
};


#endif // TESTQTQML_H
