#ifndef CUSTOMPLUGIN_H
#define CUSTOMPLUGIN_H

#include <QObject>


class CustonPlugin;

class CustomPlugin:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
public:
    CustomPlugin();
    void start();

    static CustomPlugin*  getInstance();

public slots:
    QString status() const
    {
        return m_status;
    }
    void setStatus (QString status)
    {
        m_status =  status;
        emit statusChanged(status);
    }
signals:
    void doSomething();
    void statusChanged(QString status);
    void changeStatus(QString status);

public slots:
    void onSomething();
    void onCallFromQml(QString status);

private:
    QString m_status = "none";
};

#endif // CUSTOMPLUGIN_H
