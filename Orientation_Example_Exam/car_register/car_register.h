#ifndef CAR_REGISTER_CAR_REGISTER_H
#define CAR_REGISTER_CAR_REGISTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
  MANUAL,
  AUTOMATIC,
  CVT,
  SEMI_AUTOMATIC,
  DUAL_CLUTCH

} transmission_t;

typedef struct
{
  //char car_name[255];
  char *car_name;
  float price_of_car_EURO;
  unsigned short year_of_manufacture;
  transmission_t transmission;
} car_t;

int get_cars_older_than(car_t *cars, int array_length, int age);
int get_transmission_count(car_t *cars, int array_length, transmission_t transmission);

//transmission_t get_transmission_type(transmission_t transmission);


#endif //CAR_REGISTER_CAR_REGISTER_H
