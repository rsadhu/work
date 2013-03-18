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
//Cache<Contact *>m_cache;
#ifdef FILE_DB
            FILE *m_db;
#elif
   void *m_db;
#endif//

};

#endif // CONTACTMNGR_H
