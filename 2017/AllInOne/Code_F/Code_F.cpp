// Code_F.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"FileReaderWriter.h"
#include<vector>
#include<string>


int _tmain(int argc, _TCHAR* argv[])
{
	FileReaderWriter fmgr(std::string("D:\\rsadhu\\codingPractice\\work_git\\2017\\AllInOne\\elephants.ts"));
	fmgr.read();
	return 0;
}

