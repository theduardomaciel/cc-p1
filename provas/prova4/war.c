#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    OBSERVAÇÕES:

    OBS 1: OS ESPAÇOS ADJACENTES À COORDENADA DO ATAQUE RECEBEM METADE DO DANO
    OBS 2: A MATRIZ FINAL NÃO PODE EXIBIR NÚMEROS NEGATIVOS
    OBS 3: N >= M >= 3
    OBS 4: X INDICA A LINHA E Y INDICA A COLUNA
*/

void board_print(int lines_amount, int columns_amount, int matrix[lines_amount][columns_amount])
{
    for (int line = 0; line < lines_amount; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            printf("%d", matrix[line][column] < 0 ? 0 : matrix[line][column]);
            if (column < columns_amount - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return;
}

int main()
{
    int lines_amount, columns_amount;
    scanf("%d %d", &lines_amount, &columns_amount);
    // printf("lines: %d | columns: %d\n", lines_amount, columns_amount);

    int matrix[lines_amount][columns_amount];

    // Atribuímos os valores às casas do tabuleiro
    for (int line = 0; line < lines_amount; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            scanf("%d", &matrix[line][column]);
        }
    }

    // board_print(lines_amount, columns_amount, matrix);

    int attacks_amount;
    scanf("%d", &attacks_amount);
    // printf("quantidade de ataques: %d\n", attacks_amount);

    // Realizamos os ataques
    for (int i = 0; i < attacks_amount; i++)
    {
        int x, y, D; // D = ataque
        scanf("%d %d %d", &x, &y, &D);

        // printf("x: %d | y: %d | ataque: %d\n", x, y, D);

        /* for (int line = 0; line < lines_amount; line++)
        {
            for (int column = 0; column < columns_amount; column++)
            {
                if (line == x && column == y)
                {
                    printf("%d (-%d)\t", matrix[line][column] < 0 ? 0 : matrix[line][column], D);
                }
                else
                {
                    printf("%d\t", matrix[line][column] < 0 ? 0 : matrix[line][column]);
                }
            }
            printf("\n");
        } */

        // Atacamos com o valor cheio nas coordenadas fornecidas
        matrix[x][y] -= D;

        // E damos metade do dano nos espaços adjacentes às coordenadas

        // à esquerda
        // printf("Esquerda: %d - 1 = %d\n", x, x - 1);
        if (x - 1 >= 0)
        {
            // printf("[%d, %d] = %d - %d = %d\n", x - 1, y, matrix[x - 1][y], D / 2, matrix[x - 1][y] - D / 2);
            matrix[x - 1][y] -= D / 2;
        }

        // à direita
        if (x + 1 < lines_amount)
        {
            matrix[x + 1][y] -= D / 2;
        }

        // acima
        if (y - 1 >= 0)
        {
            matrix[x][y - 1] -= D / 2;
        }

        // abaixo
        if (y + 1 < columns_amount)
        {
            matrix[x][y + 1] -= D / 2;
        }

        // digonal esquerda cima
        if (x - 1 >= 0 && y - 1 >= 0)
        {
            matrix[x - 1][y - 1] -= D / 2;
        }

        // digonal direita cima
        if (x + 1 < lines_amount && y - 1 >= 0)
        {
            matrix[x + 1][y - 1] -= D / 2;
        }

        // digonal esquerda baixo
        if (x - 1 >= 0 && y + 1 < columns_amount)
        {
            matrix[x - 1][y + 1] -= D / 2;
        }

        // digonal direita baixo
        if (x + 1 < lines_amount && y + 1 < columns_amount)
        {
            matrix[x + 1][y + 1] -= D / 2;
        }
    }

    // Printamos a matriz final com os danos aplicados
    board_print(lines_amount, columns_amount, matrix);

    return 0;
}