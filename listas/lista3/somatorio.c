#include <stdio.h>
#include <math.h>

// soma(n) = somatório de 2^i partindo de i = 1 até n

/*
    Reescrevendo em forma de definição recursiva, utilizando a notação de função:
    soma(n) =
    {
        0,                  se n = 0,
        2^n + soma(n - 1),  se n > 0.
    }
 */

/* ATENÇÃO! É necessário adicionar o parâmetro "-lm" ao fim do comando do gcc para que a biblioteca de matemática seja inclusa! */

int soma(int numero)
{
    // Verificamos se o número atende ao caso base
    if (numero == 0)
    {
        return 0;
    }

    return pow(2, numero) + soma(numero - 1); // Passo recursivo
}

int main()
{
    int numero;

    scanf("%d", &numero);
    printf("%d\n", soma(numero));

    return 0;
}