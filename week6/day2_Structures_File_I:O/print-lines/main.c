#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file;
    input_file = fopen("../gameofthrones.txt", "r");

    char lines[200];
    while (!feof(input_file)) {
        fgets(lines, 200, input_file);
        printf("%s", lines);
    }

    return 0;
}