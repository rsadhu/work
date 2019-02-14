#include "ibexshortcuts.h"
#include "ui_ibexshortcuts.h"
#include<iostream>

iBexShortCuts::iBexShortCuts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::iBexShortCuts)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint);

    this->setWindowOpacity(0.9);
    this->setStyleSheet("background-color:rgb(0,0,255);");
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    QStringList tableHeader;
    tableHeader << "Action " << " ShortCut" << "description";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    init();
}

void iBexShortCuts::init()
{
    m_Document = new QDomDocument;
    //QFile file("./resources/configurations/iBexShortCuts.xml");
    QFile file("C:\\Users\\rsadhu\\Desktop\\work\\qtCoding\\xmlTest\\myXLM.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Failed to open the file for reading.";
        return;
    }
    else
    {
        // loading
        if (!m_Document->setContent(&file))
        {
            std::cout << "Failed to load the file for reading.";
            return;
        }
        file.close();
    }

    QDomElement root = m_Document->firstChildElement();
    retrievElements(root, "iBexShortCut", "ID+Shortcut+Description");
}


void iBexShortCuts::retrievElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);
    ui->tableWidget->setRowCount(nodes.count());
    for (int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if (elm.isElement())
        {
            QDomElement e = elm.toElement();
            QStringList allAttrs = att.split("+");
            for (int k = 0; k<allAttrs.length(); k++)
            {
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setText(e.attribute(allAttrs[k]));
                ui->tableWidget->setItem(i, k, item1);
            }
        }
    }
}

iBexShortCuts::~iBexShortCuts()
{
    delete ui;
    delete m_Document;
}
