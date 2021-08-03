#include "Logger.h"
#include<fstream>


Logger::Logger()
{
	fileName = "log.txt";
}


Logger::~Logger()
{
}


void Logger::log(string &str)
{
	ofstream fp;
	//fp.open((char*)fileName.c_str());
	fp.open("log.txt", ios::out | ios::app | ios::in);
	fp << str.c_str()<<"\n";
	fp.close();
}