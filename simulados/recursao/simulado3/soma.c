#include <stdio.h>

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

int somatorio(int num)
{
    if (num == 0)
    {
        return 0; // Caso base: quando o número é zero, o somatório é zero
    }
    else
    {
        return (num % 10) + somatorio(num / 10); // Somar o último dígito e chamar a função para o resto do número
    }
}

int primo(int num, int divisor)
{
    // Caso base: se o divisor se tornar 1, o número é primo
    if (divisor == 1)
    {
        return 1; // Verdadeiro (primo)
    }

    // Se o número é divisível pelo divisor atual, não é primo
    if (num % divisor == 0)
    {
        return 0; // Falso (não é primo)
    }

    // Chama a função recursivamente com o próximo divisor
    return primo(num, divisor - 1);
}

int eh_primo(int num)
{
    // Trata o caso especial para números menores que 2
    if (num <= 1)
    {
        return 0; // Falso (não é primo)
    }

    // Inicia a verificação recursiva a partir do divisor máximo (num - 1)
    return primo(num, num - 1);
}

int proximo_primo(int inicio)
{
    if (eh_primo(inicio))
    {
        return inicio;
    }
    else
    {
        return proximo_primo(inicio + 1);
    }
}

void request_input(int atual, int quant_entradas, int *menor_soma, int *maior_soma)
{
    if (atual < quant_entradas)
    {
        int numero;
        scanf("%d", &numero);

        int soma = somatorio(numero);
        printf("N: %d - Soma: %d\n", numero, soma);

        if (*menor_soma == 0 || soma < *menor_soma)
        {
            *menor_soma = soma;
        }

        if (soma > *maior_soma)
        {
            *maior_soma = soma;
        }

        return request_input(atual + 1, quant_entradas, menor_soma, maior_soma);
    }

    return;
}

int main()
{
    int quant_entradas = 0;
    scanf("%d", &quant_entradas);

    int menor_soma = 0;
    int maior_soma = 0;

    request_input(0, quant_entradas, &menor_soma, &maior_soma);

    printf("\nMaior soma: %d\n", maior_soma);
    printf("Menor soma: %d\n", menor_soma);

    // printf("fatorial: %d\n", fatorial(menor_soma));
    // printf("próximo primo: %d\n", proximo_primo(menor_soma + 1));

    printf("Valor Y: %.2lf\n", (double)(fatorial(menor_soma) + proximo_primo(menor_soma + 1)) / (maior_soma * 1.00));

    return 0;
}