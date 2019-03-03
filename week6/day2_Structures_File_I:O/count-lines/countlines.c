#include "countlines.h"

int get_lines(char file_name[])
{
    FILE *input_file;
    input_file = fopen(file_name, "r");

    if (input_file == NULL)
        return -1;

    short counter = 0;
    char lienes[200];
    while (!feof(input_file)) {
        fgets(lienes, 200, input_file);
        counter++;
    }
    fclose(input_file);
    return counter;
}