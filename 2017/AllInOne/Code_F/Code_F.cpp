// Code_F.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<exception>

int _tmain(int argc, _TCHAR* argv[])
{
	std::fstream fs;
	fs.open("D:\\rsadhu\\codingPractice\\work_git\\2017\\AllInOne\\elephants.ts", std::fstream::in | std::fstream::out | std::fstream::app);
	try
	{
		if (fs.is_open())
		{
			std::cout << " file opened\n";
			throw std::exception("Testing file");
		}
		else
		{
			std::cout << "couldnt open the file\n";
		}
	}
	catch (std::exception &e)
	{
		std::cout << "exception Thrown::" << e.what() << "\n";
		fs.close();
	}
	return 0;
}

