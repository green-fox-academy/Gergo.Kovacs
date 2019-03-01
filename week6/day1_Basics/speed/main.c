#include <stdio.h>
#define DISTANCE 345

int main()
{
    int seconds = 17;
    float speed = DISTANCE / (float) seconds;

    printf("%f", speed);

    return 0;
}