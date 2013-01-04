#include<stdio.h>

typedef struct __contact
{
	char *firstName;
	char *secondName;
	char *firstNumber;
	char *secondNumber;	
}Contact;

typedef struct __list
{
	Contact *data;
	struct __list *next;
}ContactList;

void addtolist(Contact*);
void fillList();
void displayList();

void addContact();
void updateContact();
int deleteContact();
Contact* findContact(char*);

void init();

