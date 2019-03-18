#include "car_register.h"

int main()
{

    car_t car_list[3];

    car_list[0].car_name ="Lancia";
    car_list[0].year_of_manufacture = 2013;
    car_list[0].transmission = AUTOMATIC;

    car_list[1].car_name = "Alfa Romeo";
    car_list[1].year_of_manufacture = 2017;
    car_list[1].transmission = AUTOMATIC;

    car_list[2].car_name = "Fiat";
    car_list[2].year_of_manufacture = 2015;
    car_list[2].transmission = SEMI_AUTOMATIC;

    int result_number_year_manufactured = get_cars_older_than(car_list, 3, 2017);
    printf("number of cars then older then 2017: %d\n", result_number_year_manufactured);

    int result_number_same_transmission = get_transmission_count(car_list, 3,AUTOMATIC);
    printf("number of cars that has the same transmission:  %d", result_number_same_transmission);

    return 0;
}