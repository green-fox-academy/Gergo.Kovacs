#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

float get_area(int radius);
int main()
{
    int r = 0;
    printf("give me the radius of the circle.\n");
    scanf("%d", &r);

    printf("the circle area: %.2f\n", get_area(r));

    return 0;
}
float get_area(int radius)
{
    float result = (radius * radius) * PI;
    return result;
}


