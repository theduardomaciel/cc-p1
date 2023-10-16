#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tal peça só pode mover-se para cima (C), baixo (B), esquerda (E), e direita (D).
// Cada casa do tabuleiro tem um valor inteiro. A peça só pode mover-se para uma casa adjacente se essa casa tiver valor 0.
// Senão, a casa para onde a peça tentou se mover terá seu valor decrementado por 1.

// A peça não consegue ir para fora dos limites do tabuleiro.
// OBS: Pode ser que a peça não necessite usar todos os movimentos dados para chegar na coordenada dada.

int main()
{
    int lines_amount, columns_amount;
    scanf("%d %d", &lines_amount, &columns_amount);

    int board[lines_amount][columns_amount];

    for (int line = 0; line < lines_amount; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            scanf("%d", &board[line][column]);
        }
    }

    int attempts;
    scanf("%d", &attempts);
    // printf("tentativas: %d\n", attempts);

    char movements[attempts];
    for (int i = 0; i < attempts; i++)
    {
        scanf(" %c", &movements[i]);
        // printf("%c - caractere\n", movements[i]);
    }

    int line = 0, column = 0;

    int goal_x, goal_y;
    scanf("%d %d", &goal_x, &goal_y);

    // printf("goal_x: %d e goal_y: %d\n", goal_x, goal_y);

    int won = 0;

    for (int i = 0; i < attempts + 1; i++)
    {
        // printf("%d\n", i);

        if (line == goal_x && column == goal_y)
        {
            won = 1;
            printf("Cheguei com %d movimentos\n", i);
            break;
        }

        switch (movements[i])
        {
        case 'C':
            if (column > 0)
            {
                if (board[line - 1][column] > 0)
                {
                    board[line - 1][column] -= 1;
                }
                else
                {
                    line--;
                }
            }
            break;
        case 'B':
            if (line < lines_amount - 1)
            {
                if (board[line + 1][column] > 0)
                {
                    board[line + 1][column] -= 1;
                }
                else
                {
                    line++;
                }
            }
            break;
        case 'E':
            if (column > 0)
            {
                if (board[line][column - 1] > 0)
                {
                    board[line][column - 1]--;
                }
                else
                {
                    column--;
                }
            }
            break;
        case 'D':
            if (column < columns_amount - 1)
            {
                if (board[line][column + 1] > 0)
                {
                    board[line][column + 1] -= 1;
                }
                else
                {
                    column++;
                }
            }
            break;
        default:
            break;
        }
    }

    if (!won)
    {
        printf("Não cheguei\n");
    }

    return 0;
}

/*
Dica aleatória sobre a questão do sapo:

Pra índice ficando negativo: (i-x)%n+n
Pra índice ultrapassando o tamanho: (i+x)%n

i = índice atual
x = valor que vai se locomover
n = tamanho da array
*/