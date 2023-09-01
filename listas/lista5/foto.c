#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
    if (*(double *)a > *(double *)b)
    {
        return 1;
    }
    else if (*(double *)a < *(double *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void print_array(int index, double array[4])
{
    if (index < 4)
    {
        printf("%.2lf\n", array[index]);
        return print_array(index + 1, array);
    }

    return;
}

double main()
{
    double num1, num2, num3, num4;
    scanf("%lf %lf %lf %lf", &num1, &num2, &num3, &num4);

    double base_array[4] = {num1, num2, num3, num4};
    qsort(base_array, 4, sizeof(base_array[0]), compare);

    // Aplicamos as regras particulares de Ambrosina
    double new_array[4];
    new_array[0] = base_array[0]; // a pessoa mais baixa deve ficar sempre no index 0
    new_array[3] = base_array[1]; // a segunda mais baixa deve ficar no index 3 (última posição)
    new_array[1] = base_array[2]; // logo após a mais baixa (0 + 1 = index 1), fica a terceira mais baixa
    new_array[2] = base_array[3]; // em seguida a mais alta

    print_array(0, new_array);

    return 0;
}