#include <stdio.h>

/*
    -> Descrição
    Não tem dia ruim pra Demóclistenes. Ele programa todo dia e estabeleceu uma meta de fazer pelo menos:
        - 5 programas e
        - 100 linhas de código por dia.

    Escreva um programa que receba como entrada a quantidade de programas e a quantidade de linhas de código feitas por ele em cada um dos sete dias da semana, e exiba em quantos dias ele cumpriu as duas metas e o dia em que ele mais produziu linhas de código.

    ATENÇÃO:
    - Assuma que o primeiro dia da semana é DOMINGO.
    - Se a produção de programas for a mesma todos os dias, será exibido o último dia da semana.

    -> Formato de entrada
        Sequência de 14 valores inteiros e positivos não-nulos
            1. a quantidade de programas
            2. quantidade de linhas de código feitas por ele
        Isso em cada um dos sete dias da semana.

    -> Formato de saída
        1. Quantidade de dias que atingiu meta de programas
        2. Quantidade de dias que atingiu meta de linhas de código
        3. Dia que mais produziu linhas de código
*/

void verificar(int quant_dias, int dias_meta_programas, int dias_meta_linhas, int quant_linhas_anterior, int melhor_dia)
{
    if (quant_dias > 0)
    {
        int quant_programas, quant_linhas;
        scanf("%d %d", &quant_programas, &quant_linhas);

        if (quant_programas >= 5)
        {
            dias_meta_programas += 1;
        }

        if (quant_linhas >= 100)
        {
            dias_meta_linhas += 1;
        }

        // printf("QUANTIDADE DE LINHAS ANTERIOR: %d\n", quant_linhas_anterior);

        if (quant_linhas > quant_linhas_anterior)
        {
            // printf("A quantidade de linhas (%d) do dia atual (%d) ultrapassou a maior quantidade de linhas anterior (%d)\n", quant_linhas, 7 - quant_dias + 1, quant_linhas_anterior);

            melhor_dia = 7 - quant_dias + 1;
        }

        int nova_quant_linhas = quant_linhas > quant_linhas_anterior ? quant_linhas : quant_linhas_anterior;

        return verificar(quant_dias - 1, dias_meta_programas, dias_meta_linhas, nova_quant_linhas, melhor_dia);
    }
    else
    {
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", dias_meta_programas);
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", dias_meta_linhas);

        switch (melhor_dia)
        {
        case 1:
            printf("DIA QUE MAIS PRODUZIU: DOMINGO\n");
            break;
        case 2:
            printf("DIA QUE MAIS PRODUZIU: SEGUNDA\n");
            break;
        case 3:
            printf("DIA QUE MAIS PRODUZIU: TERCA\n");
            break;
        case 4:
            printf("DIA QUE MAIS PRODUZIU: QUARTA\n");
            break;
        case 5:
            printf("DIA QUE MAIS PRODUZIU: QUINTA\n");
            break;
        case 6:
            printf("DIA QUE MAIS PRODUZIU: SEXTA\n");
            break;
        case 7:
            printf("DIA QUE MAIS PRODUZIU: SABADO\n");
            break;
        default:
            // "Se a produção de programas for a mesma todos os dias, será exibido o último dia da semana."
            printf("DIA QUE MAIS PRODUZIU: SABADO\n");
            break;
        }
    }
}

int main()
{
    verificar(7, 0, 0, 0, 0);
    return 0;
}