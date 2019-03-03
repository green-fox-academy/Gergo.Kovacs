#include "sandwich.h"

int sandwich_price_calcluator(sandwich_t sandwich, int order)
{
    int final_price = (sandwich.price * order);
    return final_price;
}
