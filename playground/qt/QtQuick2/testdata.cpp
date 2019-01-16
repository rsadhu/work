#include "testdata.h"

DataModel::DataModel(QObject *parent) : QObject(parent)
{

}

EmployeeCard::EmployeeCard(QObject *parent):QObject(parent)
{
    if(QMetaObject::invokeMethod(this,"fireCall"))
    {
        qDebug()<<"EmployeeCard:::EmployeeCard::passed";
    }
    else
    {
        qDebug()<<"EmployeeCard:::EmployeeCard::failed";
    }
}
