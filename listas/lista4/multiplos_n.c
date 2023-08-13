#include <stdio.h>

int multiplo_de_n(int a, int b, int n, int quantidade)
{
    if (a <= b) // caso base: a = b
    {
        if (a % n == 0)
        {
            printf("%d\n", a);
            quantidade += 1;
        }

        multiplo_de_n(a + 1, b, n, quantidade);
    }
    else
    {
        return quantidade;
    }
}

int main()
{
    int multiplo, inicio, fim;
    scanf("%d %d %d", &multiplo, &inicio, &fim);

    int quantidade = multiplo_de_n(inicio, fim, multiplo, 0);

    if (inicio > fim || fim < inicio || quantidade == 0)
    {
        printf("INEXISTENTE\n");
    }

    return 0;
}