#include <stdio.h>
#include <stdlib.h>

int input(int index, double originais[5], double descontados[5])
{
    if (index > 0)
    {
        scanf("%lf %lf", &originais[index], &descontados[index]);
        return input(index - 1, originais, descontados);
    }
}

int comparar_precos(int index, double originais[5], double descontados[5])
{
    if (index < 0)
    {
        return 0;
    }
    else
    {
        if (descontados[index] <= (originais[index] - ((20 / 100.0) * originais[index])))
        {
            return 1 + comparar_precos(index - 1, originais, descontados);
        }
        else
        {
            return comparar_precos(index - 1, originais, descontados);
        }
    }
}

int main()
{
    double originais[5];
    double descontados[5];

    input(5, originais, descontados);

    int quant = comparar_precos(5, originais, descontados);
    printf("%d\n", quant);

    return 0;
}