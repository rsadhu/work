#include <iostream>
#include "webserver.h"

int main(void)
{
    WebServer wb("", 8100);
    wb.start();
    return 0;
}