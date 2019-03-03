#include <stdio.h>
#include <string.h>

void w_multiple_lines(char fpath[], char word[], int number);
int main()
{
    char fpath[] = "../my-text.txt";
    char word[] = "apple";
    char number = 5;

    if (word == "apple" && number == 5) {
        w_multiple_lines(fpath, word, number);
    } else {
        return 0;
    }

    return 0;
}
void w_multiple_lines(char fpath[], char word[], int number)
{
    FILE *file_in;
    file_in = fopen(fpath, "w");

    for (int i = 0; i < number; ++i) {
        fprintf(file_in, "%s\n", word);
    }
    fclose(file_in);
}
