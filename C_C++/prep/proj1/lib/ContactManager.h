#ifndef __CM__H
#define __CM__H

#include"Contact.h"
#include"Cache.h"
#include"global.h"
#include<vector>

//char Filter[2][] = {"Number","Name"};
typedef enum
{
	NUMBER,
	NAME
}Filter;

class ContactManager
{
	protected:
	ContactManager(){ init();}
	ContactManager(const ContactManager &rhs);
	ContactManager & operator =(const ContactManager &);	
	private:
	void init();
	public:
	static ContactManager * getInstance();	
	void addContact(Contact &contact);
	void deleteContact(Contact &contact);
	vector<Contact *>* ContactManager::findContact(Filter filter);
	void displayAll(){ m_cache->display();}
	private:
	static ContactManager *m_obj;
	FILE *m_fp;
	Cache<Contact> *m_cache;
};
#endif //
