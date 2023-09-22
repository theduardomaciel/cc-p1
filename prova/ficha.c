#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

// 6 atributos: Força, Destreza, Constituição, Sabedoria, Inteligência e Carisma
// São jogados 4d6 (4 dados de 6 faces) e OS TRÊS MAIORES VALORES SÃO SOMADOS.

/*
    ORDEM:

    For
    Des
    Con
    Sab
    Int
    Car
*/

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

void request_input(int index, int amount, int array[])
{
    if (index == amount)
    {
        return;
    }

    /* scanf("%d %d %d %d", &array[0], &array[1], &array[2], &array[3]);
    printf("array[%d]: %d\n", array[]); */
    scanf("%d", &array[index]);

    request_input(index + 1, amount, array);
}

int main()
{
    int dado1[4];
    int dado2[4];
    int dado3[4];
    int dado4[4];
    int dado5[4];
    int dado6[4];

    request_input(0, 4, dado1);
    request_input(0, 4, dado2);
    request_input(0, 4, dado3);
    request_input(0, 4, dado4);
    request_input(0, 4, dado5);
    request_input(0, 4, dado6);

    ordenar_array(dado1, 4, 1);
    ordenar_array(dado2, 4, 1);
    ordenar_array(dado3, 4, 1);
    ordenar_array(dado4, 4, 1);
    ordenar_array(dado5, 4, 1);
    ordenar_array(dado6, 4, 1);

    int somas[6];

    somas[0] = dado1[0] + dado1[1] + dado1[2];
    somas[1] = dado2[0] + dado2[1] + dado2[2];
    somas[2] = dado3[0] + dado3[1] + dado3[2];
    somas[3] = dado4[0] + dado4[1] + dado4[2];
    somas[4] = dado5[0] + dado5[1] + dado5[2];
    somas[5] = dado6[0] + dado6[1] + dado6[2];

    /* printf("Soma 0: %d\n", somas[0]);
    printf("Soma 1: %d\n", somas[1]);
    printf("Soma 2: %d\n", somas[2]);
    printf("Soma 3: %d\n", somas[3]);
    printf("Soma 4: %d\n", somas[4]);
    printf("Soma 5: %d\n", somas[5]); */

    ordenar_array(somas, 6, 1);

    int ordem_de_prioridade[6];
    scanf("%d %d %d %d %d %d", &ordem_de_prioridade[0], &ordem_de_prioridade[1], &ordem_de_prioridade[2], &ordem_de_prioridade[3], &ordem_de_prioridade[4], &ordem_de_prioridade[5]);

    printf("For = %d\n", somas[ordem_de_prioridade[0] - 1]);
    printf("Des = %d\n", somas[ordem_de_prioridade[1] - 1]);
    printf("Con = %d\n", somas[ordem_de_prioridade[2] - 1]);
    printf("Sab = %d\n", somas[ordem_de_prioridade[3] - 1]);
    printf("Int = %d\n", somas[ordem_de_prioridade[4] - 1]);
    printf("Car = %d\n", somas[ordem_de_prioridade[5] - 1]);

    return 0;
}