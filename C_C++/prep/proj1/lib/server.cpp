#include"ContactManager.h"
int main(void)
{
    ContactManager *service = ContactManager::getInstance();
    if(service)
    {
         cout<<" service is ready..";
    }
    else
    {
         cout<<" service is not ready..";
    }
     return 0;
}
