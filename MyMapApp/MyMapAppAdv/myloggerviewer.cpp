#include "myloggerviewer.h"
#include"MyDatabaseContoller.h"
#include<qthreadpool.h>

static bool s_Initialized = false;
static void registerRecordSearchQtObjects()
{
	if (!s_Initialized)
	{
		qRegisterMetaType<Data>();
		s_Initialized = true;
	}
}

int MyLoggerViewer::m_tableCounter;

MyLoggerViewer::MyLoggerViewer(QWidget *parent)
	: QWidget(parent)
{	
	ui.setupUi(this);
	initUI();
	registerRecordSearchQtObjects();
	

	MyDatabaseContoller::getInstance()->writeData("LoggerViewer::"," Starting ..");
	slotCheckLogsAgain();
	mTimer = new QTimer(this);
	connect(mTimer, SIGNAL(timeout()), this, SLOT(slotCheckLogsAgain()));
	mTimer->start(5000);
	
}

void MyLoggerViewer::initUI()
{
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);	
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(100);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setWordWrap(true);
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
	ui.tableWidget->setColumnWidth(0, this->width()*(0.1));
	ui.tableWidget->setColumnWidth(1, this->width()*(0.2));
	ui.tableWidget->setColumnWidth(2, this->width()*(0.7));
	resize(500, 500);
}



void MyLoggerViewer::slotCheckLogsAgain()
{	
	m_tableCounter = 0;
	ui.tableWidget->setRowCount(0);

	Reader *mReaderLogs = new Reader();
	connect(mReaderLogs, SIGNAL(signalUpdateLogs(Data)), this, SLOT(slotUpdateLogs(Data)), Qt::QueuedConnection);
	QThreadPool::globalInstance()->start(mReaderLogs);	
}

MyLoggerViewer::~MyLoggerViewer()
{
	MyDatabaseContoller::getInstance()->writeData("LoggerViewer::", " Shutting ..");
}

void
MyLoggerViewer::slotUpdateLogs(Data  result)
{		
	ui.tableWidget->setRowCount(10000);
	ui.tableWidget->setItem(m_tableCounter, 0, new QTableWidgetItem(result.mPrimaryKey));
	ui.tableWidget->setItem(m_tableCounter, 1, new QTableWidgetItem(result.mAppName));
	ui.tableWidget->setItem(m_tableCounter, 2, new QTableWidgetItem(result.mMessage));	
	m_tableCounter++;
	
}