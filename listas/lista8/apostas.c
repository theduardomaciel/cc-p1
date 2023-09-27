#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Indicar quantos foram os apostadores que acertaram os 6 números
// São permitidas apenas apostas contendo no máximo 10 números.

/*
    ENTRADA:
    Na primeira linha é informado um número inteiro N que representa o número de apostas.
    Nas N linhas seguintes, são fornecidas as apostas.
    Cada aposta é formada por 6 a 10 números inteiros separados por vírgulas.
    Na última linha é fornecido o resultado oficial, também formado por 6 números inteiros, mas neste caso separados por espaços.
    Por simplicidade, assuma que os números estão ordenados de forma crescente.
*/

/*
    SAÍDA:
    A saída consiste da string “Total de ganhadores:” seguida por um espaço em branco e do número de apostas que contêm os números do resultado, ou seja, o número de ganhadores.
*/

#define BET_SIZE 6

int main()
{
    int bets_amount;
    scanf("%d", &bets_amount);
    // printf("Quantidade de apostas: %d\n", bets_amount);

    // Consumir a nova linha após o número de linhas
    getchar();

    int bets[bets_amount][10];
    int bets_sizes[bets_amount];
    memset(bets_sizes, 0, sizeof(bets_sizes));

    for (int current_bet = 0; current_bet < bets_amount; current_bet++)
    {
        char bet_numbers[1000];
        fgets(bet_numbers, sizeof(bet_numbers), stdin);

        char *token = strtok(bet_numbers, ","); // Separamos a linha em tokens (números da aposta) de acordo com o delimitador "," (vírgula)
        while (token != NULL)                   // Enquanto houver tokens
        {
            // linha = aposta atual | coluna = número da aposta
            // printf("Número em [aposta %d][número de index %d] = %d\n", current_bet, bets_sizes[current_bet], atoi(token));

            bets[current_bet][bets_sizes[current_bet]] = atoi(token); // Convertemos o token para inteiro e adicionamos na matriz
            bets_sizes[current_bet]++;                                // Incrementamos o tamanho da aposta
            token = strtok(NULL, ",");                                // Continuamos a separar a linha em tokens, a partir do último ponto de parada
        }
    }

    /* for (int linha = 0; linha < bets_amount; linha++)
    {
        for (int coluna = 0; coluna < 10; coluna++)
        {
            printf("%d\t", bets[linha][coluna]);
            if (coluna == bets_sizes[linha] - 1)
            {
                break;
            }
        }
        printf("\n");
    } */

    int final_result[BET_SIZE] = {0};
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &final_result[i]);
    }

    int winners_amount = 0;

    for (int current_bet = 0; current_bet < bets_amount; current_bet++)
    {
        // printf("Aposta %d possui tamanho: %d\n", current_bet, bets_sizes[current_bet]);
        int amount_of_correct_numbers = 0;

        // Loopamos por cada número da aposta
        for (int index = 0; index < bets_sizes[current_bet]; index++)
        {
            // Loopamos por cada número do resultado
            for (int result_index = 0; result_index < 6; result_index++)
            {
                // Se o número da aposta for igual ao número do resultado, incrementamos a quantidade de números corretos
                if (bets[current_bet][index] == final_result[result_index])
                {
                    // printf("A aposta %d acertou o número %d (total: %d)\n", current_bet, bets[current_bet][index], amount_of_correct_numbers);
                    amount_of_correct_numbers++;
                }
            }
        }

        // Se a quantidade de números corretos for igual a 6, o apostador ganhou
        if (amount_of_correct_numbers == BET_SIZE)
        {
            winners_amount++;
        }
    }

    printf("Total de ganhadores: %d\n", winners_amount);

    return 0;
}