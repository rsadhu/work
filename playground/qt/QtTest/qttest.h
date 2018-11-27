#ifndef QTTEST_H
#define QTTEST_H

#include <QObject>


class Data :public QObject
{
  public:
    Data(QObject *parent = nullptr)
    {
        Q_UNUSED(parent)
    }

    Data(const Data &rhs){}
    Data operator = (const Data &rhs){}

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
    void  sendMessage(Data *,QString *, QString,Data);
public slots:
    void onMessageArrived(Data * ,QString *, QString , Data );
};


Q_DECLARE_METATYPE(Data)
#endif // QTTEST_H
