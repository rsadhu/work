#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("dummy.txt", "a+");
    int i = 0;
    while (i++ < 6)
        fprintf(fp, "%s %s%s", "rakesh", "1234", "\n");

    char name[20], mob[20];
    memset(name, 0, 20);
    memset(mob, 0, 20);
    fseek(fp, 0, SEEK_SET);
    int cnt;

    while (feof(fp) == 0)
    {
        cnt = fscanf(fp, "%s %s", name, mob);
        printf("%s %s \n", name, mob);
        if (cnt <= 0)
            break;
        printf("....... %d ....", cnt);
    }

    fclose(fp);
    return 0;
}
