#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int array[] = {103, 114, 101, 101, 110, 32, 102, 111, 120};
    for (int i = 0; i < sizeof(array) / sizeof(array[i]); ++i) {
        printf("%c", array[i]);
    }
    return 0;
}