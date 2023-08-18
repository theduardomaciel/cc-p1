#include <stdio.h>
#include <math.h>

// Um número perfeito, segundo eles, é todo número que é primo e, ao mesmo tempo, faz parte da sequencia Fibonacci,
// Os números quase perfeitos são aqueles que são OU primos OU fazem parte da sequencia Fibonacci

// No inicio eles definem o número N (0 < N <= 50) de rodadas do jogo, em cada rodada eles escrevem no papel o primeiro número X (1 <= X <= 10000) que vem a sua cabeça, após escreverem eles verificam a pontuação.

/*
    Se é um número perfeito o jogador ganha 3 pontos
    Se é um número quase perfeito o jogador ganha 1 ponto
    Se não é nem perfeito, nem quase perfeito o jogador não ganha pontos.
    Em caso de empate ganha aquele que escolheu maior número
*/

// Obs: É garantido que os dois números são sempre diferentes

int e_quadrado_perfeito(int x)
{
    int s = (int)sqrt(x);
    return (s * s == x);
}

int e_fibonacci(int x)
{
    return e_quadrado_perfeito(5 * x * x + 4) || e_quadrado_perfeito(5 * x * x - 4);
}

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

int e_perfeito(int numero)
{
    if (e_primo(numero) && e_fibonacci(numero))
    {
        return 1;
    }

    return 0;
}

int e_semiperfeito(int numero)
{
    if (e_primo(numero) || e_fibonacci(numero))
    {
        return 1;
    }

    return 0;
}

// X = Kcaj e Y = Ordep
void rodadas(int quant_rodadas, int rodada_atual)
{
    if (rodada_atual < quant_rodadas)
    {
        int inteiroX, inteiroY;
        scanf("%d %d", &inteiroX, &inteiroY);

        int pontosX = 0, pontosY = 0;

        if (e_perfeito(inteiroX))
        {
            // printf("O número de Kcaj (%d) é perfeito.\n", inteiroX);
            pontosX += 3;
        }
        else if (e_semiperfeito(inteiroX))
        {
            // printf("O número de Kcaj (%d) é semiperfeito.\n", inteiroX);
            pontosX += 1;
        }

        if (e_perfeito(inteiroY))
        {
            // printf("O número de Ordep (%d) é perfeito.\n", inteiroY);
            pontosY += 3;
        }
        else if (e_semiperfeito(inteiroY))
        {
            // printf("O número de Ordep (%d) é semiperfeito.\n", inteiroY);
            pontosY += 1;
        }

        if (pontosX == pontosY)
        {
            // printf("Pontuação igual (inteiro 1: %d) (inteiro 2: %d)\n", inteiroX, inteiroY);
            if (inteiroX > inteiroY)
            {
                printf("Kcaj\n");
            }
            else
            {
                printf("Ordep\n");
            }
        }
        else if (pontosX > pontosY)
        {
            printf("Kcaj\n");
        }
        else
        {
            printf("Ordep\n");
        }

        rodadas(quant_rodadas, rodada_atual + 1);
    }
}

int main()
{
    int quant_rodadas;
    scanf("%d", &quant_rodadas);

    rodadas(quant_rodadas, 0);

    return 0;
}