#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*
    Escreva um programa que leia uma matriz 3 x 3 de inteiros da entrada padrão e calcule:
        1. a média de todos seus valores positivos,
        2. o menor valor lido,
        3. o valor delta
        4. e a soma de todos os elementos que não estão na diagonal principal.

    O delta é igual a 1 se o menor valor for par e 0 se for ímpar.
*/

int main()
{
    int matrix[3][3];

    // Preenchemos a matriz com o input do usuário
    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            scanf("%d", &matrix[line][column]);
        }
    }

    // Realizamos a soma dos elementos para calcular a média dos valores positivos
    double sum = 0;
    int quant_positive_values = 0;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            int value = matrix[line][column];
            if (value > 0)
            {
                sum += matrix[line][column];
                quant_positive_values++;
            }
        }
    }

    // Calculamos a média
    double average = sum / quant_positive_values;

    // Obtemos o menor número da matriz
    int smallest_number = INT_MIN;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            int value = matrix[line][column];
            if (value <= smallest_number || smallest_number == INT_MIN)
            {
                smallest_number = value;
            }
        }
    }

    // Determinamos o delta
    int delta = smallest_number % 2 == 0 ? 1 : 0;

    // Calculamos a soma dos elementos QUE NÃO ESTÃO na diagonal principal (diagonal da esquerda para a direita = ↘)
    int not_in_main_diagonal_sum = 0;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (line == column)
            {
                continue;
            }
            else
            {
                not_in_main_diagonal_sum += matrix[line][column];
            }
        }
    }

    printf("%.2lf %d %d %d\n", average, smallest_number, delta, not_in_main_diagonal_sum);

    return 0;
}