#include "stdafx.h"
#include "FileReaderWriter.h"


FileReaderWriter::FileReaderWriter(const std::string &file)
{
	m_fw.open(file, std::fstream::in | std::fstream::out | std::fstream::app);
	try
	{
		if (m_fw.is_open())
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
		if (m_fw.is_open())
			m_fw.close();
	}
}


FileReaderWriter::~FileReaderWriter()
{
	if (m_fw.is_open())
		m_fw.close();
}


void  FileReaderWriter::write()
{
	try
	{	
		//m_fw.wr
	}
	catch (std::exception &e)
	{
		/*if (m_fw.is_open())
			m_fw.close();*/
		std::cout << "Exception Thrown :" << e.what();
	}
}


void FileReaderWriter::read()
{

}