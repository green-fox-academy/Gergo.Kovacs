#include <stdio.h>
#include <stdlib.h>
int sum_of_digits(int a);

int main()
{

    int number1 = 123;//123
    int number2 = 321;//321

    //  printf("give me the first number: \n");
    // scanf("%d", &number1);

    //printf("give me the first number: \n");
    //scanf("%d", &number2);

    if (sum_of_digits(number1) == sum_of_digits(number2)) {
        printf("Two number is equal.");
    } else {
        printf("Two number is not equal.");
    }

    return 0;
}
int sum_of_digits(int a)
{
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
