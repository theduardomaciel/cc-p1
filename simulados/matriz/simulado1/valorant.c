#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct player
{
    int x;
    int y;
    int enemies_killed;
} player_default = {
    .x = 0,
    .y = 0,
    .enemies_killed = 0};

typedef struct player Player;

// direction 0: diagnonais
// direction 1: retilíneas

void map_print(int size, int map[size][size], Player player1, Player player2)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (x == player1.x && y == player1.y)
            {
                printf("L\t");
                continue;
            }
            else if (x == player2.x && y == player2.y)
            {
                printf("A\t");
                continue;
            }
            else
            {
                printf("%d\t", map[x][y]);
            }
        }
        printf("\n");
    }
}

int anderson_kills(int size, int map[size][size], Player anderson, Player luiza)
{
    int total_enemies = 0;

    // Verificamos se há inimigos na linha (para a direita)
    for (int i = anderson.x; i < size; i++)
    {
        // Verificação se achou Luiza na linha
        if (i == luiza.x && anderson.y == luiza.y)
        {
            // Se sim, simplesmente interrompemos o loop
            break;
        }
        // Verificamos se há inimigos na linha
        if (map[i][anderson.y] == 1)
        {
            // Se sim, incrementamos o contador de inimigos mortos e removemos o inimigo da map
            total_enemies++;
            map[i][anderson.y] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na coluna (para baixo)
    for (int i = anderson.x; i >= 0; i--)
    {
        // Verificamos se nos deparamos com Luiza na coluna
        if (i == luiza.x && anderson.y == luiza.y)
        {
            break;
        }
        if (map[i][anderson.y] == 1)
        {
            total_enemies++;
            map[i][anderson.y] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na coluna (para cima)
    for (int j = anderson.y; j >= 0; j--)
    {
        if (anderson.x == luiza.x && j == luiza.y)
        {
            break;
        }
        if (map[anderson.x][j] == 1)
        {
            total_enemies++;
            map[anderson.x][j] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na coluna linha (para a esquerda)
    for (int j = anderson.y; j < size; j++)
    {
        if (anderson.x == luiza.x && j == luiza.y)
        {
            break;
        }
        if (map[anderson.x][j] == 1)
        {
            total_enemies++;
            map[anderson.x][j] = 0;
            break;
        }
    }

    return total_enemies;
}

int luiza_kills(int size, int map[size][size], Player luiza, Player anderson)
{
    int total_enemies = 0;

    // Verificamos se há inimigos na diagonal (para baixo e para a direita)
    for (int i = luiza.x, j = luiza.y; i < size, j < size; i++, j++)
    {
        // Verificamos se encontramos Anderson na diagonal
        if (i == anderson.x && j == anderson.y)
        {
            break;
        }
        // Verificamos se encontramos um inimigo na diagonal
        if (map[i][j] == 1)
        {
            total_enemies++;
            map[i][j] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na diagonal (para cima e para a esquerda)
    for (int i = luiza.x, j = luiza.y; i >= 0, j < size; i--, j++)
    {
        if (i == anderson.x && j == anderson.y)
        {
            break;
        }
        if (map[i][j] == 1)
        {
            total_enemies++;
            map[i][j] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na diagonal (para baixo e para a esquerda)
    for (int i = luiza.x, j = luiza.y; i < size, j >= 0; i++, j--)
    {
        if (i == anderson.x && j == anderson.y)
        {
            break;
        }
        if (map[i][j] == 1)
        {
            total_enemies++;
            map[i][j] = 0;
            break;
        }
    }

    // Verificamos se há inimigos na diagonal (para cima e para a direita)
    for (int i = luiza.x, j = luiza.y; i >= 0, j >= 0; i--, j--)
    {
        if (i == anderson.x && j == anderson.y)
        {
            break;
        }
        if (map[i][j] == 1)
        {
            total_enemies++;
            map[i][j] = 0;
            break;
        }
    }

    return total_enemies;
}

int main()
{
    int size;
    scanf("%d", &size);

    int enemies_positions[size][size];

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            scanf("%d", &enemies_positions[x][y]);
        }
    }

    Player luiza = player_default;
    scanf("%d %d", &luiza.x, &luiza.y);

    Player anderson = player_default;
    scanf("%d %d", &anderson.x, &anderson.y);

    // Quando um inimigo morre, ele deixa de existir naquela posição
    // Caso o tiro acerte um inimigo, a bala irá parar nessa posição, ou seja, não irá atravessar
    // map_print(size, enemies_positions, luiza, anderson);

    // Pelas regras, Luíza sempre começa atirando

    // Luíza atira em todas as posições da diagonal
    luiza.enemies_killed = luiza_kills(size, enemies_positions, luiza, anderson);

    // Anderson atira em todas as posições da linha e coluna
    anderson.enemies_killed = anderson_kills(size, enemies_positions, anderson, luiza);

    printf("aziul matou %d\n", luiza.enemies_killed);
    printf("nosredna matou %d\n", anderson.enemies_killed);

    return 0;
}