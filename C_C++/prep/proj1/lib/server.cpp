#include"ContactManager.h"
int main(void)
{
    ContactManager *service = ContactManager::getInstance();
    if(service)
    {
         cout<<" service is ready..";
		 int i=0;
		 while(i<10){
		 Contact c("rakesh","1234567890");
		 service->addContact(c);
		 }
		 service->displayAll();
		}
    else
    {
         cout<<" service is not ready..";
    }
     return 0;
}
