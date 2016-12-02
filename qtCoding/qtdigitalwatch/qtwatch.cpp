#include "qtwatch.h"
#include<QTimer>
#include<QTime>
#include<QDebug>
#include<QGridLayout>

QtWatch::QtWatch(QWidget *parent ):QLCDNumber(parent)
{    
    QGridLayout *layout= new QGridLayout(this);

    setSegmentStyle(Filled);
    setDigitCount(25);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotShowTime()));
    timer->start(1000);
    slotShowTime();
    setWindowTitle(tr("Digital Clock"));
    resize(150, 60);
    setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(0, 0, 0);font-size: 12pt;font-weight: bold;");

}


void QtWatch::slotShowTime()
{
    QDateTime dt =  QDateTime::currentDateTime();
    QString dateStr = dt.toString("dd::MM::yyyy");
    qDebug()<<dateStr<<endl;
    QString timeStr = dt.toString("hh::mm::ss");
    qDebug()<<timeStr<<endl;
    display(dateStr+timeStr);
}
