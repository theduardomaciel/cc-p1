#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    OBSERVAÇÕES:
        1. A ordem de leitura dos elementos é dado a cada linha, da esquerda para a direita.
        2. Caso a matriz seja vazia, imprima a string "Vazia".
*/

int main()
{
    int dimension;
    scanf("%d", &dimension);

    if (dimension == 0)
    {
        printf("Vazia\n");
    }

    int matrix1[dimension][dimension], matrix2[dimension][dimension];

    // Registramos o input correspondente à matriz 1
    for (int line = 0; line < dimension; line++)
    {
        for (int column = 0; column < dimension; column++)
        {
            scanf("%d", &matrix1[line][column]);
        }
    }

    // Registramos o input correspondente à matriz 2
    for (int line = 0; line < dimension; line++)
    {
        for (int column = 0; column < dimension; column++)
        {
            scanf("%d", &matrix2[line][column]);
        }
    }

    int sum_matrix[dimension][dimension];

    // Criamos uma nova matriz com os resultados da soma
    for (int line = 0; line < dimension; line++)
    {
        for (int column = 0; column < dimension; column++)
        {
            sum_matrix[line][column] = matrix1[line][column] + matrix2[line][column];
        }
    }

    // Printamos o resultado da soma
    for (int line = 0; line < dimension; line++)
    {
        for (int column = 0; column < dimension; column++)
        {
            printf("%d\n", sum_matrix[line][column]);
        }
    }

    return 0;
}