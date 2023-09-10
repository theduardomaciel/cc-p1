#include <stdio.h>

void swap(int *a, int *b)
{
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

void bubble(int array[], int array_size, int index, int isDescending)
{
    // Condição de parada: paramos sempre um elemento antes para evitar o overflow (acessar um elemento que não existe na array)
    if (index >= array_size - 1)
        return;

    // Se o elemento anterior for menor que o posterior, trocamos de lugar
    if (!isDescending && array[index] > array[index + 1] || isDescending && array[index] < array[index + 1])
    {
        swap(&array[index], &array[index + 1]);
    }

    return bubble(array, array_size, index + 1, isDescending);
}

// index = inicia no tamanho da array
void ordenar_array(int array[], int index, int isDescending)
{
    // Condição de parada: chegamos ao index 0, ou seja, percorremos toda a array
    if (index == 0)
        return;

    // Aplicamos o algoritmo bubble desde o elemento inicial (array[0]) ao elemento final.
    // Em razão da otimização, consideramos (array[index]) como elemento final, visto que os outros elementos já foram ordenados
    bubble(array, index, 0, isDescending);

    return ordenar_array(array, index - 1, isDescending);
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

    ordenar_array(array, 6, 1);

    printf("%d\n", array[0]);

    ordenar_array(array, 6, 0);

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

/*
void bubble_decrescente(int array[], int n, int index)
{
    if (index >= n - 1)
        return;

    if (array[index] < array[index + 1])
    {
        int temp_a = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp_a;
    }

    return bubble_decrescente(array, n, index + 1);
}

void ordenar_decrescente(int array[], int n)
{
    if (n == 0)
        return;

    bubble_decrescente(array, n, 0);

    return ordenar_decrescente(array, n - 1);
}

*/