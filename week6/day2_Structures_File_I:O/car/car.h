#ifndef CAR_CAR_H
#define CAR_CAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum car_type
{
  VOLVO,
  TOYOTA,
  LAND_ROVER,
  TESLA
};

typedef struct
{
  enum car_type type;
  double km;
  double gas;
} car_t;

char *get_car_name(enum car_type name);
void print_car(car_t car);

#endif //CAR_CAR_H
