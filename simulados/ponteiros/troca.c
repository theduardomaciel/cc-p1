#include <stdio.h>

void troca(int *a, int *b)
{
    int a_original = *a;
    int b_original = *b;

    *a = b_original;
    *b = a_original;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("a: %d b: %d\n", a, b);

    troca(&a, &b);

    printf("a: %d b: %d\n", a, b);

    return 0;
}