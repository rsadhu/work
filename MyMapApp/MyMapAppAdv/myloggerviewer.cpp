#include "myloggerviewer.h"
#include"MyDatabaseContoller.h"




void callback(QString &d)
{

}

MyLoggerViewer::MyLoggerViewer(QWidget *parent)
	: QWidget(parent)
{
	MyDatabaseContoller::getInstance()->writeData("LOGGER","Logged in ");
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(100);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setWordWrap(true);
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
	resize(500, 500);

	MyDatabaseContoller::getInstance()->getAllData(callback);
}

MyLoggerViewer::~MyLoggerViewer()
{
	MyDatabaseContoller::getInstance()->writeData("LOGGER", "Logged out ");
}
