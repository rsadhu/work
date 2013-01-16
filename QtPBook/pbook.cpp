#include"pbook.h"

PBook *PBook::self;
PBook * PBook::getInstance()
{ 
if(!self)
	self = new PBook();
  return self;
}

void PBook::addContact(Contact *obj)
{

}


void  PBook::deleteContact(Contact *obj)
{

}

void  PBook::updateContact(Contact *obj)
{

}

Contact *  PBook::find(Contact *obj)
{

}
