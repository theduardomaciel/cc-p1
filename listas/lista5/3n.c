#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int encontrar_max(int arr[], int n)
{
    // Caso base: Se o array tiver apenas um elemento, retornamos esse elemento
    if (n == 1)
    {
        return arr[0];
    }

    // Encontramos o maior valor no subarray excluindo o primeiro elemento
    int subMax = encontrar_max(arr + 1, n - 1);

    // Comparamos o maior valor no subarray com o primeiro elemento e retorne o maior dos dois
    if (arr[0] > subMax)
    {
        return arr[0];
    }
    else
    {
        return subMax;
    }
}

void teste(int n, int *quant)
{
    *quant += 1;

    if (n == 1)
    {
        return;
    }
    else
    {
        // printf("n atual: %d\n", n);
        return teste(n % 2 == 0 ? (n / 2) : ((n * 3) + 1), quant);
    }
}

void calcular_ciclos_da_linha(int atual, int maximo, int array_tamanho_dos_ciclos[])
{
    if (atual <= maximo)
    {

        // Verificamos quantos ciclos foram necessários para a linha atual
        int tamanho_do_ciclo = 0;
        teste(atual, &tamanho_do_ciclo);

        // printf("Tamanho do ciclo: %d\n", tamanho_do_ciclo);

        // Atualizamos na array
        array_tamanho_dos_ciclos[atual] = tamanho_do_ciclo;

        return calcular_ciclos_da_linha(atual + 1, maximo, array_tamanho_dos_ciclos);
    }

    return;
}

void loop()
{
    int i, j;
    int length = scanf("%d %d", &i, &j);

    if (length == 2)
    {
        int array_tamanho_dos_ciclos[100000] = {1};

        int min = fmin((int)i, (int)j);
        int max = fmax((int)i, (int)j);

        calcular_ciclos_da_linha(min, max, array_tamanho_dos_ciclos);

        int n = sizeof(array_tamanho_dos_ciclos) / sizeof(array_tamanho_dos_ciclos[0]);
        int maior = encontrar_max(array_tamanho_dos_ciclos, n);
        printf("%d %d %d\n", i, j, maior);

        return loop();
    };

    return;
}

int main()
{
    loop();
    return 0;
}