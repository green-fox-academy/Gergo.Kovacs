#include "organising.h"
#include <stdio.h>
#include <stdlib.h>
float get_area(int radius)
{
    float result = (radius * radius) * PI;
    return result;
}
float get_circumference(int radius)
{

    return 2 * radius * PI;
}
