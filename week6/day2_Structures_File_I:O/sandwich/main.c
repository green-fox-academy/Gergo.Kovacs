#include "sandwich.h"

int main()
{
    sandwich_t sandwich;
    strcpy(sandwich.name, "Bigmac");
    sandwich.price = 1190;
    int oreder;
    printf("how many %s do you want to order?\n", sandwich.name);
    scanf("%d", &oreder);
    printf("The %d db %s price will be: %d Ft", oreder, sandwich.name, sandwich_price_calcluator(sandwich, oreder));

    return 0;
}