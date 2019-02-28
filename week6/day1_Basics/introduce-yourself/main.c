#include <stdio.h>

int main()
{
    char firstName[20];
    scanf("%s", firstName);

    char secondName[20];
    scanf("%s\n", secondName);

    int age;
    scanf("%d", &age);

    float height;
    scanf("%f", &height);

    printf("%s\n", firstName);
    printf("%s\n", secondName);
    printf("%d\n", age);
    printf("%.2f\n", height);

    return 0;
}