#ifndef QTTEST_H
#define QTTEST_H

#include <QObject>
#include <QDebug>

class Data :public QObject
{
  public:
    Data(QObject *parent = nullptr)
    {
        Q_UNUSED(parent)
    }

    Data(const Data &rhs)    
    {
        qDebug()<<" Data::copy Constructor";    
    }

    Data&  operator = (const Data &rhs)
    {
        qDebug()<<" Data::= operator";    
    }

    Data(Data &&rhs)
    {
        qDebug()<<" Data::move constuctor ";
    }

    Data & operator = (Data &&rhs)
    {
        qDebug()<<"Data::move operator";
    }

    QString mStr;
    int mInt;
    enum class Types
    {
       MANUAL,
       AUTOMATIC
    };

    Types mTypes;
};

class QtTest : public QObject
{
    Q_OBJECT
public:
    explicit QtTest(QObject *parent = nullptr);
signals:
    void sendMessage(Data *,QString *, QString,Data);
    void changeSomethinWithCRefs(const Data &);
    void changeSomethingWithCopy(Data);
public slots:
    void onMessageArrived(Data * ,QString *, QString , Data );
};


Q_DECLARE_METATYPE(Data)
#endif // QTTEST_H
