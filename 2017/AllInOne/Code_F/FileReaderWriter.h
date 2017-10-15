#pragma once

#include<iostream>
#include<fstream>
#include<exception>

enum class Type { AUDIO = 0, VIDEO };

class FileReaderWriter
{
public:
	FileReaderWriter(const std::string &file);
	~FileReaderWriter();
	void write();
	void read();
private:
	std::fstream m_fw;
};
