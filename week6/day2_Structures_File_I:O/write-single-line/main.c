#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *file_input;
    file_input = fopen("../my-text.txt", "w");

    fprintf(file_input, "First try: Kovács Gergő\n");

    fputs("Second try: Kovács Gergő\n", file_input);

    char name[25] = "Third try: Kovács Gregő\n";

    for (int i = 0; i < sizeof(name); ++i) {
        fputc(name[i], file_input);
    }
    fclose(file_input);
    return 0;
}