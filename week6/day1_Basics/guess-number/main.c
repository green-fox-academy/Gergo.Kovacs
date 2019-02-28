#include <stdio.h>

int main()
{
    int guess_number = 0;
    int correct_number = 8;

    do {
        printf("Guess a number between 0-10.\n");
        scanf("%d", &guess_number);

        if (guess_number > correct_number) {
            printf("The stored number is higher.\n");
        } else if (guess_number < correct_number) {
            printf("The stored number is lower.\n");
        } else {
            printf("You found the number: 8");
        }
    } while (guess_number != correct_number);

    return 0;
}