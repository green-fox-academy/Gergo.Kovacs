#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_lenght(char text[]);
int main()
{
    char sentence[] = "Geri";
    int lenght = get_lenght(sentence);

    printf("The lenght of the typed sentence is %d\n", lenght);
    return 0;
}
int get_lenght(char text[])
{
    int result = 0;
    result = strlen(text);
    return result;
}