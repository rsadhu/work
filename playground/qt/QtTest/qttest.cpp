#include "qttest.h"
#include<QTimer>

auto connectionType = Qt::QueuedConnection;

QtTest::QtTest(QObject *parent) : QObject(parent)
{

  qRegisterMetaType<Data>();

  QTimer *m = new QTimer(this);
    
  qDebug()<<"========== Constructor-1 ===============";

  connect(this, &QtTest::sendMessage, this, &QtTest::onMessageArrived, connectionType);
  
//  connectionType = Qt::DirectConnection;

  connect(this, &QtTest::changeSomethingWithCopy, this, [] (Data d) {
    qDebug()<<" copy slot called==== >>1 ";
  },connectionType);
 


 connect(this, &QtTest::changeSomethinWithCRefs, this, [](const Data &refDa) {
    qDebug()<<" ref const  slot called ====> 2";
 }, connectionType); 
 

  qDebug()<<"========== Constructor-2 ===============";

  connect(m,&QTimer::timeout, [=]()
  {
      Data *obj = new Data();

  //    QString  *st = new QString("Rakesh sadhu ");
    //  QString strrrr("Const String");

     // emit sendMessage(obj,st,strrrr,*obj);
  
//  emit changeSomethingWithCopy(*obj);

  emit changeSomethinWithCRefs(*obj);
  });

  m->setInterval(2000);

  m->start();

}


void QtTest::onMessageArrived(Data * d1 , QString * str, QString ss,Data d)
{
    qDebug()<<"d1 :"<<d1<< "  "<<*str<< "   "<<ss<<"  "<<d.mStr<<"\n";
}
