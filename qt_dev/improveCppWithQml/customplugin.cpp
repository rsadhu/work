#include "customplugin.h"
#include <QDebug>



CustomPlugin *
CustomPlugin::getInstance()
{
    static CustomPlugin s_instance;
    return &s_instance;
}


CustomPlugin::CustomPlugin():m_status("Hello")
{
 connect(this, &CustomPlugin::doSomething, this, &CustomPlugin::onSomething);
 connect(this, &CustomPlugin::changeStatus, this , &CustomPlugin::onCallFromQml);
 connect(this, &CustomPlugin::statusChanged, [](QString str){
     qDebug()<<"From Property signal "<<str;
 });
}


void CustomPlugin::start()
{
     doSomething();
}

void CustomPlugin::onCallFromQml(QString status)
{
    qDebug()<<"CustomPlugin::onCallFromQml::"<< status<<"\n";
}


void CustomPlugin::onSomething()
{
    qDebug()<<"CustomPlugin::onsomething\n";
}
