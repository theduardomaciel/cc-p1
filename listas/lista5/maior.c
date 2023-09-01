#include <stdio.h>
#include <stdlib.h>

void pedir_input(int numeros[], int *quant_numeros)
{
    int input;
    scanf("%d", &input);

    if (input == 0)
    {
        return;
    }
    else
    {
        numeros[*quant_numeros] = input;
        *quant_numeros += 1;
        return pedir_input(numeros, quant_numeros);
    }
}

int verificar_maior(int index, int maior, int quant_numeros, int numeros[])
{
    if (index < quant_numeros)
    {
        if (numeros[index] > maior)
        {
            maior = numeros[index];
        }
        return verificar_maior(index + 1, maior, quant_numeros, numeros);
    }

    return maior;
}

int main()
{
    int quant_numeros = 0;
    int numeros[100];
    pedir_input(numeros, &quant_numeros);

    int maior = verificar_maior(0, 0, quant_numeros, numeros);
    printf("%d\n", maior);

    return 0;
}