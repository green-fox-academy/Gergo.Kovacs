#include <stdio.h>
#include <memory.h>

int get_nbr_of_character(char *file_name);
int get_get_nbr_lines(char *file_name);

int main()
{
    FILE *file_name;
    file_name = fopen("../A66.txt", "r");

    int size = get_nbr_of_character("../A66.txt");
    char dummy[size];
    char door_name[100];
    unsigned short counter = 0;

    while (!feof(file_name)) {
        fgets(dummy, size, file_name);

        char *number = strtok(dummy, ",");
        char *data = strtok(NULL, ",");
        char *acces = strtok(NULL, ",");
        char *number2 = strtok(NULL, ",");
        char *number3 = strtok(NULL, ",");
        char *door = strtok(NULL, ",");

        strcpy(door_name, door);

        int temp_terms = strcmp(door, "A66 - 04 FÕBEJÁRAT (F-1) Door #1");

        if (!temp_terms) {
            //printf("%s\n", door);
            counter++;
        }

    }
    //number of condition result
    printf("number of searched door: %d", counter);

    //number of lines
    //printf("the number of lines: %d", get_get_nbr_lines("../A66.txt"));
    return 0;
}

int get_nbr_of_character(char *file_name)
{
    int nbr_of_max_ch = 0;
    char ch;
    char buffer[50];
    int i;
    FILE *file;
    file = fopen("../A66.txt", "r");

    while (!feof(file)) {
        ch = fgetc(file);
        buffer[i] = ch;
        nbr_of_max_ch++;
    }
    return nbr_of_max_ch;
}

int get_get_nbr_lines(char *file_name)
{
    FILE *file;
    file = fopen("../A66.txt", "r");

    char buffer[250];
    unsigned short line_counter = 0;

    while (!feof(file)) {
        fgets(buffer, 250, file);
        line_counter++;
    }

    return line_counter;

}