
#include "iteratorContact.h"

Iterator::Iterator() : head(NULL)
{
    qDebug() << "Iterator::Iterator";
}

Iterator::~Iterator()
{
    qDebug() << "Iterator::~Iterator";
    linkList *tmp;
    while (head)
    {
        tmp = head;
        delete tmp->contactObject;
        head = head->next;
        free(tmp);
    }
}

void Iterator::init(void *handle, DBTYPE type)
{
    FILE *fp;
    if (type == FILETYPE)
    {

        fp = static_cast<FILE *>(handle);
        fseek(fp, 0, SEEK_SET);
        char name[50], surname[50], mob[50], tele[50];
        Contact *c;
        int i = 0;

        while (feof(fp) == 0)
        {
            fscanf(fp, "%s%s%s%s", name, surname, mob, tele);
            qDebug() << " name :: " << name << "\n surname ::  " << surname << "\n mob :: " << mob << "\ntele  :: " << tele << endl;
            c = new Contact(name, surname, mob, tele);
            add(c);
        }
    }
    else if (type == QTSQL)
    {
        // to be Implemented
    }

    qDebug() << "\n CHECKING IF LIST IS PROPER\n";
    display();
}

void Iterator::add(Contact *c)
{
    linkList *tmp = (linkList *)malloc(sizeof(linkList));
    tmp->contactObject = c;
    tmp->next = NULL;

    if (!head)
    {
        head = tmp;
    }
    else
    {
        linkList *tra;
        for (tra = head; tra->next != NULL; tra = tra->next)
            ;
        tra->next = tmp;
    }
}

void Iterator::del(Contact *c)
{
    qDebug() << c->fname << "\n";
}

void Iterator ::update(Contact *c)
{
    qDebug() << c->fname << "\n";
}

Contact &Iterator::operator*()
{
    Contact *c = new Contact(head->contactObject);
    return *c;
}

void Iterator::display()
{
    linkList *tra = head;
    while (tra)
    {
        qDebug() << "\n"
                 << tra->contactObject->fname << " " << tra->contactObject->lname << " " << tra->contactObject->mob << " " << tra->contactObject->landline;
        tra = tra->next;
    }
}

QVector<Contact *> *Iterator::find(char *p)
{
    qDebug() << "\nIterator::find\n";
    linkList *tra = head;
    Contact *obj;
    QVector<Contact *> *cVector = new QVector<Contact *>();
    while (tra)
    {
        obj = tra->contactObject;
        if (strcmp(p, obj->fname) == 0 || strcmp(p, obj->lname) == 0 || strcmp(p, obj->mob) == 0 || strcmp(p, obj->landline) == 0)
        {
            cVector->push_back(obj);
        }
        tra = tra->next;
    }
    qDebug() << "\nIterator;:find:;size :: " << cVector->size() << endl;
    return cVector;
}
