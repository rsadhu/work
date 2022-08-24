#include <iostream>

int main(void)
{
    int **t = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        t[i] = new int(10);
    }
    // auto *t =  new auto(10);
    /*    for(int i=0;i<10;i++)
        {
            t[i]=10*i;
            std::cout<< t[i];
        }*/
    return 0;
}
