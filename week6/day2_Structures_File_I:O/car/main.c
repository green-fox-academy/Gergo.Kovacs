#include "car.h"

int main()
{

    car_t volvo;
    volvo.type = VOLVO;
    volvo.km = 123.254;
    volvo.gas = 7.9;

    car_t toyota;
    toyota.type = TOYOTA;
    toyota.km = 45.124;
    toyota.gas = 5.5;

    car_t land_rover;
    land_rover.type = LAND_ROVER;
    land_rover.km = 276.349;
    land_rover.gas = 12.5;

    car_t tesla;
    tesla.type = TESLA;
    tesla.km = 89.346;

    print_car(volvo);
    print_car(tesla);

    return 0;
}