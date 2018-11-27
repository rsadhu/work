#include "qttest.h"
#include<QTimer>
#include<QDebug>


QtTest::QtTest(QObject *parent) : QObject(parent)
{

  qRegisterMetaType<Data>();

  QTimer *m = new QTimer(this);

  connect(this,&QtTest::sendMessage, this, &QtTest::onMessageArrived,Qt::QueuedConnection);

  connect(m,&QTimer::timeout, [=]()
  {
      Data *obj = new Data();

      QString  *st = new QString("Rakesh sadhu ");
      QString strrrr("Const String");

      emit sendMessage(obj,st,strrrr,*obj);
  });

  m->setInterval(2000);

  m->start();

}


void QtTest::onMessageArrived(Data * d1 , QString * str, QString ss,Data d)
{
    qDebug()<<"d1 :"<<d1<< "  "<<*str<< "   "<<ss<<"  "<<d.mStr<<"\n";
}
