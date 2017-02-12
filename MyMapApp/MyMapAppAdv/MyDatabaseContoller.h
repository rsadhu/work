#pragma once
#include"sqlite3.h"
#include<qstring.h>
class MyDatabaseContoller
{
public:
	MyDatabaseContoller(QString &dbName);
	virtual ~MyDatabaseContoller();
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
};

