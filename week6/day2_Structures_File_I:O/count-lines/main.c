#include <stdio.h>
#include "countlines.h"

int main()
{

    char file_name[] = "../GOT.txt";
    printf("%d", (get_lines(file_name)));

    return 0;
}
