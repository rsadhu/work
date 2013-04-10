#include"../inc/layout.h"
#include<QDebug>

Layout::Layout()
{
    m_hlayout =  new QHBoxLayout();
    qDebug()<<"Layout::Layout\n";    
    connect(&play,SIGNAL(pressed()),this,SLOT(onPress()));
    m_hlayout->addWidget(&play);
    setLayout(m_hlayout);
}


void Layout::onPress()
{
    qDebug()<<"Layout::onPress()\n";
}
