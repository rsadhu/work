#include"phonebook.h"


int main(void)
{
	int key;
	init();
	while(1)
	{
		 printf("\n 1.Add New Contact\n");
		 printf("\n 2.Find Contact\n");
		 printf("\n 3.Delete Contact\n");
		 printf("\n 3.Update  Contact\n");
		 printf("\n Enter the choice\n");
		 scanf("%d",&key);
		 switch(key)
		 {
			 case 1:
				 addContact();
				 break;
         	         case 2:
				 {
				 Contact *p;
				 findContact(p);
				 break;
				 }
			 case 3:
				 deleteContact();
				 break;
			 case 4:
				 updateContact();
				 break;
			 case 0:
			 default:
				 {
				  close();
				 printf("\n : Exitting\n");
				 }
				 return 0;
		}

	}
 return 0;
}

