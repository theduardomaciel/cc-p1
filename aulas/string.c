#include <stdio.h>
#include <string.h>

void imprimir_ao_contrario(char str[], int i)
{
    if (i == -1)
    {
        printf("\n");
        return;
    }
    printf("%c", str[i]);
    imprimir_ao_contrario(str, i - 1);
}

void para_maiusculo(char frase[], int final)
{
    if (final == -1)
        return;
    if (frase[final] >= 'a' && frase[final] <= 'z')
    {
        frase[final] = frase[final] - ('a' - 'A');
    }
    para_maiusculo(frase, final - 1);
}

int main()
{
    // // string
    char nome[11]; // = {'o' , 'i' , '\0', 'h', 'i', 'k', 'o', 'q', 'x', 'z' };

    // // leitura
    // // scanf("%s", nome);
    gets(nome);
    // // fgets(nome, 2, stdin);

    // printf("%s\n", nome);

    // imprimir_ao_contrario(nome, strlen(nome) - 1);

    // char maiusculo = 'R';
    // char minusculo = maiusculo + ('a' - 'A');

    // printf("%c\n", minusculo);

    // printf("%c\n", 'A');

    para_maiusculo(nome, strlen(nome) - 1);

    printf("%s\n", nome);

    return 0;
}