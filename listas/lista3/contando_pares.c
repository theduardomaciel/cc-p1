#include <stdio.h>

/*
    - Descrição:
    Escreva uma função recursiva chamada ContaDigitosPares que receba como entrada um número e retorne a quantidade de dígitos pares que o compõem.Ex: 234 tem 3 dígitos, mas apenas 2 são pares

    - Formato de entrada
    Um número inteiro

    - Formato de saída
    Um número inteiro
 */

// ATENÇÃO!
// ++indice vai incrementar o valor de "indice" e retornar o valor já incrementado.
// indice++ vai retornar o valor de "indice" no momento em que é chamado e só depois vai incrementar esse valor.

int ContaDigitosPares(int numero, int count)
{
    if (numero >= 2)
    {
        if (numero % 2 == 0)
        {
            // Caso o número seja par, reduzimos uma casa decimal e adicionamos 1 ao n° de dígitos pares encontrados
            return ContaDigitosPares(numero / 10, ++count);
        }
        else
        {
            // Caso o número NÃO seja par, mas ainda seja maior ou igual a 2, simplesmente reduzimos uma casa decimal e buscamos por outro n° par
            return ContaDigitosPares(numero / 10, count);
        }
    }
    else
    {
        return count;
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);

    printf("%d\n", ContaDigitosPares(numero, 0));

    return 0;
}