#include "MyDatabaseContoller.h"
#include<qdebug.h>

MyDatabaseContoller::MyDatabaseContoller(QString &dbName) :mDbName(dbName)
{
	init();
}


MyDatabaseContoller::~MyDatabaseContoller()
{
	sqlite3_close(mDatabase);
}

static int dbCallBack(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void MyDatabaseContoller::init()
{
	int ret = sqlite3_open(mDbName.toStdString().c_str(), &mDatabase);
	if (ret==0)
	{
		qDebug() << "database created..";

		/* Create SQL statement */
		/*char *sql = "CREATE TABLE if not exists tbl_test("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"NAME           TEXT    NOT NULL," \
			"AGE            INT     NOT NULL," \
			"ADDRESS        CHAR(50)\
			);";*/

		char *sql = "CREATE TABLE COMPANY("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"NAME           TEXT    NOT NULL," \
			"AGE            INT     NOT NULL," \
			"ADDRESS        CHAR(50)," \
			"SALARY         REAL );";

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
	const char *sql = query.toStdString().c_str();
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


void MyDatabaseContoller::deleteData(QString &key)
{

}


void MyDatabaseContoller::updateData(QString &data, QString &key)
{

}


void MyDatabaseContoller::getAllData(QList<QStringList> &content)
{	
	const char *sql = "SELECT * FROM tbl_test";
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