#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Considere que cada fruta pesa 1Kg.

/*
    char *strtok(char *str, const char *delim)
    Separa uma string em tokens (pedaços) de acordo com o delimitador.
*/

int main()
{
    int quant_dias;
    scanf("%d", &quant_dias);

    // Consumir a nova linha após o número de linhas
    getchar();

    double montante_total = 0;
    int total_frutas = 0;

    for (int i = 1; i <= quant_dias; i++)
    {
        double montante_dia;
        scanf("%lf\n", &montante_dia);

        // Consumir a nova linha após o preço
        getchar();

        /// printf("Montante do dia %d: R$ %.2lf\n", i, montante_dia);

        montante_total += montante_dia;

        char linha[1000];
        fgets(linha, sizeof(linha), stdin);

        // Contamos as frutas na linha
        int quant_frutas = 0;
        char *token = strtok(linha, " "); // Separamos a linha em tokens (pedaços) de acordo com o delimitador " " (espaço em branco)
        while (token != NULL)             // Enquanto houver tokens
        {
            // Adicionamos tanto na variável local quant_frutas (para o printf do dia), quanto na variável externa total_frutas (para o cálculo do peso médio)
            quant_frutas++;
            total_frutas++;
            token = strtok(NULL, " ");
        }

        printf("dia %d: %d kg\n", i, quant_frutas);
    }

    printf("%.2lf kg por dia\n", (double)total_frutas / quant_dias);
    printf("R$ %.2lf por dia\n", (double)montante_total / quant_dias);

    return 0;
}