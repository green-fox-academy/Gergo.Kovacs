#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lenght(char text[]);
int main()
{
    char sentence1[50]="i like meat!";
    char sentence2[50]="i don't like meat!";

    if(get_lenght(sentence1)==get_lenght(sentence2)){
        printf("same lenght");
    }else {
        printf("not the same lenght");
    }

    return 0;
}
int get_lenght(char text[])
{
    int result;
    result = strlen(text);
    return result;
}








// Create a program which asks for two strings and stores them
// Create a function which takes two strings as parameters and
// returns 1 if the two strings are the same and 0 otherwise
// Try to erase small and uppercase sensitivity.