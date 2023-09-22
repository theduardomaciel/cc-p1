#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    for (int i = 1; i <= Y; i++)
    {
        printf("%d", i);
        if (i % X == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    return 0;
}