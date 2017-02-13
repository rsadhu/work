#pragma once
#include"sqlite3.h"
#include<qstring.h>
#include<mutex>
#include<condition_variable>
#include<thread>

class MyDatabaseContoller
{
	MyDatabaseContoller() ;
	MyDatabaseContoller(const MyDatabaseContoller &) = delete;
	MyDatabaseContoller & operator =(const MyDatabaseContoller &) = delete;	
	virtual ~MyDatabaseContoller();// = delete;
public:
	static MyDatabaseContoller *  getInstance();
	static void freeDatabase();
protected:
	void init();
public:	
	void insertData(QString &data);
	void deleteData(QString &key);
	void updateData(QString &data, QString &key);	
	void getAllData(QList<QStringList> &);
private:
	sqlite3 *mDatabase = nullptr;
	QString mDbName;
	static MyDatabaseContoller *s_obj;	
	bool mSignal = false;
	std::condition_variable m_cond;
	std::mutex mMutex;
};

