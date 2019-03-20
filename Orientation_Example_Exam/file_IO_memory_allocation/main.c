#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input_file;
    input_file = fopen("../A66_Logs.txt", "r");

    char ch[2] = " ";
    unsigned short number_of_the_same_door = 0;

    char *str_array = (char *) malloc(sizeof(char));

    while (!feof(input_file)) {

        int is_end_line = 0;
        int index_counter = 0;

        while (!is_end_line && !feof(input_file)) {

            ch[0] = fgetc(input_file);
            str_array[index_counter] = ch[0];
            str_array = (char *) realloc(str_array, index_counter + 2);
            str_array[index_counter + 1] = '\0';
            index_counter++;
            is_end_line = !strcmp(ch, "\n");
        }

        char *number = strtok(str_array, ",");
        char *data = strtok(NULL, ",");
        char *acces = strtok(NULL, ",");
        char *number2 = strtok(NULL, ",");
        char *number3 = strtok(NULL, ",");
        char *door = strtok(NULL, ",");

        int test_of_door = strcmp(door, "A66 - 04 FÕBEJÁRAT (F-1) Door #1");

        if (!test_of_door) {
            number_of_the_same_door++;
        }
    }

    printf("the number of doors that we sought: %d", number_of_the_same_door);

    fclose(input_file);
    free(str_array);

    return 0;
}
