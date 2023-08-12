#include <stdio.h>

// fatorial:
// n! = n * (n - 1)!
/*
    0! = 1 (caso base)
    1! = 1 * 0!
    2! = 2 * 1!

    Reescrevendo de forma recursiva, numa notação de função:
    fat(n) =
    {
        1,                  se n = 0,
        n * fat(n - 1),     se n > 0.
    }
 */

int fatorial(int numero)
{
    // Checamos o caso base
    if (numero == 0)
    {
        return 1;
    }

    // Caso contrário, realizamos a recursão
    return numero * fatorial(numero - 1);
}

int main()
{
    int numero;
    scanf("%d", &numero);

    printf("%d\n", fatorial(numero));

    return 0;
}