#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include"commonData.h"
#include"iteratorContact.h"


class DataBaseManager
{
public:
    DataBaseManager();
    void setPointer(void *p);
    virtual ~DataBaseManager();

    virtual  void read(Contact *)
    {
        qDebug()<<"DataBaseManager::read::not Implemented\n";
    }

    virtual void write(Contact *)
    {
        qDebug()<<"DataBaseManager::write::not Implemented\n";
    }

    void init(){ if(m_cache)m_cache->init(m_dbPointer,m_dbtype);}


    DBTYPE getDbType(){ return m_dbtype;}
    void setType(DBTYPE type){ m_dbtype = type;}        

    QVector<Contact *> *searchContacts(char *p);

private:
    DBTYPE m_dbtype;
    Iterator *m_cache;
    void *m_dbPointer;
};

#endif // DATABASEMANAGER_H
