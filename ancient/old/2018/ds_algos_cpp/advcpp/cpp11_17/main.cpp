#include <QCoreApplication>
#include"asynchronous.h"
#include<QDebug>
#include<iostream>
#include<filereaderwriter.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Asynchronous async;
    int p = 100;

    std::cout<<".... Starts...";
    qDebug()<<".... Starts...";

    async.start(p,[](int  data){
        qDebug()<<" the data received is  "<<data;
        std::cout<<" the data received is  "<<data;

    });


    qDebug()<<".... ENDS...";
    std::cout<<".... ENDS...";

    FileReaderWriter fw("asynchronous.cpp");
    fw.open();
    std::string str;
    fw.read(str);
    qDebug()<<"File read: "<<str.c_str();

    return a.exec();
}
