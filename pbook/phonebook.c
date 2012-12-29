#include"phonebook.h"

static FILE *fp=NULL;
void init(void)
{
	 fp = fopen("pb.txt","r+");
}

void close()
{
	if(fp)
	fclose(fp);
}

void addContact()
{
 printf("\n addContact called\n");
	Contact *contact = (Contact *)malloc(sizeof(Contact));
	
	printf("\n 1.Enter the FirstName ");
	puts(contact->firstName);
	printf("\n 2.Enter the SecondName ");
	puts(contact->secondName);
	printf("\n 3.Enter the FirstNumber ");
	puts(contact->firstNumber);
	printf("\n 4.Enter the SecondNumber ");
	puts(contact->secondNumber);
}

void updateContact()
{

}

int deleteContact()
{

}

Contact* findContact(Contact *f)
{

}


