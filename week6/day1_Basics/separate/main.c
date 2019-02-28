#include <stdio.h>
#include "organising.h"

int main()
{
    int r = 0;
    printf("Give me the radius of a circle.\n");
    scanf("%d", &r);

    printf("The circle area is: %.2f\n", get_area(r));
    printf("The circle circumference: %.2f\n", get_circumference(r));

    return 0;
}