#pragma once
#include"sqlite3.h"
#include<list>
class DbController
{
public:
	DbController();
	virtual ~DbController();
	void initDb();
	void insertData();
	void readData(std::list < std::string > &);
private:
	sqlite3 *mDb = nullptr;
};

