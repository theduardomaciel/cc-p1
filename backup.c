#include <stdio.h>
#include <string.h>
/* #include <math.h> */
#include <stdlib.h>

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

// Conceito Matemático:
// Chamamos números primos entre si (ou coprimos) ao conjunto de números onde o único divisor comum a todos eles é o número 1.
int e_coprimo(int numero1, int numero2)
{
    if (!divisivel_por_outros(numero1, 2) && !divisivel_por_outros(numero2, 2))
    {
        return 1;
    };

    return 0;
}

// Os jogadores entram em acordo e decidem uma quantidade de rodadas X
// Depois, eles mostram uma carta cada por rodada
// A batalha acontecerá entre essas duas cartas
// Os jogadores podem escolher uma habilidade única que ficará do início ao fim da rodada.

/*
    Habilidade:
    1 - Se for um round primo, poderá atacar 2 vezes.
    2 - Se a vida for coprimo da vida inimiga, aumenta o ataque em 25.
    3 - Se a vida ou ataque for um número primo, aumenta o ataque em 10.
*/

/*
    Após a escolha da habilidade, cada jogador mostra sua carta contendo Ataque e vida.
    Perde a rodada aquele que morrer primeiro.

        Obs: round não é a mesma coisa de rodadas.
        Obs: Rounds são as batalhas dentro de cada rodada.
        Obs: o round começa em 1.
        Obs: a habilidade só será ativada no momento que a carta for atacar.
        Obs: os buff's das habilidades são acumulados durante a rodada.
*/

/*
    -Formato de entrada:
    Primeiro será recebido um X equivalente ao numero de rodadas.
    Em seguida será lido X vezes:
        linha 1: um inteiro i, correspondente a quem vai começar atacando  na rodada; 1 (Will) e 2(Gabriel)
        linha 2: Três inteiros HABILIDADE, ATAQUE e VIDA, correspondente a habilidade, ataque e vida da carta do Will
        linha 3: Três inteiros HABILIDADE, ATAQUE e VIDA, correspondente a habilidade, ataque e vida da carta do Gabriel
*/

int round(int primeiro, int habilidade1, int ataque1, int vida1, int habilidade2, int ataque2, int vida2, int round_atual)
{
    if (primeiro == 1)
    {
        // Quem começa atacando é o Jogador 1 (Will)
        switch (habilidade1)
        {
        case 1:
            if (e_primo(round_atual)) // poderá atacar 2 vezes.
            {
                // para fazer isso de maneira simples, atacaremos ele nesse bloco de código uma vez e deixaremos que ele ataque novamente seguindo fluxo do código
                // não precisamos nos preocupar com os buffs sendo aplicados, visto que só é possível escolher uma habilidade
                vida2 -= ataque1;
            }
            break;
        case 2:
            if (e_coprimo(vida1, vida2)) // aumenta o ataque em 25.
            {
                ataque1 += 25;
            }
            break;
        case 3:
            if (e_primo(vida1) || e_primo(ataque1)) // aumenta o ataque em 10.
            {
                ataque1 += 10;
            }
            break;
        default:
            break;
        }
    }
    else
    {
        // Quem começa atacando é o Jogador 2 (Gabriel)
    }
}

void rodadas(int quant_rodadas, int rodada_atual, int rodadas_ganhas1, int rodadas_ganhas2)
{
    // Caso dê problema no The Huxley, verificar essas igualdades <=, etc.
    if (rodada_atual <= quant_rodadas)
    {
        int primeiro;
        int habilidade1, ataque1, vida1;
        int habilidade2, ataque2, vida2;

        scanf("%d", &primeiro);
        scanf("%d %d %d", &habilidade1, ataque1, vida1);
        scanf("%d %d %d", &habilidade2, ataque2, vida2);

        int jogador1_venceu = round(primeiro, habilidade1, ataque1, vida1, habilidade2, ataque2, vida2, 1); // de acordo com uma das observações, o round começa em 1
        if (jogador1_venceu)
        {
            ++rodadas_ganhas1;
        }
        else
        {
            ++rodadas_ganhas2;
        }

        rodadas(quant_rodadas, rodada_atual + 1, rodadas_ganhas1, rodadas_ganhas2);
    }
    else
    {
        if (rodadas_ganhas1 > rodadas_ganhas2)
        {
            printf("Will ganhou %d rodadas\n", rodadas_ganhas1);
        }
        else
        {
            printf("Gabriel ganhou %d rodadas\n", rodadas_ganhas2);
        }
    }
}

int main()
{
    int quant_rodadas;
    scanf("%d", &quant_rodadas);

    rodadas(quant_rodadas, 0);

    return 0;
}