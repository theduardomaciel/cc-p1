#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    A taxa de importação para eletrônicos é de 60%;
    O calculo do ICMS é dado pela formula: (Valor Final do produto x Aliquota)
    O valor final do produto é dado pela soma do (Valor do Produto + Frete + Impostos de Importação) / (1 - Aliquota)
    A empresa tem a cultura de não adicionar o frete no calculo para valores de US$ 2,500 em diante. Informe isso ao fim da nota.
*/

/*
    Entrada:
        -Cotação do Dolar
        -Aliquota(%) do ICMS
        -Valor do produto
        -Valor do frete
*/

/*
    Saída:
        -Taxa de conversão monetária (Cotação do dolar)
        -Valor do produto (em reais)
        -Valor do frete (em reais)
        -Valor total (Valor do frete + Valor do produto)
        -Valor de impostos de importação
        -Valor de icms
        -Total de Impostos (Importação + ICMS)
        -Total a pagar
        -Dizer se o total foi ou não isento do frete no calculo
*/

int main()
{
    double cotacao_dolar, aliquiota_icms, valor_produto_dolar, valor_frete_dolar; // o ICMS deve ser transformado em porcentagem
    scanf("%lf %lf %lf %lf", &cotacao_dolar, &aliquiota_icms, &valor_produto_dolar, &valor_frete_dolar);

    double valor_produto = valor_produto_dolar * cotacao_dolar;
    double valor_frete = valor_frete_dolar * cotacao_dolar;
    double valor_total = valor_produto + valor_frete;

    double valor_isento_de_frete = valor_produto_dolar >= 2500.00 ? valor_produto : valor_total;
    double impostos_de_importacao = valor_isento_de_frete * 0.6;

    double valor_final_produto = (valor_isento_de_frete + impostos_de_importacao) / (1 - (aliquiota_icms / 100.0));
    double icms = (valor_final_produto * (aliquiota_icms / 100.0));

    double total_impostos = impostos_de_importacao + icms;

    // printf("---------------------------\n");

    printf("%.2lf\n", cotacao_dolar);
    printf("%.2lf\n", valor_produto);
    printf("%.2lf\n", valor_frete);
    printf("%.2lf\n", valor_total);
    printf("%.2lf\n", impostos_de_importacao);
    printf("%.2lf\n", icms);
    printf("%.2lf\n", total_impostos);
    printf("%.2lf\n", valor_total + total_impostos);

    if (valor_produto_dolar >= 2500.00)
    {
        printf("Impostos calculados sem o frete\n");
    }
    else
    {
        printf("Impostos calculados com o frete\n");
    }

    return 0;
}

/*
void ordenar_bolha(double array[], int n, int j)
{
    if (j >= n)
        return;

    if (array[j] > array[j + 1])
    {
        double temp_a = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp_a;
    }

    return ordenar_bolha(array, n, j + 1);
}

void controlar_bolha(double array[], int n)
{
    if (n == 0)
        return;

    ordenar_bolha(array, n, 0);

    return controlar_bolha(array, n - 1);
}

void array_print(int index, double array[])
{
    if (index == 0)
        return;

    printf("%.2lf\n", array[index]);
    return array_print(index + 1, array);
}
*/