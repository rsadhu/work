#ifndef FILEBOOK_H
#define FILEBOOK_H
#include "commonData.h"
#include "databasemanager.h"

class FileMngr : public DataBaseManager
{
public:
    FileMngr();
    ~FileMngr();
    void write(Contact *);
    void read(Contact *);
    void readAll(char *, unsigned int);

private:
    FILE *m_fp;
};

#endif //
