#include <stdio.h>

// Cada cápsula prepara o equivalente a duas xícaras.
// As cápsulas são vendidas em caixas pequenas (10 unidades) ou grandes (16 unidades)

/*
    - Formato de entrada
    A quantidade (um inteiro) e o tamanho das caixas doadas (um char (P ou p para caixas pequenas, G ou g para caixas grandes) por cada um dos sete professores que compartilham a cafeteira

    Dica: os professores farão a doação de caixas, não de cápsulas avulsas

    - Formato de saída
    Dois valores inteiros: a quantidade total de cápsulas de café doadas, e quantas xícaras cada professor poderá beber.
*/

int quantidade_de_capsulas(int quant_professores, int quant_atual)
{
    int Caixa_Pequena = 10;
    int Caixa_Grande = 16;

    if (quant_professores > 0)
    {
        int quant_caixas;
        char tamanho_caixas;
        scanf("%d %c", &quant_caixas, &tamanho_caixas);

        if (tamanho_caixas == 'P' || tamanho_caixas == 'p')
        {
            return quantidade_de_capsulas(quant_professores - 1, quant_atual + (quant_caixas * Caixa_Pequena));
        }
        else if (tamanho_caixas == 'G' || tamanho_caixas == 'g')
        {
            return quantidade_de_capsulas(quant_professores - 1, quant_atual + (quant_caixas * Caixa_Grande));
        }
    }
    else
    {
        return quant_atual;
    }
}

int main()
{
    int Quantidade_De_Professores = 7;
    int capsulas = quantidade_de_capsulas(Quantidade_De_Professores, 0);

    // Como cada cápsula prepara o equivalente a duas xícaras, multiplicamos o valor da quantidade de xícaras por 2
    printf("%d\n%d\n", capsulas, (capsulas * 2) / Quantidade_De_Professores);

    return 0;
}