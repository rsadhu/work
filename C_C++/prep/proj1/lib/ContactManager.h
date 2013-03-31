#ifndef __CM__H
#define __CM__H

#include"Contact.h"
#include"Cache.h"
#include"global.h"

class ContactManager
{
	protected:
	ContactManager(){ m_fp = fopen("contactdb.txt","a");}
	ContactManager(const ContactManager &rhs);
	ContactManager & operator =(const ContactManager &);	
	public:
	static ContactManager * getInstance();	
	void addContact(Contact &contact);
	void deleteContact(Contact &contact);
	private:
	static ContactManager *m_obj;
	FILE *m_fp;
	Cache<Contact*> m_cache;
};
#endif //
