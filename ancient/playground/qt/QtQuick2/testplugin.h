#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QObject>
#include <QVariant>

class AccessType: public QObject
{
    Q_OBJECT
    Q_PROPERTY(MyType type READ type WRITE setType NOTIFY  typeChanged)
public:
    enum class MyType
    {
        INT,
        STRING,
        VARIANT
    };

    void setType(MyType t) {
        m_type = t;
        emit typeChanged(t);
    }

    MyType type() const {
        return m_type;
    }

    Q_ENUMS(MyType);

signals:
    void typeChanged(MyType type);
private:
    MyType m_type =  MyType::INT;
};

class TestPlugin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int thisProperty READ thisProperty WRITE setThisProperty  NOTIFY thisPropertyChanged)
    Q_PROPERTY(QVariant  ObjectProperty READ objectProperty WRITE setobjectProperty  NOTIFY objectPropertyChanged)
    Q_PROPERTY(QList<int>  listIntegers READ listIntegers WRITE setListIntegers)
    //    Q_PROPERTY(MyType Type READ Type WRITE setType NOTIFY typeChanged)

public:
    explicit TestPlugin(QObject *parent = nullptr);
public:
    //property setters
    void setThisProperty(int newProperty);
    void setobjectProperty(QVariant val);
    void setListIntegers(QList<int> list);
    //  void setType(MyType type);

    //property getters
    int thisProperty() const;
    QVariant objectProperty() const;
    QList<int> listIntegers() const;
    //MyType Type() const;

signals:
    void thisPropertyChanged(int thisProperty);
    void objectPropertyChanged(QVariant objectProperty);
    //void typeChanged(MyType type);

private:
    int m_thisProperty=0;
    QVariant m_objectProperty;
    QList<int> m_listIntegers;
};

#endif // TESTPLUGIN_H
