#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Sua tarefa é escrever um programa que consiga simular a sequência de rodadas de golpes e, ao final da mesma, dizer quem foi o vencedor (se é que houve um).

/*
    Regras da batalha:
        - Cada rodada é representada por duas matrizes. A primeira representa o golpe de Luke e a segunda de Vader.
        - Cada matriz de golpe é composta de 3 linhas e 3 colunas.
        - A batalha consiste em no máximo 10 rodadas de golpes.

        - Para ser considerada válida, todos os valores da matriz de golpe precisam ser iguais a 0, exceto a diagonal principal ou secundária, nas quais todos os valores precisam ser iguais a 1.
        Qualquer matriz de golpe que não atenda as exigências é inválida.

        [...]
*/

/*
    ENTRADA
        A primeira linha da entrada é composta por dois números inteiros, representando a vida de Luke Skywalker e Darth Vader, respectivamente.

        Seguido de uma linha em branco.

        As próximas linhas contém matrizes separadas por uma linha em branco.
        É garantido que sempre haverá um número PAR de matrizes, afinal, CADA PAR REPRESENTA UMA RODADA
        (em cada par, a primeira matriz representa o golpe de Luke e a segundo o de Vader).
        Não é informado quantas rodadas haverão em uma batalha, desta forma, você precisa ler duas matrizes, até o fim da entrada.

        Cada matriz é composta por 3 linhas e cada uma dessas 3 linhas é composta por 3 inteiros separados por espaço. (ou seja, cada matriz é 3x3)
*/

/*
    SAÍDA:
        "Luke Skywalker venceu." - Caso Luke vença;
        "Darth Vader venceu." - Caso Darth Vader Vença;
        "Houve empate." - Caso haja empate.
*/

int verify_validity(int matrix[3][3])
{
    int is_valid = 1;
    int is_principal_valid = 1;
    int is_secondary_valid = 1;

    // " exceto a diagonal principal OU secundária, nas quais todos os valores precisam ser iguais a 1."

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            // Verificamos a validade da matriz de golpe
            if (line == column) // diagonal principal
            {
                if (matrix[line][column] != 1)
                {
                    is_principal_valid = 0;
                    // printf("A digonal principal [%d][%d] = %d é inválida.\n", line, column, matrix[line][column]);
                }
            }
            else if (line + column == 2) // diagonal secundária
            {
                if (matrix[line][column] != 1)
                {
                    is_secondary_valid = 0;
                    // printf("A digonal secundária [%d][%d] = %d é inválida.\n", line, column, matrix[line][column]);
                }
            }
            else
            {
                if (matrix[line][column] != 0)
                {
                    is_valid = 0;
                    // printf("A posição [%d][%d] é inválida.\n", line, column);
                }
            }
        }
    }

    if (!is_principal_valid && !is_secondary_valid)
    {
        is_valid = 0;
        // printf("A matriz é inválida.\n");
    }

    return is_valid;
}

int verify_diagonal_iguality(int matrix1[3][3], int matrix2[3][3])
{
    int are_equals = 1;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (line == column || line + column == 2)
            {
                if (matrix1[line][column] != matrix2[line][column])
                {
                    are_equals = 0;
                }
            }
        }
    }
}

int verify_iguality(int matrix1[3][3], int matrix2[3][3])
{
    int are_equals = 1;

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (matrix1[line][column] != matrix2[line][column])
            {
                are_equals = 0;
            }
        }
    }

    return are_equals;
}

int main()
{
    int life_luke, life_darth;
    scanf("%d %d", &life_luke, &life_darth);
    // printf("Luke: %d\nDarth: %d\n", life_luke, life_darth);

    fgetc(stdin); // Pulamos a linha em branco

    while (getchar() != EOF)
    {
        int luck_atack[3][3];

        // Lemos a matriz de golpe de Luck
        for (int line = 0; line < 3; line++)
        {
            for (int column = 0; column < 3; column++)
            {
                scanf("%d", &luck_atack[line][column]);
            }
        }

        /* for (int line = 0; line < 3; line++)
        {
            for (int column = 0; column < 3; column++)
            {
                printf("%d\t", luck_atack[line][column]);
            }
            printf("\n");
        } */

        int is_luck_valid = verify_validity(luck_atack); // Verificamos a validade da matriz de golpe de Luck

        fgetc(stdin); // Pulamos a linha em branco
        // printf("------------------------\n");

        int darth_atack[3][3];

        // Lemos a matriz de golpe de Darth
        for (int line = 0; line < 3; line++)
        {
            for (int column = 0; column < 3; column++)
            {
                scanf("%d", &darth_atack[line][column]);
            }
        }

        /* for (int line = 0; line < 3; line++)
        {
            for (int column = 0; column < 3; column++)
            {
                printf("%d\t", darth_atack[line][column]);
            }
            printf("\n");
        } */

        int is_darth_valid = verify_validity(darth_atack); // Verificamos a validade da matriz de golpe de Darth

        /*
            - Uma matriz de golpe inválida significa que seu autor não conseguiu atacar e pode receber dano se a matriz de golpe do adversário for válida.
            - Em rodadas que ambas as matrizes de golpes são válidas e com as diagonais iguais, ambos os guerreiros recebem os ataques.
            - Se as duas matrizes forem válidas e diferentes, nenhum dos guerreiros toma dano na rodada.
        */

        // Quando um combatente é atingido por um golpe, o mesmo perde 15 pontos de vida.

        if (!is_luck_valid && is_darth_valid)
        {
            life_luke -= 15;
        }
        else if (is_luck_valid && !is_darth_valid)
        {
            life_darth -= 15;
        }
        else if (is_luck_valid && is_darth_valid && verify_diagonal_iguality(luck_atack, darth_atack))
        {
            if (verify_iguality(luck_atack, darth_atack))
            {
                life_luke -= 15;
                life_darth -= 15;
            }
        }
    }

    if (life_luke > life_darth)
    {
        printf("Luke Skywalker venceu.\n");
    }
    else if (life_darth > life_luke)
    {
        printf("Darth Vader venceu.\n");
    }
    else
    {
        printf("Houve empate.\n");
    }

    return 0;
}