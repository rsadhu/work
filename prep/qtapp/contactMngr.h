#ifndef CONTACTMNGR_H
#define CONTACTMNGR_H
#include"contact.h"
#include"cachemngr.h"

class ContactMngr
{
public:
    void addContact(Contact &);
    void delContact(Contact &);
    Contact & findContact(Contact);
private:
Cache<Contact *>m_cache;
QtDataBase *m_db;
};

#endif // CONTACTMNGR_H
