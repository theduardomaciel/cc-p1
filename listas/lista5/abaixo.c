#include <stdio.h>
#include <stdlib.h>

void pedir_input(int quant_veiculos_por_casa[], int *quant_casas)
{
    int input;
    scanf("%d", &input);

    if (input == 999)
    {
        return;
    }
    else
    {
        quant_veiculos_por_casa[*quant_casas] = input;
        *quant_casas += 1;
        // printf("Novo valor na array de quantidades de veículos por casa: %d\n", quant_veiculos_por_casa[sizeof *quant_veiculos_por_casa]);
        return pedir_input(quant_veiculos_por_casa, quant_casas);
    }
}

// casas que possuem mais de 2 veículos são multadas em R$ 12.89 por mês por cada veículo extra

void checar_multas(int index, int quant_casas, int quant_veiculos_por_casa[], int *quant_multas, double *valor_total_multas)
{
    if (index < quant_casas)
    {
        int quant_veiculos_casa_i = quant_veiculos_por_casa[index];
        // printf("Quantidade de veículos na casa i: %d\n", quant_veiculos_por_casa[index]);

        if (quant_veiculos_casa_i > 2)
        {
            *quant_multas += 1;
            *valor_total_multas += ((double)(quant_veiculos_casa_i - 2) * 12.89);
            // printf("Valor a ser somado: %.2lf\n", (quant_veiculos_casa_i - 2) * 12.89);
            //  printf("Nova quantidade de multas: %d\n", *quant_multas);
            //  printf("Nova valor total de multas: %.2lf\n", *valor_total_multas);
        }

        return checar_multas(index + 1, quant_casas, quant_veiculos_por_casa, quant_multas, valor_total_multas);
    }

    return;
}

int main()
{
    int quant_veiculos_por_casa[1000];
    int quant_casas = 0;

    pedir_input(quant_veiculos_por_casa, &quant_casas);

    int quant_multas = 0;
    double valor_total_multas = 0;

    // printf("Quantidade de inputs: %d\n", quant_casas);
    checar_multas(0, quant_casas, quant_veiculos_por_casa, &quant_multas, &valor_total_multas);

    printf("%.2lf\n", valor_total_multas);
    printf("%d\n", quant_multas);

    return 0;
}