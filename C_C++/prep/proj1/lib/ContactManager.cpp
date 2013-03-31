#include"ContactManager.h"

ContactManager *ContactManager::m_obj;

 ContactManager * ContactManager::getInstance()
 {
 if(!m_obj)
     m_obj= new ContactManager();
  return m_obj;
 }
 
 void ContactManager::addContact(Contact &contact)
 {

 }

 void ContactManager::deleteContact(Contact &contact)
 {

 }

 Vector<Contact *>* ContactManager::findContact(Filter filter)
 {
 }



