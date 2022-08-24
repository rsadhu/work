#include "databasemanager.h"

DataBaseManager::DataBaseManager() : m_dbtype(NONE), m_dbPointer(NULL)
{
    qDebug() << "DataBaseManager::DataBaseManager";
    m_cache = new Iterator;
}

DataBaseManager::~DataBaseManager()
{
    qDebug() << "DataBaseManager::~DataBaseManager";
    delete m_cache;
    m_dbtype = NONE;
    m_dbPointer = NULL;
}

void DataBaseManager::setPointer(void *p)
{
    qDebug() << "\nDataBaseManager::setPointer()\n";
    m_dbPointer = p;
}

QVector<Contact *> *DataBaseManager::searchContacts(char *pattern)
{
    qDebug() << "\n DBM:: searchContacts\n";
    return m_cache->find(pattern);
}
