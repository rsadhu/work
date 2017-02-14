#pragma once
#include"sqlite3.h"
#include<qstring.h>
#include<qrunnable.h>
#include<qobject.h>
#include<QMutex>
#include<condition_variable>

typedef void(*callBackForDbData)(QString &);


class Data
{
public:
	QString mAppName = "";
	QString mMessage = "";
	QString mPrimaryKey = "";
};

static sqlite3 *s_Database = nullptr;

class MyDatabaseContoller 
{		
	MyDatabaseContoller();
	virtual ~MyDatabaseContoller();
	MyDatabaseContoller(const MyDatabaseContoller &) = delete;
	MyDatabaseContoller & operator =(const MyDatabaseContoller &) = delete;		
public:
	static MyDatabaseContoller *  getInstance();
	static void freeDatabase();
	static void setPrimaryKey(int);	
	void writeData(const QString &appName, const QString &data);
protected:
	void init();
	void insertData(const char *);	
	void initPrimaryKey();							
private:	
	QString mDbName;
	callBackForDbData mCb;	
	static int  s_primaryKey;
	static MyDatabaseContoller *s_instance;	
};



class Reader :public QObject, public QRunnable
{
	Q_OBJECT
public:
	void run();
	int  sqlite3callback(int argc, char **argv, char **azColName);	
	friend static int dbCallBack(void *this_ptr, int argc, char **argv, char **azColName);
signals:
	void signalUpdateLogs(Data);
private:
	bool mSignal = false;
	std::condition_variable m_cond;
	QMutex  mMutex;
};

