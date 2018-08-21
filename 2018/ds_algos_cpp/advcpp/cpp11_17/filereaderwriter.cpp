#include "filereaderwriter.h"

FileReaderWriter::FileReaderWriter( std::string filename):m_resource(filename)
{

}

FileReaderWriter::~FileReaderWriter()
{
    m_fileopener.close();
}

bool FileReaderWriter::open(std::string filename)
{
    m_resource = filename;
    m_fileopener.open(m_resource);
}

void FileReaderWriter::read(std::string &data) const
{
    m_fileopener.read(data,100);
}

void FileReaderWriter::write(const std::string &data)
{
    m_fileopener.write(data,data.size());
}


