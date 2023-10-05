#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct player
{
    int line;
    int column;
    int enemies_killed;
} player_default = {
    .line = 0,
    .column = 0,
    .enemies_killed = 0};

typedef struct player Player;

// direction 0: diagnonais
// direction 1: retilíneas

void map_print(int size, int map[size][size], Player player1, Player player2)
{
    for (int line = 0; line < size; line++)
    {
        for (int column = 0; column < size; column++)
        {
            if (line == player1.line && column == player1.column)
            {
                printf("L\t");
                continue;
            }
            else if (line == player2.line && column == player2.column)
            {
                printf("A\t");
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

int anderson_kills(int size, int map[size][size], int line, int column)
{
    int total_enemies = 0;

    // Atira para cima
    int curr_line = line - 1;
    while (curr_line >= 0 && map[curr_line][column] == 0) // percorremos a coluna para CIMA até encontrarmos um inimigo ou o limite da matriz
    {
        curr_line--;
    }
    if (curr_line >= 0 && map[curr_line][column] == 1) // se encontrarmos um inimigo, ele morre
    {
        printf("Anderson matou um inimigo para cima\n");
        map[curr_line][column] = 0;
        total_enemies++;
    }

    // Atira para baixo
    curr_line = line + 1;
    while (curr_line < size && map[curr_line][column] == 0) // percorremos a coluna para BAIXO até encontrarmos um inimigo ou o limite da matriz
    {
        curr_line++;
    }
    if (curr_line < size && map[curr_line][column] == 1) // se encontrarmos um inimigo, ele morre
    {
        printf("Anderson matou um inimigo para baixo\n");
        map[curr_line][column] = 0;
        total_enemies++;
    }

    // Atira para a direita
    int curr_column = column + 1;
    while (curr_column < size && map[line][curr_column] == 0) // percorremos a linha para DIREITA até encontrarmos um inimigo ou o limite da matriz
    {
        curr_column++;
    }
    if (curr_column < size && map[line][curr_column] == 1) // se encontrarmos um inimigo, ele morre
    {
        printf("Anderson matou um inimigo para direita\n");
        map[line][curr_column] = 0;
        total_enemies++;
    }

    // Atira para a esquerda
    curr_column = column - 1;
    while (curr_column >= 0 && map[line][curr_column] == 0) // percorremos a linha para ESQUERDA até encontrarmos um inimigo ou o limite da matriz
    {
        curr_column--;
    }
    if (curr_column >= 0 && map[line][curr_column] == 1) // se encontrarmos um inimigo, ele morre
    {
        printf("Anderson matou um inimigo para esquerda\n");
        map[line][curr_column] = 0;
        total_enemies++;
    }

    return total_enemies;
}

int luiza_kills(int size, int map[size][size], int line, int column)
{
    int total_enemies = 0;

    // Atira na diagonal superior direita
    int curr_line = line - 1;
    int curr_column = column + 1;
    while (curr_line >= 0 && curr_column < size && map[curr_line][curr_column] == 0) // percorremos a diagonal superior direita até encontrarmos um inimigo ou o limite da matriz
    {
        curr_line--;
        curr_column++;
    }
    if (curr_line >= 0 && curr_column < size && map[curr_line][curr_column] == 1) // se encontrarmos um inimigo, ele morre
    {
        map[curr_line][curr_column] = 0;
        total_enemies++;
    }

    // Atira na diagonal superior esquerda
    curr_line = line - 1;
    curr_column = column - 1;
    while (curr_line >= 0 && curr_column >= 0 && map[curr_line][curr_column] == 0)
    {
        curr_line--;
        curr_column--;
    }
    if (curr_line >= 0 && curr_column >= 0 && map[curr_line][curr_column] == 1)
    {
        map[curr_line][curr_column] = 0;
        total_enemies++;
    }

    // Atira na diagonal inferior direita
    curr_line = line + 1;
    curr_column = column + 1;
    while (curr_line < size && curr_column < size && map[curr_line][curr_column] == 0)
    {
        curr_line++;
        curr_column++;
    }
    if (curr_line < size && curr_column < size && map[curr_line][curr_column] == 1)
    {
        map[curr_line][curr_column] = 0;
        total_enemies++;
    }

    // Atira na diagonal inferior esquerda
    curr_line = line + 1;
    curr_column = column - 1;
    while (curr_line < size && curr_column >= 0 && map[curr_line][curr_column] == 0)
    {
        curr_line++;
        curr_column--;
    }
    if (curr_line < size && curr_column >= 0 && map[curr_line][curr_column] == 1)
    {
        map[curr_line][curr_column] = 0;
        total_enemies++;
    }

    return total_enemies;
}

int main()
{
    int size;
    scanf("%d", &size);

    int enemies_positions[size][size];

    for (int line = 0; line < size; line++)
    {
        for (int column = 0; column < size; column++)
        {
            scanf("%d", &enemies_positions[line][column]);
        }
    }

    Player luiza = player_default;
    scanf("%d %d", &luiza.line, &luiza.column);

    Player anderson = player_default;
    scanf("%d %d", &anderson.line, &anderson.column);

    // Quando um inimigo morre, ele deixa de existir naquela posição
    // Caso o tiro acerte um inimigo, a bala irá parar nessa posição, ou seja, não irá atravessar
    map_print(size, enemies_positions, luiza, anderson);

    // Pelas regras, Luíza sempre começa atirando

    // Luíza atira em todas as posições da diagonal
    luiza.enemies_killed = luiza_kills(size, enemies_positions, luiza.line, luiza.column);

    // Anderson atira em todas as posições da linha e coluna
    anderson.enemies_killed = anderson_kills(size, enemies_positions, anderson.line, anderson.column);

    printf("aziul matou %d\n", luiza.enemies_killed);
    printf("nosredna matou %d\n", anderson.enemies_killed);

    return 0;
}