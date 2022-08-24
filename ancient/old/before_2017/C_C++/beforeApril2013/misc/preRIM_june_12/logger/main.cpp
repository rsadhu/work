#include "logger.h"

int main(int argc, char *argv[])
{
    int i = argc;
    Logger l;
    while (argc > 0)
    {
        l.log(argv[i - argc]);
        argc--;
    }
    return 0;
}
