#include<stdio.h>

typedef struct __contact
{
	char *firstName;
	char *secondName;
	char *firstNumber;
	char *secondNumber;
	unsigned uid ;
}Contact;

typedef struct __list
{
	Contact *head;
	struct __list *next;
}ContactList;

void addContact();
void updateContact();
int deleteContact();
Contact* findContact(Contact *);

void init();

