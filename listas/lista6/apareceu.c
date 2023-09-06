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

int verificar_recorrencia(int alvo, int index, int size, int array[])
{
    if (index == size)
    {
        return 0;
    }

    if (array[index] == alvo)
    {
        return 1 + verificar_recorrencia(alvo, index + 1, size, array);
    }
    else
    {
        return verificar_recorrencia(alvo, index + 1, size, array);
    }
}

int main()
{
    int numeros[10];
    request_input(10, numeros);

    int numero_escolhido;
    scanf("%d", &numero_escolhido);

    int quant_encontrados = verificar_recorrencia(numero_escolhido, 0, 10, numeros);
    printf("%d\n", quant_encontrados);

    return 0;
}