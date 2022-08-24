#ifndef INTERFACE_H
#define INTERFACE_H
#include "fileBook.h"
#include "qtBook.h"
#include "databasemanager.h"

class PhoneBook
{
public:
    PhoneBook(DBTYPE);
    ~PhoneBook();
    void addContact(Contact *p);
    void updateContact(Contact *p);
    void deleteContact(Contact *p);
    QVector<Contact *> *findContacts(char *p);

private:
    DataBaseManager *m_dmngr;
};

#endif // INTERFACE_H
