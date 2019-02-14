#ifndef FILEREADERWRITER_H
#define FILEREADERWRITER_H
#include<fstream>
#include<array>

class FileReaderWriter
{
public:
    FileReaderWriter(std::string filename = std::string(""));
    ~FileReaderWriter();
    bool open(std::string filename=std::string(""));
    void read(std::string &data) const;
    void write(const std::string &data) ;
private:
    std::string m_resource;
    std::fstream m_fileopener;
};

#endif // FILEREADERWRITER_H
