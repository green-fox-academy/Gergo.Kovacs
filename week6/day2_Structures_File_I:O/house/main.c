#include "house.h"

int main()
{
    house_t large_house;
    strcpy(large_house.address, "Petőfi út 41/a");
    large_house.price = 860000;
    large_house.number_of_rooms = 5;
    large_house.house_area = 75;
    decide(&large_house);

    house_t small_house;
    strcpy(small_house.address, "Deák Ferenc útca 12.");
    small_house.price = 160.900;
    small_house.number_of_rooms = 2;
    small_house.house_area = 30;
    decide(&small_house);

    house_t houses[] = {large_house, small_house};

    int size_of_array = sizeof(houses) / sizeof(houses[0]);

    printf("\n");

    printf("The number of houses are worth to buy is %d.", get_number_of_house(houses, size_of_array));

    return 0;
}