#ifndef COMMONDATA_H
#define COMMONDATA_H
#include<string.h>
#include<stdlib.h>
#include<QDebug>
#include<QVector>

typedef enum
{
    FILETYPE,
    QTSQL,
    NONE
}DBTYPE;

class Contact
{
 public:
    Contact(){}
    Contact(char *,char *,char *, char *);
    Contact(Contact *);
    ~Contact();
    char *fname;
    char *lname;
    char *mob;
    char *landline;
};

#endif // COMMONDATA_H
