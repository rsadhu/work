#include "myloggerviewer.h"

MyLoggerViewer::MyLoggerViewer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(9);
	ui.tableWidget->setRowCount(100);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setWordWrap(true);
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}

MyLoggerViewer::~MyLoggerViewer()
{

}
