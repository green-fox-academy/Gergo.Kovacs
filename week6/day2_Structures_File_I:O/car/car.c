#include "car.h"

char *get_car_name(enum car_type name)
{
    switch (name) {
        case VOLVO: return "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "Tesla";
    }
}

void print_car(car_t car)
{
    if (car.type != TESLA) {
        printf("This is %s it has %.2f km in it and has %.1f gas is use in 100km.\n",
               get_car_name(car.type),
               car.km,
               car.gas);
    } else {
        printf("This is %s it has %.2f km in it and this is a Tesla so this car is electric.\ny",
               get_car_name(car.type),
               car.km);

    }
}
