#include <stdio.h>

/*
    ALGORITMO DE EUCLIDES:
    1. Escolha os dois numeros para tirar mdc(A,D)
    2. Divida A por D, se o resto não for zero divida D (divisor) pelo resto até achar o resto 0
    3. Quando achar uma divisão (entre A e D) com resto 0, o "D" (divisor) dessa divisão será o MDC de A e D originais.

    A = D * Q + R (dividendo = divisor * resultado inteiro + resto da divisão)
    - A: o dividendo (número a ser dividido)
    - D: o divisor
    - Q: o quociente (resultado) da divisão inteira de a por d
    - R: o mod ou resto da divisão inteira
*/

// mdc(2500, 13) = 1
int mdc(int dividendo, int divisor)
{
    // Quando o resto da divisão entre o dividendo (A) e o divisor (D) for igual a 0, podemos retornar o divisor (D) como o MDC
    if (dividendo % divisor == 0)
    {
        return divisor;
    }
    /* ou podemos utilizar a seguinte abordagem (abstração mais complexa):
    // Quando o PRÓXIMO resto ("divisor" atual) for igual a 0, podemos retornar o resto atual ("divisor" anterior) é o MDC.
    if (divisor == 0)
    {
        return dividendo;
    }
    */
    else
    {
        return mdc(divisor, dividendo % divisor);
    }
}

int print_mdc(int index)
{
    if (index > 0)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        printf("MDC(%d,%d) = %d\n", num1, num2, mdc(num1, num2));
        print_mdc(index - 1);
    }
}

int main()
{
    int index;
    scanf("%d", &index);

    print_mdc(index);

    return 0;
}