#include <stdio.h>

void redutor(double *x, double *y)
{
    *x = *x - *y;
}

int main()
{
    double x, y;
    scanf("%lf %lf", &x, &y);

    redutor(&x, &y);

    printf("%.2lf %.2lf\n", x, y);

    return 0;
}