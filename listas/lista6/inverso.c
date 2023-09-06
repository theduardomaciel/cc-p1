#include <stdio.h>

void request_input(int quant_restante, int numeros[])
{
    if (quant_restante == 0)
    {
        return;
    }

    scanf("%d", &numeros[quant_restante - 1]);

    return request_input(quant_restante - 1, numeros);
}

void array_print(int index, int end, int array_numeros[])
{
    if (index == end)
    {
        printf("\n");
        return;
    }

    printf("%d ", array_numeros[index]);

    return array_print(index + 1, end, array_numeros);
}

int main()
{
    int quant_numeros;
    scanf("%d", &quant_numeros);

    int array_numeros[quant_numeros];
    request_input(quant_numeros, array_numeros);

    array_print(0, quant_numeros, array_numeros);

    return 0;
}