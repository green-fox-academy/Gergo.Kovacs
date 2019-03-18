#include "bit_roll.h"

int count_characters(char *filename)
{

    unsigned short num = 0;

    FILE *file;

    file = fopen(filename, "r");

    while (!feof(file)) {
        fgetc(file);
        num++;
    }
    fclose(file);
    return num;
}
int binary_to_decimal(int binary_number)
{

    int decimal_value = 0;
    int base = 1;

    int temp = binary_number;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        decimal_value += last_digit * base;
        base = base * 2;
    }
    return decimal_value;

}
char *get_conversion(char *filename)
{

    int number;
    char word[10];

    FILE *file;
    file = fopen(filename, "r");

    int size = count_characters(filename);

    char buffer[size + 1];

    char *one_word;

    // line
    while (!feof(file)) {
        fgets(buffer, size, file);
    }
    fclose(file);

    char *text_array;
    text_array = (char *) malloc(sizeof(char) * size);

    file = fopen(filename, "r");

    while (!feof(file)) {
        fgets(text_array, size, file);
    }

    one_word = strtok(text_array, " ");
    while (one_word != NULL) {
        strcpy(word, one_word);
        number = atoi(word);
        printf("%c", binary_to_decimal(number));
        one_word = strtok(NULL, " \0");
    }

    fclose(file);

    return text_array;
}

/*  //character
  while(!feof(file)){
      char c= fgetc(file);
      buffer[i]=c;
      i++;
  }
*/

