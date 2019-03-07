#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int *num_array = NULL;

    num_array = (int *) calloc(5, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", num_array[i]);
    }

    for (int i = 0; i < 5; ++i) {
        num_array[i] = rand() % 128;
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", num_array[i]);
    }

    free(num_array);

    return 0;
}