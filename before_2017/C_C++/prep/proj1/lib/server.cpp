#include"ContactManager.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    ContactManager *service = ContactManager::getInstance();
    if(service)
    {
         cout<<" service is ready..";
		 int i=0,num =100;
         char buff[10][6]={"1234","2345","45566","55677","3000","23421","23311","1111","2222","4456"};
		 while(i<10)
         {
    		 Contact c("rakesh",buff[i]);
    		 service->addContact(c);
             i++;
		 }
		 service->displayAll();
		}
    else
    {
         cout<<" service is not ready..";
    }
     return 0;
}
