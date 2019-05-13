#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include<QAbstractItemModel>
#include<QDebug>

class EmployeeCard : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int eId READ id)
    Q_PROPERTY(QString eName READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString eAddr READ addr WRITE setAddr NOTIFY addrChanged)

public:
    EmployeeCard(QObject *parent=nullptr);

    int id() const  { return m_empId; }

    QString name() const  { return m_empName; }
    void setName(const QString name) {
        if(m_empName != name)
        {
            m_empName = name;
            emit nameChanged(m_empName);
        }
    }

    QString addr() const  { return m_empAddr; }
    void setAddr(const QString name) {
        if(m_empAddr != name){
            m_empAddr = name;
            emit addrChanged(m_empAddr);
        }
    }

    Q_INVOKABLE void fireCall() {
        QString d = " this is a test data ";
        emit fireHandler(d);
    }
signals:
    void nameChanged(QString name);
    void addrChanged(QString addr);
    void fireHandler(QString data);

public:
    int m_empId;
    QString m_empName;
    QString m_empAddr;
};


class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATAMODEL_H
