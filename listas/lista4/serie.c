#include <stdio.h>
#include <stdbool.h>

/*
    - Descrição
        Faça um programa que mostre os n primeiros termos e calcule o resultado da seguinte série:

            1!/1 + 2!/2 + 3!/3 + 4!/5 + 5!/5 + 6!/7 + 7!/7 + 8!/11 + 9!/11 ...

        A cada termo são apresentados no dividendo o fatorial dos números naturais não nulos.
        No divisor, a partir do segundo termo, temos o menor número primo que seja maior ou igual ao dividendo.

        Nesse programa você deve fazer pelo menos 3 funções:
            1. eh_primo(x): Retorna True ou False se um número é primo ou não
            2. proximo_primo(y): Retorna o próximo número primo a partir de um número y dado
            3. fatorial(z): Retorna o fatorial de um número

        O retorno deve ser os termos da série e o resultado da soma.

    - Formato de entrada
        Um número n que indica quantos termos devem ser calculados.

    - Formato de saída
        Os termos da série e o resultado da soma com duas casas decimais de aproximação.
*/

int divisivel_por_outros(int divisivel, int teste)
{
    if (teste < divisivel && divisivel % teste != 0)
    {
        // o teste ainda não alcançou o valor do n° "divisivel"
        return divisivel_por_outros(divisivel, teste + 1);
    }
    else if (teste >= divisivel && divisivel % teste == 0)
    {
        // não é divisível
        return 0;
    }
    else
    {
        // é divisível por algum número
        return 1;
    }
}

bool eh_primo(int numero)
{
    // Caso o número não seja divisível por nenhum outro além de si mesmo e de 1, ele é primo
    // Começamos verificando a divisão por 2, visto que os n°s primos são maiores que 1
    if (numero > 1 && !divisivel_por_outros(numero, 2))
    {
        return 1;
    };

    return 0;
}

int proximo_primo(int inicio)
{
    if (eh_primo(inicio) == true)
    {
        return inicio;
    }
    else
    {
        return proximo_primo(inicio + 1);
    }
}

int fatorial(int z)
{
    // Checamos o caso base
    if (z == 0)
    {
        return 1;
    }

    // Caso contrário, realizamos a recursão
    return z * fatorial(z - 1);
}

void criar_serie(int quant_termos, int atual, double total)
{
    int primo_atual = atual == 1 ? 1 : proximo_primo(atual);
    double resultado = (fatorial(atual) / (primo_atual * 1.0));

    if (atual > quant_termos)
    {
        printf("%.2lf\n", total);
    }
    else
    {
        if (atual < quant_termos)
        {
            printf("%d!/%d + ", atual, primo_atual);
        }
        else
        {
            printf("%d!/%d\n", atual, primo_atual);
        }

        // printf("%d!/%d = %.2lf\n", atual, primo_atual, resultado);
        criar_serie(quant_termos, atual + 1, total + resultado);
    }
}

int main()
{
    int quant_termos;
    scanf("%d", &quant_termos);

    criar_serie(quant_termos, 1, 0.0);

    return 0;
}