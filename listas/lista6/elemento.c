#include <stdio.h>

void ordenar_bolha_crescente(int array[], int n, int j)
{
    if (j >= n - 1)
        return;

    if (array[j] > array[j + 1])
    {
        int temp_a = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp_a;
    }

    return ordenar_bolha_crescente(array, n, j + 1);
}

// n = tamanho da array
void controlar_bolha_crescente(int array[], int n)
{
    if (n == 0)
        return;

    ordenar_bolha_crescente(array, n, 0);

    return controlar_bolha_crescente(array, n - 1);
}

void ordenar_bolha_decrescente(int array[], int n, int j)
{
    if (j >= n - 1)
        return;

    if (array[j] < array[j + 1])
    {
        int temp_a = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp_a;
    }

    return ordenar_bolha_decrescente(array, n, j + 1);
}

void controlar_bolha_decrescente(int array[], int n)
{
    if (n == 0)
        return;

    ordenar_bolha_decrescente(array, n, 0);

    return controlar_bolha_decrescente(array, n - 1);
}

void request_input(int quant_restante, int numeros[])
{
    if (quant_restante == 0)
    {
        return;
    }

    scanf("%d", &numeros[quant_restante - 1]);

    return request_input(quant_restante - 1, numeros);
}

int main()
{
    int array[6];
    request_input(6, array);

    controlar_bolha_crescente(array, 6);

    printf("%d\n", array[0]);

    controlar_bolha_decrescente(array, 6);

    printf("%d\n", array[0]);

    return 0;
}

/*
    USADO SOMENTE PARA TESTE, CALMA!

    int array[10] = {68, 5, 3, 6, 8, 1, 35, 31, 45, 123};

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    controlar_bolha_crescente(array, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    controlar_bolha_decrescente(array, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
 */