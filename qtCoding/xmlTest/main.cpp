#include "mainwindow.h"
#include <QApplication>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str("2016-01-11 17:29:51");
    QStringList list =  str.split(" ");
    for(int i=0;i<list.size();i++)
        qDebug()<<list.at(i);





#ifdef RAKESH
    MainWindow w;



    // Create a document to write XML
        QDomDocument document;

        // Open a file for reading
        QFile file("C:\\Users\\rsadhu\\Desktop\\work\\qtCoding\\xmlTest\\myXLM.xml");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open the file for reading.";
            return -1;
        }
        else
        {
            // loading
            if(!document.setContent(&file))
            {
                qDebug() << "Failed to load the file for reading.";
                return -1;
            }
            file.close();
        }

        // Getting root element
        QDomElement root = document.firstChildElement();

        // retrievelements(QDomElement root, QString tag, QString att)
        w.retrievElements(root, "iBexShortCut", "ID+Shortcut+Description");

        qDebug() << "Reading finished";




    w.show();
#endif

    return a.exec();
}
