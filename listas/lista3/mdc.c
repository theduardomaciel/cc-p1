#include <stdio.h>

/*
    - Descrição:
    Dois números naturais sempre têm divisores comuns. Por exemplo: os divisores comuns de 12 e 18 são 1,2,3 e 6. Dentre eles, 6 é o maior. Então chamamos o 6 de máximo divisor comum de 12 e 18 e indicamos m.d.c.(12,18) = 6.

    Desenvolva uma função recursiva para calcular o m.d.c de dois inteiros.

    - Formato de entrada
    Dois inteiros positivos.

    - Formato de saída
    Um inteiro positivo
*/

// mdc(2500, 13) = 1
int mdc(int dividendo, int divisor)
{
    // Quando não houver resto entre a divisão do dividendo e do divisor, podemos retornar o divisor como o maior possível
    if (dividendo % divisor == 0)
    {
        return divisor;
    }
    else
    {
        return mdc(divisor, dividendo % divisor);
    }
}

int main()
{
    int inteiro1, inteiro2;
    scanf("%d %d", &inteiro1, &inteiro2);

    printf("%d\n", mdc(inteiro1, inteiro2));

    return 0;
}