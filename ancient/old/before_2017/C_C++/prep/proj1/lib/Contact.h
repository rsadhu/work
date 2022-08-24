#ifndef __CONTACT__H
#define __CONTACT__H
#include "global.h"
class Contact
{
public:
	Contact() : m_name(0), m_mob(0) {}
	Contact(char *name, char *mob)
	{
		m_name = strdup(name);
		m_mob = strdup(mob);
	}
	Contact(const Contact &rhs)
	{
		this->m_name = strdup(rhs.m_name);
		this->m_mob = strdup(rhs.m_mob);
	}

	Contact operator=(const Contact &rhs)
	{
	}
	char *name() { return m_name; }
	char *mobile() { return m_mob; }

private:
	char *m_name;
	char *m_mob;
};
#endif
