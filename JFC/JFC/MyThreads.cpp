#include "MyThreads.h"
#include<fstream>



MyThreads::MyThreads()
{
	
}


MyThreads::~MyThreads()
{
	if (th.joinable())
		th.join();
	if (th1.joinable())
		th1.join();
}

void MyThreads::thread1()
{
	m1.lock();
	int m = 0;
	while (m < 10)
	{
		mSharedData = m;
		m++;
		std::cout << "value of mSharedData  ::  " << mSharedData << std::endl;	
	}
	m1.unlock();
}

void MyThreads::thread2()
{
	m1.lock();
	int m = 0;
	while (m < 10)
	{
		mSharedData = m;
		m++;
		std::cout << "value of mSharedData  ::  " << mSharedData << std::endl;	
	}
	m1.unlock();
}

void MyThreads::printValues()
{
	while (!mStop)
		std::cout << "value of mSharedData  ::  " << mSharedData << std::endl;
}

void MyThreads::start()
{
	th = std::thread(&MyThreads::thread1,this);
	th1 = std::thread(&MyThreads::thread2,this);
}

void MyThreads::stop()
{
	mStop = !mStop;
}



class LogFile
{
	std::mutex m_mutex;
	std::ofstream f;
	static LogFile *m_Obj;
	LogFile()
	{
		f.open("log.txt", std::ios_base::app);
	}
	LogFile(const LogFile &) = delete;
	LogFile & operator =(const LogFile&) = delete;

public:

	static LogFile* getInstance()
	{
		if (!m_Obj)
			m_Obj = new LogFile;
		return m_Obj;
	}

	void writeToFile(std::string &str)
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		f << str.c_str();
	}
};

LogFile *LogFile::m_Obj = nullptr;


template<typename T>
std::string to_string(const T&n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}