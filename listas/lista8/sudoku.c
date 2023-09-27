#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// "O jogo de Sudoku espalhou-se rapidamente por todo o mundo, tornando-se hoje O PASSATEMPO MAIS POPULAR DE >>> TODO <<< O PLANETA".
// Sua tarefa neste problema é escrever um programa que verifica se uma matriz preenchida é ou não uma solução para o problema.

int main()
{
    int instances_amount = 0;
    scanf("%d", &instances_amount);

    for (int instance = 0; instance < instances_amount; instance++)
    {
        // Lemos cada uma das "instâncias" do problema
        int instance_matrix[9][9];
        for (int line = 0; line < 9; line++)
        {
            for (int column = 0; column < 9; column++)
            {
                scanf("%d", &instance_matrix[line][column]);
            }
        }

        // Verificamos se a instância é válida
        int is_valid = 1;

        // Verificamos se todas as colunas são válidas
        for (int column = 0; column < 9; column++)
        {
            int column_values[9] = {0}; // armazenamos os valores já vistos em cada coluna
            for (int current_column_element = 0; current_column_element < 9; current_column_element++)
            {
                int value = instance_matrix[current_column_element][column];

                // Caso o valor já tenha sido visto, a instância é inválida (visto que não pode haver valores repetidos em uma coluna)
                if (column_values[value - 1] == 1)
                {
                    is_valid = 0;
                    break;
                }
                else
                {
                    column_values[value - 1] = 1;
                }
            }
            if (!is_valid)
            {
                break;
            }
        }

        if (!is_valid)
        {
            printf("Instancia %d\nNAO\n\n", instance + 1);
            continue;
        }

        // Verificamos se todas as linhas são válidas
        for (int line = 0; line < 9; line++)
        {
            int line_values[9] = {0}; // armazenamos os valores já vistos em cada linha
            for (int current_line_element = 0; current_line_element < 9; current_line_element++)
            {
                int value = instance_matrix[line][current_line_element];

                // Caso o valor já tenha sido visto, a instância é inválida (visto que não pode haver valores repetidos em uma linha)
                if (line_values[value - 1] == 1)
                {
                    is_valid = 0;
                    break;
                }
                else
                {
                    line_values[value - 1] = 1;
                }
            }
            if (!is_valid)
            {
                break;
            }
        }

        if (!is_valid)
        {
            printf("Instancia %d\nNAO\n\n", instance + 1);
            continue;
        }

        // Verificamos se todos os quadrados são válidos
        for (int square = 0; square < 9; square++)
        {
            int square_values[9] = {0};                                                                // armazenamos os valores já vistos em cada quadrado
            for (int current_square_element = 0; current_square_element < 9; current_square_element++) // loopamos pelos 9 elementos de cada quadrado
            {
                int line = (square / 3) * 3 + (current_square_element / 3);   // calculamos a linha do elemento atual
                int column = (square % 3) * 3 + (current_square_element % 3); // calculamos a coluna do elemento atual

                int value = instance_matrix[line][column]; // pegamos o valor do elemento atual

                // Caso o valor já tenha sido visto, a instância é inválida (visto que não pode haver valores repetidos em um quadrado)
                if (square_values[value - 1] == 1)
                {
                    is_valid = 0;
                    break;
                }
                else
                {
                    square_values[value - 1] = 1;
                }
            }
            if (!is_valid)
            {
                break;
            }
        }

        if (!is_valid)
        {
            printf("Instancia %d\nNAO\n", instance + 1);
        }
        else
        {
            printf("Instancia %d\nSIM\n", instance + 1);
        }

        if (instance != instances_amount - 1)
        {
            printf("\n");
        }
    }

    return 0;
}