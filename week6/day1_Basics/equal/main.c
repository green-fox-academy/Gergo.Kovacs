#include <stdio.h>
#include <stdlib.h>

int equal(int a, int b);
int main()
{
    int first_number;
    int second_number;
    printf("give me the first number:\n");
    scanf("%d", &first_number);
    printf("give me the second number:\n");
    scanf("%d", &second_number);

    if (equal(first_number, second_number)) {
        printf("two number is equal.\n");
    } else {
        printf("two number is not equal\n");
    }

    return 0;
}
int equal(int a, int b)
{
/*
    if (a == b) {
    printf("two number is equal.\n");
    } else {
        printf("two number is not equal.\n");
    }
*/
    return a == b;
}