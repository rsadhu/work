#include "MyDatabaseContoller.h"
#include<qdebug.h>
#include<qdatetime.h>

static sqlite3 *s_Database = nullptr;
QMutex  gMutex;

MyDatabaseContoller MyDatabaseContoller::s_instance;
int  MyDatabaseContoller::s_primaryKey;


static int dbCallBack(void *this_ptr, int argc, char **argv, char **azColName)
{
	if (this_ptr)
	{
		Reader * thisPtr = static_cast<Reader*> (this_ptr);
		if (thisPtr)
		{
			thisPtr->sqlite3callback(argc, argv, azColName);
		}
	}
	return 0;
}


MyDatabaseContoller::MyDatabaseContoller()
{
	mDbName = "Log.db";
	init();
}


MyDatabaseContoller * MyDatabaseContoller::getInstance()
{
	return &s_instance;
}



MyDatabaseContoller::~MyDatabaseContoller()
{
	if (s_Database)
		sqlite3_close(s_Database);
}


static int primartKeyDetection(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
	{
		if (std::strcmp(azColName[i], "ID") == 0)
		{
			MyDatabaseContoller::setPrimaryKey(std::stoi(argv[i]));
			break;
		}
	}
	return 0;
}


void MyDatabaseContoller::setPrimaryKey(int key)
{
	s_primaryKey = key;
}


void MyDatabaseContoller::initPrimaryKey()
{
	char *query = "SELECT * FROM LOG_TABLE ORDER BY ID DESC LIMIT 1";
	const char *sql = strdup(query);
	char *errMsg = nullptr;
	gMutex.lock();
	int ret = sqlite3_exec(s_Database, sql, primartKeyDetection, "some data", &errMsg);
	gMutex.unlock();
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		//qDebug() << "Query runs  Successfully..\n";
	}
}




// c++ call back called from sqlite calback
int Reader::sqlite3callback(int argc, char **argv, char **azColName)
{	
	Data data;
	for (int i = 0; i<argc; i++)
	{
		if (std::strcmp(azColName[i], "ID") == 0)
			data.mPrimaryKey = argv[i];
		if (std::strcmp(azColName[i], "APPNAME") == 0)
			data.mAppName = argv[i];
		if (std::strcmp(azColName[i], "ACTIVITY") == 0)
			data.mMessage = argv[i];	
	}
	emit signalUpdateLogs(data);
	return 0;
}

void MyDatabaseContoller::writeData(const QString &appName, const QString &data)
{
	s_primaryKey++;	
	std::string str = data.toStdString() + "  ::  " + QDateTime::currentDateTime().toString().toStdString();
	char *sql =
	sqlite3_mprintf("INSERT INTO LOG_TABLE VALUES(%Q,%Q,%Q)", std::to_string(s_primaryKey).c_str(), appName.toStdString().c_str(), str.c_str());
	insertData(sql);
}


void MyDatabaseContoller::init()
{
	gMutex.lock();
	int ret = sqlite3_open(mDbName.toStdString().c_str(), &s_Database);
	gMutex.unlock();
	if (ret==0)
	{
		//qDebug() << "database created..";		

		char *sql = "CREATE TABLE IF NOT EXISTS LOG_TABLE("  \
			"ID INT PRIMARY KEY			NOT NULL," \
			"APPNAME            TEXT    NOT NULL,"\
			"ACTIVITY            TEXT    NOT NULL); ";

		char *errMsg = nullptr;
		gMutex.lock();
		ret = sqlite3_exec(s_Database, sql, dbCallBack, 0, &errMsg);
		gMutex.unlock();
		if (ret != SQLITE_OK)
		{
			sqlite3_free(errMsg);
		}
		else
		{
//			qDebug() << "TableCreated Successfully..\n";
			initPrimaryKey();
		}	
	}	
}


void MyDatabaseContoller::insertData(const char *query)
{
	const char *sql = strdup(query);
	char *errMsg = nullptr;

	gMutex.lock();
	int ret = sqlite3_exec(s_Database, sql, dbCallBack, 0, &errMsg);
	gMutex.unlock();
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		//qDebug() << "Query runs  Successfully..\n";
	}

	free((char*)sql);
}


void Reader::run()
{		
	const char *sql = "SELECT * FROM LOG_TABLE";
	char *errMsg = nullptr;	

	gMutex.lock();
	int ret = sqlite3_exec(s_Database, sql, dbCallBack, this, &errMsg);	
	gMutex.unlock();

	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		//qDebug() << "Query runs  Successfully..\n";
	}	
	
}