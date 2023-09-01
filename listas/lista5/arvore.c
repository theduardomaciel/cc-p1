#include <stdio.h>
#include <stdlib.h>

// Robson se juntou a outros 20 funcionários para dividir o valor
// Ele encontrou a árvore prefeita e três tipos de enfeites
// Calcule e exiba o total gasto e o valor a ser pago por cada funcionário do setor.

/*
    -> Formato de entrada: Números reais no seguinte formato:
    A primeira linha contém o valor da arvore;
    Seguem duas linhas para cada tipo de enfeite, contendo respectivamente sua quantidade (número inteiro) e seu valor (número real).

    -> Formato de saída
    Dois valores reais, cada um com duas casas decimais
*/

void loop(int index, int quantidades[3], double precos[3])
{
    if (index > 0)
    {
        scanf("%d %lf", &quantidades[index], &precos[index]);
        return loop(index - 1, quantidades, precos);
    }
    else
    {
        return;
    }
}

int somatorio_array(int index, double array_precos[3], int array_quant[3])
{
    if (index == 0)
    {
        return 0;
    }
    else
    {
        return (array_precos[index] * array_quant[index]) + somatorio_array(index - 1, array_precos, array_quant);
    }
}

int main()
{
    double valor_arvore;
    scanf("%lf", &valor_arvore);

    int quantidades[3] = {0, 0, 0};
    double precos[3];

    loop(3, quantidades, precos);

    double total_gasto = valor_arvore + somatorio_array(3, precos, quantidades);
    printf("%.2lf\n", total_gasto);
    printf("%.2lf\n", total_gasto / 21);

    return 0;
}