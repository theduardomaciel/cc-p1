#include <stdio.h>

void decrescente(int numero)
{
    // o "=" de >= é o caso base
    if (numero >= 1)
    {
        // Como o printf abaixo é a primeira coisa a ser executada, começaremos com o número de input e iremos decrescendo até alcançar o último elemento (caso base)
        printf("%d\n", numero);

        decrescente(numero - 1); // essa função será chamada enquanto n >= 1, tendo sido o valor "numero" já impresso
    }
}

void crescente(int numero)
{
    // o "=" de >= é o caso base
    if (numero >= 1)
    {
        crescente(numero - 1); // essa função será chamada enquanto n >= 1, enquanto não for, irá chamar a função de novo, impedindo o printf abaixo

        // O printf abaixo será executado na ordem inversa (primeiro a última função a ser chamada, ou seja, a que atingiu o caso base numero = 1)
        printf("%d\n", numero);
    }
}

void intervalo(int a, int b)
{
    if (a <= b) // caso base: a = b
    {
        printf("%d\n", a);

        intervalo(a + 1, b);
    }
}

int main()
{
    printf("Digite: \n\t-> 'c' para contar de forma crescente (seguido de 1 número inteiro)\n\t-> 'd' para contar de forma decrescente (seguido de 1 número inteiro)\n\t-> 'i' para contar entre um intervalo (seguido de 2 números inteiros)\n");

    char tipo;
    scanf(" %c", &tipo);

    // crescente(numero, 0);
    if (tipo == 'c' || tipo == 'C')
    {
        printf("Insira o número para contagem crescente: ");
        int numero;
        scanf("%d", &numero);

        crescente(numero);
    }
    else if (tipo == 'd' || tipo == 'D')
    {
        printf("Insira o número para contagem decrescente: ");
        int numero;
        scanf("%d", &numero);

        decrescente(numero);
    }
    else if (tipo == 'i' || tipo == 'I')
    {
        printf("Insira os números de início e fim do intervalo para contagem: ");
        int numero1, numero2;
        scanf("%d %d", &numero1, &numero2);

        intervalo(numero1, numero2);
    }
    else
    {
        printf("O tipo informado está fora dos suportados pelo programa. Encerrando...\n");
    }

    return 0;
}

// v1
/* int decrescente(int numero)
{
    printf("%d\n", numero);

    if (numero == 1)
    {
        return 1;
    }

    return decrescente(numero - 1);
} */

// v1
/* int crescente(int objetivo, int atual)
{
    printf("%d\n", atual);

    if (atual >= objetivo)
    {
        return objetivo;
    }

    return crescente(objetivo, atual + 1);
} */

// v2
/* int crescente(int numero)
{
    // Após cada chamada da função "crescente" iremos realizar essa verificação (caso base)
    if (numero == 1)
    {
        return 1;
    }

    int proximo = crescente(numero - 1); // essa função será chamada até que numero = 1, enquanto não for, irá ser chamada de novo e de novo até atingir o caso base

    // Após alcançar o caso base, o printf abaixo será executado na ordem inversa (primeiro a última função a ser chamada, ou seja, a que atingiu o caso base numero = 1)
    printf("%d\n", proximo);

    return numero;
} */