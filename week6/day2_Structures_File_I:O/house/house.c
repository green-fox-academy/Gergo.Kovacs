#include "house.h"

void decide(house_t *house)
{
    if (house->price / house->house_area < 400) {
        printf("The house with %d rooms and %.2lf EUR price is worth to buy.\n", house->number_of_rooms, house->price);
    } else {
        printf("This house with %d rooms and %.2lf EUR price is not worth to buy.\n",
               house->number_of_rooms,
               house->price);

    }
}
int get_number_of_house(house_t houses[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (houses[i].price / houses[i].house_area < 400) {
            counter++;
        }
    }
    return counter;
}

