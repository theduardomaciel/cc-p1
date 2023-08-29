#include <stdio.h>

// calcular a média dos valores de A e B (média = (A+B) / 2) e armazenar o resultado na variável que contém o menor valor.
// armazenar o resto da divisão na variável na variável de maior valor

void calcular_media(int *A, int *B)
{
    int media = (*A + *B) / 2;
    int resto = (*A + *B) % 2;

    if (*A < *B)
    {
        *A = media;
    }
    else
    {
        *B = media;
    }

    if (*A > *B)
    {
        *A = resto;
    }
    else
    {
        *B = resto;
    }
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    calcular_media(&A, &B);
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    return 0;
}