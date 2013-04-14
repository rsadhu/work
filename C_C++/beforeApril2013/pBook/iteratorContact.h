#ifndef ITERATORCONTACT_H
#define ITERATORCONTACT_H

#include"commonData.h"


typedef
struct _list
{
Contact *contactObject;
struct _list *next;
}linkList;

class Iterator
{
public:
    Iterator();
    ~Iterator();
    void init(void *handle ,DBTYPE type );
    void add(Contact *);
    void del(Contact *);
    QVector<Contact *>* find(char *);
    void update(Contact *);
    Contact & operator *();
    void display();
private:
        linkList *head;
};

#endif // ITERATORCONTACT_H
