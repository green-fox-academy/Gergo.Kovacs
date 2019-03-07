#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *num_array;
    num_array = (int *) malloc(5 * sizeof(int));

    for(int i =0; i <5; ++i){
        num_array[i]=rand()%5+1;
    }

    for ( int j = 0; j <5; ++j){
        printf("%d\n",num_array[j]);
    }
    free(num_array);

    return 0;
}