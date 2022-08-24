#include "phonebook.h"

PhoneBook::PhoneBook(DBTYPE type) : m_dmngr(NULL)
{
    qDebug() << "PhoneBook::PhoneBook\n";
    if (!m_dmngr)
    {
        if (type == FILETYPE)
            m_dmngr = new FileMngr();
        else if (type == QTSQL)
            m_dmngr = new QtBook();
        m_dmngr->setType(type);
        m_dmngr->init();
    }
}

PhoneBook::~PhoneBook()
{
    qDebug() << "PhoneBook::~PhoneBook\n";
    delete m_dmngr;
}

void PhoneBook::addContact(Contact *c)
{
    qDebug() << "PhoneBook::addContact\n";
    m_dmngr->write(c);
}

void PhoneBook::deleteContact(Contact *c)
{
    qDebug() << "PhoneBook::deleteContact\n";
}

void PhoneBook::updateContact(Contact *c)
{
    qDebug() << "PhoneBook::updateContact\n";
}

QVector<Contact *> *PhoneBook::findContacts(char *c)
{
    qDebug() << "PhoneBook::findContact\n";
    QVector<Contact *> *p = m_dmngr->searchContacts(c);
}
