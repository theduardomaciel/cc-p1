#include <stdio.h>

void number_translate(int numero)
{
    int digito_atual = numero % 10;
    if (numero == 0)
    {
        printf("\n");
        return;
    }
    else
    {
        // O número é par
        if (digito_atual % 2 == 0)
        {
            printf(".");
        }
        else
        {
            // O número é ímpar
            printf("-");
        }

        return number_translate(numero / 10);
    }
}

void loop(int restante)
{
    if (restante > 0)
    {
        int numero_atual;
        scanf("%d", &numero_atual);

        number_translate(numero_atual);

        return loop(restante - 1);
    }
}

int main()
{
    loop(10);
    return 0;
}