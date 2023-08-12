#include <stdio.h>

/*
    - Descrição
    Faça um programa que dado um número indique se ele é um primo ou não. Nesta versão iniciante não se preocupe com a eficiência.
    Se você consegue cumprir essa missão de forma eficiente, é so tentar problema 260: "É um número primo?"

    - Formato de entrada
    Você irá receber uma sequência de números separados por um final de linha. A entrada termina quando o número lido for -1.

    - Formato de saída
    Para cada número lido você deve imprimir 0 caso o número não seja primo ou 1 caso seja.
    Depois de cada 0 ou 1 impresso, coloque um final de linha.
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

int e_primo(int numero)
{
    // Caso o número não seja divisível por nenhum outro além de si mesmo e de 1, ele é primo
    // Começamos verificando a divisão por 2, visto que os n°s primos são maiores que 1
    if (numero > 1 && !divisivel_por_outros(numero, 2))
    {
        return 1;
    };

    return 0;
}

void loop()
{
    int numero;
    scanf("%d", &numero);

    if (numero == -1)
    {
        return;
    }
    else
    {
        printf("%d\n", e_primo(numero));
        loop();
    }
}

int main()
{
    loop();

    return 0;
}