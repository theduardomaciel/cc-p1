#include <stdio.h>

/*
    Descrição:
    -O problema envolve achar a quantidade de divisores de um número que são divisíveis por 3.

    Formato de entrada:
    - Um inteiro N.

    Formato de saída:
    - Um inteiro R seguido de um final de linha, sendo R o número de divisores de N que são divisiveis por 3.
    Caso não tenha nenhum imprima "O numero nao possui divisores multiplos de 3!" sem as aspas e com um final de linha.
*/

/*
    Conceito de divisibilidade: A divide B, se existe um inteiro C, tal que: B = A . C
    Se A divide B:
        1. B é múltiplo de A
        2. A é divisor de B
*/

int quant_divisores_de_n_por_3(int numero, int divisor, int quant)
{
    if (divisor > 0)
    {
        if (numero % divisor == 0 && divisor % 3 == 0)
        {
            quant += 1;
        }

        return quant_divisores_de_n_por_3(numero, divisor - 1, quant);
    }
    else
    {
        return quant;
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);

    int quantidade = quant_divisores_de_n_por_3(numero, numero, 0);

    if (quantidade > 0)
    {
        printf("%d\n", quantidade);
    }
    else
    {
        printf("O numero nao possui divisores multiplos de 3!\n");
    }

    return 0;
}