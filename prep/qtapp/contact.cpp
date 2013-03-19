#include "contact.h"

Contact::Contact(uint mob, char *name):m_mob(mob)
{
 qDebug()<<"\n Contact::Contact\n";
 int tmplen = strlen(name);
 if(tmplen!=0){
     m_fname = new char[tmplen+1];
    memcpy(m_fname,name,tmplen);
}
}

Contact::Contact(const Contact &rhs)
{
    qDebug()<<"\n Contact::Contact copy\n";
    int tmplen = strlen(rhs.m_fname);
    if(tmplen!=0){
        m_fname = new char[tmplen+1];
       memcpy(m_fname,rhs.m_fname,tmplen);
   }

}

Contact & Contact:: operator=(const Contact &rhs)
{
    qDebug()<<"\n Contact::operator = \n";
 if(!this->m_fname)
     return *this;
 int tmplen = strlen(this->m_fname);

 if(tmplen>=0)
 {
   delete this->m_fname;
   this->m_fname= new char[tmplen+1];
   memcpy(this->m_fname,rhs.m_fname,tmplen);
 }
 return *this;
}

