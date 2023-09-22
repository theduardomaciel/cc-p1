#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    int numbers_on_line = 1;
    for (int i = 1; i <= Y; i += Z)
    {
        printf("%d", i);
        if (numbers_on_line % X == 0)
        {
            printf("\n");
            numbers_on_line = 1;
        }
        else
        {
            printf(" ");
            numbers_on_line += 1;
        }
    }

    printf("\n");

    return 0;
}