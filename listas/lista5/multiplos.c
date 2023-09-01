#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void verificar_multiplos(int i, int num1, int num2, int *quant_multiplos)
{
    if (i < 50)
    {
        if (i % num1 == 0 && i % num2 == 0)
        {
            // printf("%d é um múltiplo tanto de %d como de %d!\n", i, num1, num2);
            *quant_multiplos += 1;
        }
        return verificar_multiplos(i + 1, num1, num2, quant_multiplos);
    }

    return;
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int quant_multiplos = 0;
    verificar_multiplos(1, num1, num2, &quant_multiplos);
    printf("%d\n", quant_multiplos);

    return 0;
}