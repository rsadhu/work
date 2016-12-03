#pragma once
#include<qmutex.h>
#include<qfile.h>
#include <QTextStream>
class Logger
{
	Logger();
	Logger(const Logger &);
	Logger & operator=(const Logger &);
	~Logger();

public:	
	static Logger *  getInstance();
	void writeToFile(const QString &);
	
private:
	static Logger *mSingleton;
	QFile mFile;
	QMutex mMutex;
};

