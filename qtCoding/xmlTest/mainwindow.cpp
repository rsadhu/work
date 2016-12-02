#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QGridLayout>
#include<QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowOpacity(0.8);
    this->setStyleSheet("background-color:rgb(0,255,255);");
}

MainWindow::~MainWindow()
{

}



void MainWindow ::retrievElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);

    QGridLayout *layout = new QGridLayout (this);


    qDebug() << "# nodes = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            QStringList allAttrs = att.split("+");
            for(int k=0;k<allAttrs.length();k++)
            {
                qDebug() << e.attribute(allAttrs[k]);
                QLabel *l = new QLabel(this);
                l->setText(e.attribute(allAttrs[k]));
                l->setStyleSheet("QLabel {color : blue; }");
                QFont f( "Arial", 10, QFont::Bold);
                l->setGeometry(0,0,500,60);
                l->setFont(f);
                l->setMaximumHeight(50);
                layout->addWidget(l,i,k);

            }
        }
    }
    show();
}
