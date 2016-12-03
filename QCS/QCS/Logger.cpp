#include "Logger.h"


Logger *Logger::mSingleton = nullptr;
Logger::Logger() 
{
	mFile.setFileName("D:\\rsadhu\\work\\QCS\\log.txt");
}


Logger::~Logger()
{
}

Logger * Logger::getInstance( )
{
	if (!mSingleton)	
		mSingleton = new Logger();
	
	return mSingleton;
}

void Logger::writeToFile(const QString &data)
{
	QMutexLocker ml(&mMutex);
	if (mFile.open(QIODevice::WriteOnly | QIODevice::Append))
	{
		QTextStream out (&mFile);
		QByteArray d;
		d.append(data);	
		out << d;
	}	
}
