#ifndef CONTACT_H
#define CONTACT_H
#include"global.h"
class Contact
{
 public:
 Contact (){ m_fname=NULL,m_mob=0;}
 explicit Contact(uint mob,char *name = "");
 Contact(const Contact &rhs);
 Contact & operator=(const Contact &rhs);
 char *m_fname;
 uint m_mob;
};

#endif // CONTACT_H
