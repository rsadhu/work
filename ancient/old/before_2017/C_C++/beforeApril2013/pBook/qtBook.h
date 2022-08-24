#ifndef QTBOOK_H
#define QTBOOK_H
#include "commonData.h"
#include "databasemanager.h"

class QtBook : public DataBaseManager
{
public:
    QtBook();
    ~QtBook();
    void read(char *);
    void write(char *);

private:
    // qtdb_base;
};

#endif
