#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("%c\n",65);

    printf("%d\n", 65);

    long ret;
    char str[] = "65";
    ret = strtol(str, NULL, 10);

    printf("%d", ret);

    return 0;
}