#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QObject>
#include <QVariant>

class TestPlugin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int thisProperty READ thisProperty WRITE setThisProperty  NOTIFY thisPropertyChanged)
    Q_PROPERTY(QVariant  ObjectProperty READ objectProperty WRITE setobjectProperty  NOTIFY objectPropertyChanged)
    Q_PROPERTY(QList<int>  listIntegers READ listIntegers WRITE setListIntegers)

public:
    explicit TestPlugin(QObject *parent = nullptr);
public:
    //property setters
    void setThisProperty(int newProperty);
    void setobjectProperty(QVariant val);
    void setListIntegers(QList<int> list);
    //property getters
    int thisProperty() const;
    QVariant objectProperty() const;
    QList<int> listIntegers() const;

signals:
    void thisPropertyChanged(int thisProperty);
    void objectPropertyChanged(QVariant objectProperty);

private:
    int m_thisProperty=0;
    QVariant m_objectProperty;
    QList<int> m_listIntegers;
};

#endif // TESTPLUGIN_H
