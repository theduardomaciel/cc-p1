#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Ekul só é capaz de se movimentar PARA BAIXO e PARA A DIREITA
// 0 - indica a existência de uma parede que NÃO PODE SER ATRAVESSADA
// 1 - indica a existência de uma parede com fresta (que PODE SER ATRAVESSADA)
// 2 - indica a localização da dragoa

/*
    OBSERVAÇÕES:

    OBS1: A posição inicial de Ekul é sempre na coordenada (0,0) e o final do labirinto é sempre na coordenada (N-1, N-1).
    OBS2: A dragoa é capaz de sentir o cheiro de Eluk vindo de UMA CASA DE DISTÂNCIA, de todas as direções, INCLUINDO DIAGONAIS.
    OBS3: N >= 3
*/

void board_print(int lines_amount, int columns_amount, int matrix[lines_amount][columns_amount], int x, int y)
{
    for (int line = 0; line < lines_amount; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            if (x == column && y == line)
            {
                printf("X");
            }
            else
            {
                printf("%d", matrix[line][column] < 0 ? 0 : matrix[line][column]);
            }
            if (column < columns_amount - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return;
}

int can_walk_here(int x, int y, int dragoa_x, int dragoa_y)
{
    int allowed = 1;

    // Verificamos se Luke ficará à ESQUERDA da dragoa
    if (x == dragoa_x - 1 && y == dragoa_y)
    {
        // printf("A dragoa pegaria Luke pela esquerda!\n");
        allowed = 0;
    }

    // Verificamos se: o movimento de Luke está dentro do mapa, a parede é atravessável e Luke ficará à DIREITA da dragoa
    if (x == dragoa_x + 1 && y == dragoa_y)
    {
        // printf("A dragoa pegaria Luke pela direita!\n");
        allowed = 0;
    }

    // Verificamos se Luke ficará ACIMA da dragoa
    if (x == dragoa_x && y == dragoa_y - 1)
    {
        // printf("A dragoa pegaria Luke por cima!\n");
        allowed = 0;
    }

    // Verificamos se: o movimento de Luke está dentro do mapa, a parede é atravessável e se Luke ficará ABAIXO da dragoa
    if (x == dragoa_x && y == dragoa_y + 1)
    {
        // printf("A dragoa pegaria Luke por baixo!\n");
        allowed = 0;
    }

    // Verificamos se Luke ficará na DIAGONAL ESQUERDA SUPERIOR da dragoa
    if (x == dragoa_x - 1 && y == dragoa_y - 1)
    {
        // printf("A dragoa pegaria Luke pela diagonal superior esquerda!\n");
        allowed = 0;
    }

    // Verificamos se Luke ficará na DIAGONAL DIREITA SUPERIOR da dragoa
    if (x == dragoa_x + 1 && y == dragoa_y - 1)
    {
        // printf("A dragoa pegaria Luke pela diagonal superior direita!\n");
        allowed = 0;
    }

    // Verificamos se Luke ficará na DIAGONAL ESQUERDA INFEIROR da dragoa
    if (x == dragoa_x - 1 && y == dragoa_y + 1)
    {
        // printf("A dragoa pegaria Luke pela diagonal infeiror esquerda!\n");
        allowed = 0;
    }

    // Verificamos se Luke ficará na DIAGONAL DIREITA INFEIROR da dragoa
    if (x == dragoa_x + 1 && y == dragoa_y + 1)
    {
        // printf("A dragoa pegaria Luke pela diagonal infeiror direita!\n");
        allowed = 0;
    }

    return allowed;
}

int main()
{
    int size;
    scanf("%d", &size);

    // Atribuímos os valores às casas do labirinto
    int labirinth[size][size];

    int dragoa_x, dragoa_y;

    for (int line = 0; line < size; line++)
    {
        for (int column = 0; column < size; column++)
        {
            int value;
            scanf("%d", &value);

            if (value == 2)
            {
                dragoa_x = line;
                dragoa_y = column;
            }

            labirinth[line][column] = value;
        }
    }

    // O cachorrinho sempre começa em [0, 0] e deve ir até [N - 1, N - 1]
    int x = 0, y = 0;

    while (x != size - 1 || y != size - 1)
    {
        // board_print(size, size, labirinth, x, y);

        if (x + 1 < size && labirinth[x + 1][y] == 1 && can_walk_here(x + 1, y, dragoa_x, dragoa_y))
        {
            // printf("Luke pode ir à direita!\n");
            x++;
        }
        else
        {
            if (y + 1 < size && labirinth[x][y + 1] == 1 && can_walk_here(x, y + 1, dragoa_x, dragoa_y))
            {
                // printf("Luke pode ir para baixo!\n");
                y++;
            }
            else
            {
                printf("Ekul tomou o nhac da dragoa :(\n");
                return 0;
            }
        }

        // printf("------\n");
    }

    printf("Ekul conseguiu ludibriar a dragoa!\n");

    return 0;
}