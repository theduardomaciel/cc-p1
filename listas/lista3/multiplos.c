#include <stdio.h>

void multiplo_de_n(int a, int b, int n)
{
    if (a <= b) // caso base: a = b
    {
        if (a % n == 0)
        {
            printf("- %d\n", a);
        }

        multiplo_de_n(a + 1, b, n);
    }
}

int main()
{
    printf("MÚLTIPLOS EM UM INTERVALO:\n");
    int inicio, fim, multiplo;

    printf("-> Insira um inteiro para o INÍCIO do intervalo: ");
    scanf("%d", &inicio);

    printf("-> Insira um inteiro para o FIM do intervalo: ");
    scanf("%d", &fim);

    printf("-> Insira um inteiro para verificar a multiplicidade dos números dentro do intervalo fornecido anteriormento: ");
    scanf("%d", &multiplo);

    // scanf("%d %d %d", &inicio, &fim, &multiplo);

    if (inicio > fim)
    {
        printf("O intervalo é inválido (início é maior que o fim). Encerrando programa...\n");
        return 0;
    }

    if (fim < inicio)
    {
        printf("O intervalo é inválido (fim é maior que o início). Encerrando programa...\n");
        return 0;
    }

    printf("Os seguintes números são divisíveis por %d:\n", multiplo);
    multiplo_de_n(inicio, fim, multiplo);

    return 0;
}