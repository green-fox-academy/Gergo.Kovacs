#include <stdio.h>
#include <stdlib.h>
#include "oldenough.h"

char get_age(unsigned int a)
{

    if (a >= 18) {
        printf("you are old enough to buy alcohol!");
    } else {
        printf("you are not old enough to by alcohol!");
    }

    return 0;
}
