#include <stdio.h>
#include <stdlib.h>
#include "oldenough.h"

int main()
{
    int age = 0;
    printf("how old are you?\n");
    scanf("%d", &age);

    get_age(age);

    return 0;
}