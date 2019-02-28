#include <stdio.h>

int cubeSurfaceArea(int a);
int cubeVolume(int a);
int main()
{
    int cubeSide;
    scanf("%d", &cubeSide);

    char surfaceArea[] = "SurfaceAera:";
    printf("%s %d\n", surfaceArea, cubeSurfaceArea(cubeSide));
    char volume[] = "Volume:";
    printf("%s %d\n", volume, cubeVolume(cubeSide));

    return 0;
}
int cubeSurfaceArea(int a)
{
    int result = 6 * a * a;
    return result;
}

int cubeVolume(int a)
{
    int result = a * a * a;
    return result;
}