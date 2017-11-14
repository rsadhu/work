// MTP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<thread>
#include<condition_variable>
#include<share.h>
#include<future>
#include<fstream>
#include<string>
#include <iostream>
#include <sstream>
class FileMngr
{
	std::fstream fs;	
public:
	FileMngr()
	{
		fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);		
	}

	void write(std::string &data)
	{		
		fs.write(data.c_str(),data.size());
	}

	bool read(std::string &d)
	{
		int n = 10;
		fs.read(const_cast<char*>(d.c_str()), n);
		return n == 0;
	}

	~FileMngr()
	{
		fs.close();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	FileMngr fm;
	std::string name;
	//while (std::getline(std::cin, name) && name.compare("")!=0)
	//{
	//	fm.write(name);
	//}

	while (fm.read(name))
	{
		std::cout << name << "   ";
		name = "";
	}

	return 0;
}

