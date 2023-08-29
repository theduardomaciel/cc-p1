#include <stdio.h>
#include <math.h>

/*
    REGRAS GERAIS:
        1. Caso a rodada esteja em um número primo, kcaj não atacará e como consequência, não conseguirá usar sua habilidade naquele momento.
        2. Caso a rodada esteja em um número resultante da potência de 2, Ordep não atacará e como consequência, não conseguirá usar sua habilidade naquele momento.

    OBS.1: as duas regras podem ser ativadas juntas

    -> Na vez de Ordep, caso a vida de seu boneco seja maior que o ataque, os atributos serão trocados antes de atacar
    -> Na vez de kcaJ, caso a vida de seu boneco seja ímpar, ele aumenta seu ataque em 5 antes de atacar.

    OBS.2: As habilidades podem ativar mais de uma vez na mesma batalha.

    !!! Ordep sempre vai ser o primeiro a atacar em cada batalha.

    Uma rodada é composta pelo ataque (ou tentativa, caso a regra seja ativada) de Ordep e Kcaj. Perde aquele na qual o personagem tiver vida menor ou igual a 0 primeiro.

    OBS.3: Batalha não é a mesma coisa que rodada, em 1 batalha podemos ter várias rodadas.
    OBS.4: Considere que a rodada sempre inicia em 1.
*/

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

/* int eh_da_potencia_2(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    else

        if (num > 1)
    {
        if (num % 2 != 0)
        {
            return 0;
        }
        return eh_da_potencia_2(num /= 2);
    }

    return 1;
} */

/* int potencia_2(int num, int potencia)
{
    if (sqrt(potencia) > num)
    {
        return 0; // Falso (não faz parte das potências)
    }

    if (pow(2, potencia) == num)
    {
        return 1; // Verdadeiro (faz parte das potências)
    }

    // Chama a função recursivamente com a próxima potência
    return primo(num, potencia + 1);
}

int eh_da_potencia_2(int num)
{
    return potencia_2(num, 0);
} */

/* int eh_da_potencia_2(int num)
{
    if (num <= 0)
    {
        return 0; // Falso para números não positivos
    }

    // Verifica se num é uma potência de 2
    return (num & (num - 1)) == 0;
} */

int eh_da_potencia_2(int rodada, int i)
{
    if (rodada == i)
    {
        return 1;
    }

    if (i > rodada)
    {
        return 0;
    }

    return eh_da_potencia_2(rodada, i * 2);
}

int rodadas(int atual, int ataque_pedro, int vida_pedro, int ataque_jack, int vida_jack)
{

    if (vida_jack <= 0)
    {
        // Pedro ganhou
        return 1;
    }

    if (vida_pedro <= 0)
    {
        // Jack ganhou
        return 2;
    }

    // ATAQUE DE PEDRO (sempre ataca primeiro)
    if (eh_da_potencia_2(atual, 1) == 0)
    {
        // Como a rodada não está em um número primo, Pedro pode atacar
        // HABILIDADE
        if (vida_pedro > ataque_pedro)
        {
            int antiga_vida = vida_pedro;
            int antigo_ataque = ataque_pedro;
            vida_pedro = antigo_ataque;
            ataque_pedro = antiga_vida;
        }

        vida_jack -= ataque_pedro;
    }

    // ATAQUE DE JACK
    // printf("%d é numero resultante da potência de 2? %d\n", atual, eh_da_potencia_2(atual));
    if (!eh_primo(atual))
    {
        // HABILIDADE
        if (vida_jack % 2 != 0)
        {
            ataque_jack += 5;
        }

        vida_pedro -= ataque_jack;
    }

    rodadas(atual + 1, ataque_pedro, vida_pedro, ataque_jack, vida_jack);
}

int batalha()
{
    int ataque_pedro, vida_pedro;
    scanf("%d %d", &ataque_pedro, &vida_pedro);

    int ataque_jack, vida_jack;
    scanf("%d %d", &ataque_jack, &vida_jack);

    //  1 = pedro ganhou | 2 = jack ganhou
    int resultado = rodadas(1, ataque_pedro, vida_pedro, ataque_jack, vida_jack);
    return resultado;
}

void batalhas(int quant_batalhas, int *vitorias_pedro, int *vitorias_jack)
{
    if (quant_batalhas > 0)
    {
        int resultado = batalha();

        if (resultado == 1)
        {
            *vitorias_pedro = *vitorias_pedro + 1;
        }
        else if (resultado == 2)
        {
            *vitorias_jack = *vitorias_jack + 1;
        }

        return batalhas(quant_batalhas - 1, vitorias_pedro, vitorias_jack);
    }
}

int main()
{
    int quant_batalhas;
    scanf("%d", &quant_batalhas);

    int vitorias_pedro = 0, vitorias_jack = 0;
    batalhas(quant_batalhas, &vitorias_pedro, &vitorias_jack);

    if (vitorias_pedro > vitorias_jack)
    {
        printf("ordep ganhou %d coffees\n", vitorias_pedro);
    }
    else if (vitorias_jack > vitorias_pedro)
    {
        printf("kcaj ganhou %d coffees\n", vitorias_jack);
    }
    else
    {
        printf("F coffees\n");
    }

    return 0;
}