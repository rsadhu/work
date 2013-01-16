#ifndef PBOOK_H
#define PBOOK_H
#include"datastructures.h"

class Pbook_P;

class PBook
{
 public:
 void addContact(char *fName,char *lName,char *mob,char *landline);
 void deleteContact(char *mob);
 void updateContact(char *fName,char *lName,char *mob,char *landline);
 Contact * find(char *mob); 
 private:
 Pbook_P *m_ptr;
};
#endif //
