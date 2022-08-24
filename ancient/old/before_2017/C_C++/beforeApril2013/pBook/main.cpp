#include "commonData.h"
#include "phonebook.h"

int main(void)
{
    PhoneBook *pbook = new PhoneBook(FILETYPE);
    Contact *c = new Contact("rakesh", "sadhu", "9686862367", "9966680427");
    pbook->addContact(c);
    QVector<Contact *> *list = pbook->findContacts("rakesh");
    Contact *o;
    int i = -1;
    while (++i < list->size())
    {
        o = list->at(i);
        qDebug() << "\nname :: " << o->fname << "\nsurname ::" << o->lname << "\nmob:: " << o->mob << "\n tele" << o->landline << endl;
    }
    delete pbook;
    return 0;
}
