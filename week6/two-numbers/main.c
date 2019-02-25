#include <stdio.h>

int main()
{
    int a = 22;
    int b = 13;

    int c = a + b;
    printf("%d\n", c);

    int d = a - b;
    printf("%d\n", d);

    int e = a * b;
    printf("%d\n", e);

    float f = (float)a/b;
    printf("%.2f\n",f);

    int g=a%b;
    printf("%d\n",g);



    return 0;
}