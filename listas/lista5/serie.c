#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// S = 1 + 2/3 + 3/4 + 8/6 + 5/16 + 32/9 + 7/64 + ...

// Começamos a nossa série desconsiderando o 1, partindo do index 1
// ou seja, index 1 = 2/3, index 2 = 3/4
void calcular_serie(int index, int quant_elementos, float *total)
{
    if (index <= quant_elementos)
    {
        bool eh_par = index % 2 == 0;

        int potencia_2 = pow(2, index);

        int quant_pares = index / 2;
        int multiplo_3 = 3 + (3 * quant_pares);

        int index_mais_1 = index + 1;

        int numerador = eh_par ? index_mais_1 : potencia_2;
        int denominador = eh_par ? potencia_2 : multiplo_3;

        // printf("numerador: %d e denominador: %d\n", numerador, denominador);

        *total += numerador / (double)denominador;

        return calcular_serie(index + 1, quant_elementos, total);
    }

    return;
}

int main()
{
    int n_elementos;
    scanf("%d", &n_elementos);

    float total = 1;
    calcular_serie(1, n_elementos - 1, &total);

    printf("S: %.2lf\n", total);

    return 0;
}