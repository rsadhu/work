#include"ContactManager.h"
int main(void)
{
    ContactManager *service = ContactManager::getInstance();
    if(service)
    {
         cout<<" service is ready..";
		 Contact c("rakesh","1234567890");
		 service->addContact(c);
		}
    else
    {
         cout<<" service is not ready..";
    }
     return 0;
}
