#include <stdio.h>
#include <stdlib.h>
int odd_or_even(int a);
int main()
{
    int number = 0;
    printf("Give me a number and i will tell you if its even or odd.\n");
    scanf("%d", &number);

    if (odd_or_even(number)) {
        printf("The given number is even.\n");
    } else {
        printf("The given number is odd.\n");
    }

    return 0;
}
int odd_or_even(int a)
{
    return (a % 2 == 0);
}