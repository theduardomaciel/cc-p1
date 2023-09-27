#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Para lidar com elas, você construiu um vetor bidimensional de 0s e 1s, onde "0" representa parede, e "1" representa o caminho por onde você pode se movimentar.

/*
    Os comandos de direção serão representados por:
    Direita: D
    Esquerda: E
    Cima: C
    Baixo: B
*/

int main()
{
    int lines_amount, columns_amount;
    scanf("%d %d", &lines_amount, &columns_amount);

    int map[lines_amount][columns_amount];
    for (int line = 0; line < lines_amount; line++)
    {
        for (int column = 0; column < columns_amount; column++)
        {
            scanf("%d", &map[line][column]);
        }
    }

    int commands_amount;
    scanf("%d", &commands_amount);

    char commands[commands_amount];
    for (int i = 0; i < commands_amount; i++)
    {
        scanf(" %c", &commands[i]);
    }

    int initial_line, initial_column;
    scanf("%d %d", &initial_line, &initial_column);

    int current_line = initial_line;
    int current_column = initial_column;

    for (int i = 0; i < commands_amount; i++)
    {
        char command = commands[i];

        // Caso encontremos uma parede (ou tenhamos chegado na borda do mapa), não movimentamos o personagem
        // De resto, podemos movimentar o personagem
        switch (command)
        {
        case 'D':
            if (map[current_line][current_column + 1] == 0 || current_column + 1 >= columns_amount)
            {
                continue;
            }
            else
            {
                current_column++;
            }
            break;
        case 'E':
            if (map[current_line][current_column - 1] == 0 || current_column - 1 < 0)
            {
                continue;
            }
            else
            {
                current_column--;
            }
            break;
        case 'C':
            if (map[current_line - 1][current_column] == 0 || current_line - 1 < 0)
            {
                continue;
            }
            else
            {
                current_line--;
            }
            break;
        case 'B':
            if (map[current_line + 1][current_column] == 0 || current_line + 1 >= lines_amount)
            {
                continue;
            }
            else
            {
                current_line++;
            }
            break;
        default:
            break;
        }
    }

    printf("(%d,%d)\n", current_line, current_column);

    return 0;
}