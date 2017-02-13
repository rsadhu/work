#include "MyDatabaseContoller.h"
#include<qdebug.h>

MyDatabaseContoller *MyDatabaseContoller::s_obj = nullptr;

MyDatabaseContoller::MyDatabaseContoller()
{
	mDbName = "Log.db";
	init();
}


MyDatabaseContoller * MyDatabaseContoller::getInstance()
{
	if (!s_obj)
	{
		s_obj = new MyDatabaseContoller();
	}
	return s_obj;
}

void MyDatabaseContoller::freeDatabase()
{	
	
}

MyDatabaseContoller::~MyDatabaseContoller()
{
	sqlite3_close(mDatabase);
}

static int dbCallBack(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	char data[1000];
	for (i = 0; i<argc; i++){
		sprintf(data,"%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	qDebug() << data;
	return 0;
}

void MyDatabaseContoller::init()
{
	int ret = sqlite3_open(mDbName.toStdString().c_str(), &mDatabase);
	if (ret==0)
	{
		qDebug() << "database created..";		

		char *sql = "CREATE TABLE IF NOT EXISTS LOG_TABLE("  \
			"ID INT PRIMARY KEY			NOT NULL," \
			"APPNAME            TEXT    NOT NULL,"\
			"ACTIVITY            TEXT    NOT NULL); ";

		char *errMsg = nullptr;
		ret = sqlite3_exec(mDatabase,sql, dbCallBack,0,&errMsg);
		if (ret != SQLITE_OK)
		{
			sqlite3_free(errMsg);
		}
		else
		{
			qDebug() << "TableCreated Successfully..\n";
		}	
	}	
}


void MyDatabaseContoller::insertData(QString &query)
{
	const char *sql = strdup(query.toStdString().c_str());
	char *errMsg = nullptr;
	int ret = sqlite3_exec(mDatabase, sql, dbCallBack, "some data", &errMsg);
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		qDebug() << "Query runs  Successfully..\n";
	}

	free((char*)sql);
}


void MyDatabaseContoller::getAllData(QList<QStringList> &content)
{	
	const char *sql = "SELECT * FROM LOG_TABLE";
	char *errMsg = nullptr;
	int ret = sqlite3_exec(mDatabase, sql, dbCallBack, 0, &errMsg);
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		qDebug() << "Query runs  Successfully..\n";
	}	
}