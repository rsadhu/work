#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_Tree = new QTreeWidget(this);

    QStringList name("node");
    m_TreeItem = new QTreeWidgetItem(m_Tree,name);

    QTreeWidgetItem *item = QTreeWidgetItem(m_TreeItem);




}

Widget::~Widget()
{
    delete ui;
}
