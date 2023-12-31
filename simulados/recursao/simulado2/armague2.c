#include <stdio.h>

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
int mdc(int dividendo, int divisor)
{
    // Quando não houver resto entre a divisão do dividendo e do divisor, podemos retornar o divisor como o maior possível
    if (dividendo % divisor == 0)
    {
        return divisor;
    }
    else
    {
        return mdc(divisor, dividendo % divisor);
    }
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
        linha 1: um inteiro i, correspondente a quem vai começar atacando na rodada; 1 (Will) e 2(Gabriel)
        linha 2: Três inteiros HABILIDADE, ATAQUE e VIDA, correspondente a habilidade, ataque e vida da carta do Will
        linha 3: Três inteiros HABILIDADE, ATAQUE e VIDA, correspondente a habilidade, ataque e vida da carta do Gabriel
*/

int aplicar_habilidade(int habilidade, int round_atual, int vida, int vida_inimiga, int *ataque)
{
    int ataque_duplo = 0;

    switch (habilidade)
    {
    case 1:
        if (e_primo(round_atual)) // poderá atacar 2 vezes.
        {
            // para fazer isso de maneira simples, atacaremos ele nesse bloco de código uma vez e deixaremos que ele ataque novamente seguindo fluxo do código
            // não precisamos nos preocupar com os buffs sendo aplicados, visto que só é possível escolher uma habilidade
            ataque_duplo = 1;
        }
        break;
    case 2:
        if (mdc(vida, vida_inimiga) == 1) // aumenta o ataque em 25.
        {
            // printf("\n%d e %d são coprimos!\n", vida, vida_inimiga);
            *ataque += 25;
        }
        break;
    case 3:
        if (e_primo(vida) || e_primo(*ataque)) // aumenta o ataque em 10.
        {
            *ataque += 10;
        }
        break;
    default:
        break;
    }
    return ataque_duplo;
}

int round_da_rodada(int primeiro, int habilidade1, int ataque1, int vida1, int habilidade2, int ataque2, int vida2, int round_atual)
{
    if (vida1 <= 0)
    {
        // Jogador 1 perdeu
        return 0;
    }
    else if (vida2 <= 0)
    {
        // Jogador 1 ganhou
        return 1;
    }
    else
    {
        if (primeiro == 1)
        {
            // Nas rodadas desse round quem começa atacando é o Jogador 1 (Will)
            int ataque_duplo1 = aplicar_habilidade(habilidade1, round_atual, vida1, vida2, &ataque1);
            vida2 -= ataque1 * (ataque_duplo1 ? 2 : 1);

            int ataque_duplo2 = aplicar_habilidade(habilidade2, round_atual, vida2, vida1, &ataque2);
            vida1 -= ataque2 * (ataque_duplo2 ? 2 : 1);
        }
        else
        {
            // Nas rodadas desse round quem começa atacando é o Jogador 2 (Gabriel)
            int ataque_duplo2 = aplicar_habilidade(habilidade2, round_atual, vida2, vida1, &ataque2);
            vida1 -= ataque2 * (ataque_duplo2 ? 2 : 1);

            int ataque_duplo1 = aplicar_habilidade(habilidade1, round_atual, vida1, vida2, &ataque1);
            vida2 -= ataque1 * (ataque_duplo1 ? 2 : 1);
        }

        return round_da_rodada(primeiro, habilidade1, ataque1, vida1, habilidade2, ataque2, vida2, round_atual + 1);
    }
}

void rodadas(int quant_rodadas, int rodada_atual, int rodadas_ganhas1, int rodadas_ganhas2)
{
    // printf("Quantidade de rodadas: %d\n", quant_rodadas);
    //  Caso dê problema no The Huxley, verificar essas igualdades <=, etc.
    // printf("\nQuantidade de rodadas: %d | Rodada atual: %d\n", quant_rodadas, rodada_atual);
    if (rodada_atual < quant_rodadas)
    {
        int primeiro;
        int habilidade1, ataque1, vida1;
        int habilidade2, ataque2, vida2;

        scanf("%d", &primeiro);
        scanf("%d %d %d", &habilidade1, &ataque1, &vida1);
        scanf("%d %d %d", &habilidade2, &ataque2, &vida2);

        int jogador1_venceu = round_da_rodada(primeiro, habilidade1, ataque1, vida1, habilidade2, ataque2, vida2, 1); // de acordo com uma das observações, o round começa em 1

        if (jogador1_venceu)
        {
            rodadas_ganhas1 += 1;
        }
        else
        {
            rodadas_ganhas2 += 1;
        }

        rodadas(quant_rodadas, rodada_atual + 1, rodadas_ganhas1, rodadas_ganhas2);
    }
    else
    {
        printf("Will ganhou %d rodadas\n", rodadas_ganhas1);
        printf("Gabriel ganhou %d rodadas\n", rodadas_ganhas2);
    }
}

int main()
{
    int quant_rodadas;
    scanf("%d", &quant_rodadas);

    rodadas(quant_rodadas, 0, 0, 0);

    return 0;
}