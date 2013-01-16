#ifndef PBOOK_H
#define PBOOK_H
#include"datastructures.h"

class Pbook_P;

class PBook
{
 PBook(){ cout<<"PBook::PBook\n";}
 PBook(const PBook &);
 public:
 static PBook * getInstance();
 void addContact(Contact *);
 void deleteContact(Contact *);
 void updateContact(Contact *);
 Contact * find(Contact *); 
 private:
 Pbook_P *m_ptr;
 static PBook  *self;
};
#endif //

