#include "testplugin.h"
#include <QDebug>

TestPlugin::TestPlugin(QObject *parent) : QObject(parent)
{
    m_listIntegers = {1, 2, 3, 4, 5, 6};
}

void TestPlugin::setThisProperty( int newProperty)
{
    if(m_thisProperty != newProperty)
    {
        m_thisProperty =  newProperty;
        emit thisPropertyChanged(m_thisProperty);
    }
}

int TestPlugin::thisProperty() const
{
    return m_thisProperty;
}

void TestPlugin::setobjectProperty(QVariant val)
{
    qDebug()<<"TestPlugin::C++::qvariantYpename:: >>  "<<val.typeName();
    m_objectProperty = val;
    emit objectPropertyChanged(val);
}

QVariant TestPlugin::objectProperty() const
{
    return m_objectProperty;
}

void TestPlugin::setListIntegers(QList<int> list)
{
    //std::move(list.begin(), list.end(), m_listIntegers);
    m_listIntegers = list;
}

QList<int> TestPlugin::listIntegers() const
{
    return m_listIntegers;
}
