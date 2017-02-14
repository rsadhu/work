#include "MyDatabaseContoller.h"
#include<qdebug.h>
#include<qdatetime.h>

MyDatabaseContoller *MyDatabaseContoller::s_instance = nullptr;
int  MyDatabaseContoller::s_primaryKey;


static int dbCallBack(void *this_ptr, int argc, char **argv, char **azColName)
{
	if (this_ptr)
	{
		MyDatabaseContoller * thisPtr = static_cast<MyDatabaseContoller*> (this_ptr);
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
	if (!s_instance)
	{
		s_instance = new MyDatabaseContoller();
	}
	return s_instance;
}

void MyDatabaseContoller::freeDatabase()
{

}

MyDatabaseContoller::~MyDatabaseContoller()
{
	sqlite3_close(mDatabase);
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
	int ret = sqlite3_exec(mDatabase, sql, primartKeyDetection, "some data", &errMsg);
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		qDebug() << "Query runs  Successfully..\n";
	}
}




// c++ call back called from sqlite calback
int MyDatabaseContoller::sqlite3callback(int argc, char **argv, char **azColName)
{	
	QString str;
	int i;
	char data[1000];
	for (i = 0; i<argc; i++)
	{
		memset(data, 0, 1001);
		sprintf(data, "%s ", argv[i] ? argv[i] : "NULL");
		qDebug() << data;
		str.append(data);
	}
	mCb(str);
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
	int ret = sqlite3_open(mDbName.toStdString().c_str(), &mDatabase);
	if (ret==0)
	{
		qDebug() << "database created..";		

		char *sql = "CREATE TABLE IF NOT EXISTS LOG_TABLE("  \
			"ID INT PRIMARY KEY			NOT NULL," \
			"APPNAME            TEXT    NOT NULL,"\
			"ACTIVITY            TEXT    NOT NULL); ";

		char *errMsg = nullptr;
		ret = sqlite3_exec(mDatabase, sql, dbCallBack, 0, &errMsg);
		if (ret != SQLITE_OK)
		{
			sqlite3_free(errMsg);
		}
		else
		{
			qDebug() << "TableCreated Successfully..\n";
			initPrimaryKey();
		}	
	}	
}


void MyDatabaseContoller::insertData(const char *query)
{
	const char *sql = strdup(query);
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

	free((char*)sql);
}


void MyDatabaseContoller::getAllData(callBackForDbData cb)
{	
	mCb = cb;
	const char *sql = "SELECT * FROM LOG_TABLE";
	char *errMsg = nullptr;	
	//s_content.clear();
	int ret = sqlite3_exec(mDatabase, sql, dbCallBack, this, &errMsg);	
	if (ret != SQLITE_OK)
	{
		sqlite3_free(errMsg);
	}
	else
	{
		qDebug() << "Query runs  Successfully..\n";
	}	
}