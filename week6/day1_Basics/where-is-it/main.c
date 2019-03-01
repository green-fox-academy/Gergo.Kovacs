#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_character_in_string(char letter, char text[]);
void run_first_test()
{
    char given_string[] = "embedded";

    char given_char = 'd';

    int result = get_character_in_string(given_char, given_string);

    if (result == 4) {
        printf("First test case passed!");
    } else {
        printf("First test case not passed");
    }
}

int main()
{
    run_first_test();

    return 0;
}
int get_character_in_string(char letter, char text[])
{
    int size = strlen(text);
    for (int i = 0; i < size; ++i) {
        if (letter == text[i]) {
            return i;
        }
    }
    return -1;
}