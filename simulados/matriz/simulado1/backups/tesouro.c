#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LINES_AMOUNT 2

void map_print(int columns_amount, int map[2][columns_amount], int player_position[2])
{
    for (int line = 0; line < 2; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            if (line == player_position[0] && column == player_position[1])
            {
                printf("X\t");
                continue;
            }
            else
            {
                printf("%d\t", map[line][column]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int columns_amount;
    scanf("%d", &columns_amount);

    // [0] = linha, [1] = coluna
    int map[LINES_AMOUNT][columns_amount];

    // [0] = linha, [1] = coluna
    int player_position[2] = {0, 0};

    // Obtendo os valores da matriz
    for (int line = 0; line < 2; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            scanf("%d", &map[line][column]);
        }
    }

    int movements_needed = 0;

    for (int i = 0; i < LINES_AMOUNT * columns_amount; i++)
    {
        for (int direction = 1; direction <= 4; direction++)
        {
            // printf("------\n");
            //  printf("i: %d | [%d, %d] - inicio\n", direction, player_position[0], player_position[1]);
            // map_print(columns_amount, map, player_position);

            if (direction == 1 && map[player_position[0]][player_position[1] + 1] == 0 && player_position[1] < columns_amount) // Verificamos se o jogador pode ir para a direita
            {
                // printf("[%d, %d + 1] - direita\n", player_position[0], player_position[1]);
                player_position[1] += 1;
                movements_needed += 1;
                break;
            }
            else if (direction == 2 && map[player_position[0] + 1][player_position[1]] == 0 && player_position[0] < LINES_AMOUNT) // Verificamos se o jogador pode ir para baixo
            {
                // printf("[%d + 1, %d] - baixo\n", player_position[0], player_position[1]);
                player_position[0] += 1;
                movements_needed += 1;
                break;
            }
            else if (direction == 3 && map[player_position[0] - 1][player_position[1]] == 0 && player_position[0] > 0) // Verificamos se o jogador pode ir para cima
            {
                // printf("[%d - 1, %d] - cima\n", player_position[0], player_position[1]);
                player_position[0] -= 1;
                movements_needed += 1;
                break;
            }
            else if (direction == 4)
            {
                // Caso não consiga ir para nenhuma direção, o caminho está bloqueado
                movements_needed = -1;
                break;
            }
            else
            {
                // printf("Não foi possível ir para a direção %d\n", direction);
                continue;
            }
        }

        // Caso o jogador esteja na ultima linha e coluna, ele conseguiu chegar ao tesouro
        // ou não haja mais movimentos possíveis, o caminho está bloqueado
        if (player_position[0] == 1 && player_position[1] == columns_amount - 1 || movements_needed == -1)
        {
            break;
        }
    }

    if (movements_needed == -1)
    {
        printf("existe um bloqueio!\n");
    }
    else
    {
        printf("precisamos de %d movimentos\n", movements_needed);
    }

    return 0;
}