#include"pbook.h"

int main(void)
{
 Contact obj;
 PBook *pb =  PBook::getInstance();
 pb->addContact(&obj);
 return 0;
}
