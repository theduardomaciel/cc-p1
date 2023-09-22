#include <stdio.h>
#include <limits.h>

// Escreva um programa que leia uma matriz 3 x 3 de inteiros da entrada padrão e calcule:
/*
    1. a média de todos seus valores
    2. o maior valor lido
    3. o valor delta (baseado no maior valor)
    4. soma dos elementos da diagonal principal.
*/

// O delta é igual a 1 se o maior valor for positivo, -1 se for negativo e zero se for zero.

// SAÍDA:
// 4 valores numéricos: o primeiro é um número em ponto flutuante de duas casas decimais e os outros três inteiros.

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

    // Realizamos a soma dos elementos para calcular a média
    double sum = 0;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            sum += matrix[line][column];
        }
    }

    // Calculamos a média
    double average = sum / 9;

    // Obtemos o maior número da matriz
    int biggest_number = -INT_MAX;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            int value = matrix[line][column];
            if (value >= biggest_number)
            {
                biggest_number = value;
            }
        }
    }

    // Determinamos o delta
    int delta = biggest_number == 0 ? 0 : (biggest_number > 0 ? 1 : -1);

    // Calculamos a soma dos elementos da diagonal principal (diagonal da esquerda para a direita = ↘)
    int main_diagonal_sum = 0;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (line == column)
            {
                main_diagonal_sum += matrix[line][column];
            }
        }
    }

    printf("%.2lf %d %d %d\n", average, biggest_number, delta, main_diagonal_sum);

    return 0;
}