#include <stdio.h>
#include <string.h>
#include <string.h>

char sentence(char array[]);
int main()
{
    printf("Type a sentence:\n");
    char string[256];

    gets(string);
    sentence(string);
    printf("%s", string);

    return (0);
}
char sentence(char array[])
{
    char *sentence = strtok(array, " ");
    while (!sentence == NULL) {
        puts(sentence);
        {
            sentence = strtok(NULL, " ");
        }
    }
}