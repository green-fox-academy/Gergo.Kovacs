#ifndef HOUSE_HOUSE_H
#define HOUSE_HOUSE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char address[50];
  double price;
  int number_of_rooms;
  double house_area;

} house_t;

void decide(house_t *house);
int get_number_of_house(house_t houses[], int size);

#endif //HOUSE_HOUSE_H
