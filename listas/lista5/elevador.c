#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// "Eles sabem que as pessoas são educadas e sempre deixam todos os passageiros que irão sair em um andar saírem antes de outros passageiros entrarem no elevador"

void verificar_leitura(int quant_leituras, int capacidade_atual, int capacidade_maxima, bool *houve_violacao)
{
    if (quant_leituras > 0)
    {
        int quant_entrada = 0, quant_saida = 0;
        scanf("%d %d", &quant_saida, &quant_entrada);

        capacidade_atual += quant_entrada;
        capacidade_atual -= quant_saida;

        if (capacidade_atual > capacidade_maxima)
        {
            *houve_violacao = true;
        }

        return verificar_leitura(quant_leituras - 1, capacidade_atual, capacidade_maxima, houve_violacao);
    }

    return;
}

int main()
{
    int quant_leituras, capacidade_maxima;
    scanf("%d %d", &quant_leituras, &capacidade_maxima);

    bool houve_violacao = false;
    verificar_leitura(quant_leituras, 0, capacidade_maxima, &houve_violacao);

    if (houve_violacao)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}