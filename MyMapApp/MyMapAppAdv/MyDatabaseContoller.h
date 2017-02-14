#pragma once
#include"sqlite3.h"
#include<qstring.h>
#include<mutex>
#include<condition_variable>
#include<thread>
typedef void(*callBackForDbData)(QString &);

class MyDatabaseContoller
{
	MyDatabaseContoller() ;
	MyDatabaseContoller(const MyDatabaseContoller &) = delete;
	MyDatabaseContoller & operator =(const MyDatabaseContoller &) = delete;	
	virtual ~MyDatabaseContoller();// = delete;
public:
	static MyDatabaseContoller *  getInstance();
	static void freeDatabase();
	static void setPrimaryKey(int);
	int sqlite3callback(int argc, char **argv, char **azColName);
protected:
	void init();
	void insertData(const char *);	
	void initPrimaryKey();	
public:	
	void writeData(const QString &appName, const QString &data);
	void getAllData(callBackForDbData &);
private:
	sqlite3 *mDatabase = nullptr;
	QString mDbName;
	static MyDatabaseContoller *s_obj;	
	bool mSignal = false;
	std::condition_variable m_cond;
	std::mutex mMutex;
	static int  s_primaryKey;
	static QStringList s_content;
	callBackForDbData mCb;
};

