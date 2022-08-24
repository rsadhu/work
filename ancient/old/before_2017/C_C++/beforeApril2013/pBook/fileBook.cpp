#include "fileBook.h"

FileMngr::FileMngr()
{
    qDebug() << "FileMngr::FileMngr\n";
    m_fp = fopen("contacts.txt", "a+");
    setPointer((void *)m_fp);
}

FileMngr::~FileMngr()
{
    qDebug() << "FileMngr::~FileMngr\n";
    fclose(m_fp);
}

void FileMngr::write(Contact *c)
{
    qDebug() << "FileMngr::write" << c->fname << " " << c->lname << " " << c->mob << " " << c->landline << "\n";
    fprintf(m_fp, "%s %s %s %s%s", c->fname, c->lname, c->mob, c->landline, "\n");
}

void FileMngr::read(Contact *c)
{
    qDebug() << "FileMngr::read\n";
    Contact *con = new Contact;
    con->fname = new char[255];
    con->lname = new char[255];
    con->mob = new char[255];
    con->landline = new char[255];
}
