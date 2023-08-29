#include <stdio.h>
#include <math.h>

void input(int *soma, int expoente)
{
    int digito;
    scanf("%d", &digito);

    if (digito == 1)
    {
        *soma = *soma + pow(2, expoente);
    }
}

void octeto(int atual, int soma)
{
    if (atual > 0)
    {
        input(&soma, atual - 1);
        return octeto(atual - 1, soma);
    }
    else
    {
        printf("%d", soma);
        return;
    }
}

void loop(int quant_octetos)
{
    if (quant_octetos > 0)
    {
        octeto(8, 0);
        if (quant_octetos != 1)
        {
            printf(".");
        }
        return loop(quant_octetos - 1);
    }
}

int main()
{
    loop(4);
    return 0;
}