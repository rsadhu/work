#pragma once


#include<string>


class ReaderWriterPriv
{
public:
	ReaderWriterPriv();
	~ReaderWriterPriv();

};


class ReaderWriter
{
public:
	ReaderWriter();
	~ReaderWriter();
	void read(std::string &);
	void write(std::string &);
private:
	ReaderWriterPriv *m_priv = nullptr;
};

