#include "car_register.h"
/*
transmission_t get_transmission_type(transmission_t transmission)
{
    if (transmission == MANUAL) {
        return "MANUAL";
    } else if (transmission == AUTOMATIC) {
        return "AUTOMAITC";
    } else if (transmission == CVT) {
        return "CVT";
    } else if (transmission == SEMI_AUTOMATIC) {
        return "SEMMI_AUTOMATIC";
    } else if (transmission == DUAL_CLUTCH) {
        return "DUAL_CLUTCH";
    }
}
*/
int get_cars_older_than(car_t *cars, int array_length, int age)
{
    unsigned short car_counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (cars[i].year_of_manufacture < age) {
            car_counter++;
        }
    }
    return car_counter;
}
int get_transmission_count(car_t *cars, int array_length, transmission_t transmission)
{
    int transmission_counter = 0;

    for (int i = 0; i < array_length; ++i) {
        if (cars[i].transmission == transmission)
        {
            transmission_counter++;
        }
    }
    return transmission_counter;
}




