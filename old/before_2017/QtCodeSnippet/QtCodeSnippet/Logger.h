#pragma once
class Logger
{
public:
	Logger();
	~Logger();
private:
	static Logger *msingleton;
};

