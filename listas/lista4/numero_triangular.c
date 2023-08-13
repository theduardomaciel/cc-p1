#include <stdio.h>

/*
    - Descrição:
    Um número natural é triangular se ele é produto de três números naturais consecutivos.
    Por exemplo:
        120 é triangular, pois 4 * 5 * 6 = 120.
        O número 2730 é triangular, pois 13 * 14 * 15 = 2730.
    Dado um número natural (inteiro não-negativo) n, verifique se ele é triangular ou não.

    - Formato de entrada:
    Um número natural

    - Formato de saída:
    Caso o número seja triangular, apresentar quais números formam o número triangular e a mensagem Verdadeiro.
    Veja exemplo a seguir:
        13*14*15 = 2730
        Verdadeiro
    Caso o número não seja triangular, apresente a mensagem: Falso.
*/

int triangular(int numero, int atual)
{
    if (atual < numero)
    {
        if ((atual - 1) * atual * (atual + 1) == numero)
        {
            return atual;
        }
        else
        {
            return triangular(numero, atual + 1);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);

    int intermediario = triangular(numero, 2);
    if (intermediario != 0)
    {
        printf("%d * %d * %d = %d\n", intermediario - 1, intermediario, intermediario + 1, (intermediario - 1) * intermediario * (intermediario + 1));
        printf("Verdadeiro\n");
    }
    else
    {
        printf("Falso\n");
    }

    return 0;
}