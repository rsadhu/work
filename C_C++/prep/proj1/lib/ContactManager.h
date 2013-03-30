#ifndef __CM__H
#define __CM__H

#include"global.h"

class ContactManager
{
	protected:
	ContactManager(){}
	ContactManager(const ContactManager &rhs);
	ContactManager & operator =(const ContactManager &);	
	public:
	static ContactManager * getInstance();	
	void addContact(Contact &contact);
	void deleteContact(Contact &contact);
	void 
	private:
	ContactManager *m_obj;
	FILE *m_fp;
	CacheManager<Contact*> m_cache;
};
#endif //