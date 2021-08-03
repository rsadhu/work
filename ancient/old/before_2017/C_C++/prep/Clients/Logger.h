#pragma once
#include<iostream>
using namespace std;

class Logger
{
public:
	Logger();
	~Logger();
	static void log(string &str);	
private:
	string fileName;
};

