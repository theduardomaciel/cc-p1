#include <stdio.h>

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

    int map[LINES_AMOUNT][columns_amount];

    for (int line = 0; line < 2; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            scanf("%d", &map[line][column]);
        }
    }

    int line = 0, column = 0, movements_needed = 0;

    while (line != 1 || column != columns_amount - 1)
    {
        map[line][column] = 1; // Marca a posição atual como visitada
        movements_needed++;

        if (column + 1 < columns_amount && map[line][column + 1] != 1)
        {
            // Se a coluna atual + 1 (da direita) for menor que a quantidade de colunas e a próxima posição for 0, podemos ir para a direita
            column++;
        }
        else if (line + 1 < LINES_AMOUNT && map[line + 1][column] != 1)
        {
            // Se a linha atual + 1 (de baixo) for menor que a quantidade de linhas e a próxima posição for 0, podemos ir para baixo
            line++;
        }
        else if (line - 1 >= 0 && map[line - 1][column] != 1)
        {
            // Se a linha atual - 1 (de cima) for maior que 0 e a próxima posição for 0, podemos ir para cima
            line--;
        }
        else
        {
            printf("existe um bloqueio!\n"); // Caso contrário, o caminho está bloqueado
            return 0;
        }
    }

    printf("precisamos de %d movimentos\n", movements_needed);

    return 0;
}