#include "ContactManager.h"

ContactManager *ContactManager::m_obj;

ContactManager::~ContactManager()
{
    fclose(m_fp);
    delete m_cache;
}

void ContactManager::init()
{
    m_fp = fopen("contactdb.txt", "a+");
    m_cache = new Cache<Contact>();
    m_cache->readAll(m_fp);
}

ContactManager *ContactManager::getInstance()
{
    if (!m_obj)
        m_obj = new ContactManager();
    return m_obj;
}

void ContactManager::addContact(Contact &contact)
{
    if (!m_cache->search(&contact))
    {
        fprintf(m_fp, "%s %s%s", contact.name(), contact.mobile(), "\n");
        m_cache->insert(&contact);
    }
    else
    {
        cout << " ContactManager::already present\n";
    }
}

void ContactManager::deleteContact(Contact &contact)
{
    m_cache->remove(&contact);
}

vector<Contact *> *ContactManager::findContact(Filter filter)
{
    vector<Contact *> *list = new vector<Contact *>();
}
