#include <stdio.h>
#include <math.h>

/*
    Os pokemon possuem apenas duas habilidades:
        1. um ataque de dano, que se escolhido causa um dano D (dano atual do pokemon) no seu adversário,
        2. uma habilidade especial, que, se escolhida, aumenta permanentemente o seu dano em 50 unidades.
*/

/*
    - Formato de entrada:
        No início você receberá um numero  1 <= n <= 1000, o numero de batalhas a serem disputadas (considere que cada batalha é independente).
        Em seguida, você receberá n linhas contendo, na ordem V1, V2, D1, D2, quarto números inteiros cada:
            - V1 e D1, a vida e dano inicial do pokemon de Clodes, respectivamente.
            - V2 e D2 são a vida e dano inicial do pokemon de Bezaliel, respectivamente.

        1 <= [V1, V2, D1, D2] <= 1000000

    - Formato de saída:
        Para cada batalha, sua resposta deve ser uma única linha contendo “Clodes” ou “Bezaliel”, sem aspas, o nome do treinador que deverá ganhar aquela batalha.
*/

// As batalhas são baseadas em turnos, onde, em cada turno, o pokemon mais rápido pode usar sua habilidade primeiro.
// Cada pokemon tem uma quantidade inteira de vida V e um dano inicial inteiro D.
// A batalha termina quando um dos pokemons perde toda sua vida.

// Em um turno, um pokemon pode usar APENAS UMA de suas habilidades.
// Considere que o pokemon de Clodes é o mais rápido, ou seja, ele sempre ataca primeiro.
// Considere que cada treinador joga de maneiro ótima, se mantendo sempre fiel a sua estratégia.

// JOGADOR 1 - Clodes
// JOGADOR 2 - Bezaliel (o dano2 sempre será 50)

void batalha(int quant_rodadas_para_derrota_jogador1, int dano1, int vida2, int round_atual)
{
    int Incremento_Habilidade_Especial = 50;

    // printf("Vida inimigo: %d | Vida Clodes: %d | Dano inimigo: %d | Dano de Clodes: %d\n", vida2, vida1, dano2, dano1);

    // Bezaliel vai atacar TODOS os turnos até derrotar o inimigo ou perder tentando
    // Clodes sempre ataca primeiro e vai usar a habilidade ESPECIAL de incrementar o dano de seu pokemon ATÉ chegar num ponto que não possa mais perder, e só ENTÃO começar a ATACAR

    int quant_rodadas_restantes = quant_rodadas_para_derrota_jogador1 - round_atual;
    int dano_incrementado_acumulado_jogador1 = dano1 + (Incremento_Habilidade_Especial * round_atual);

    if (quant_rodadas_para_derrota_jogador1 == round_atual)
    {
        // A quantidade de rodadas em que Clodes precisava ter eliminado Belaziel acabaram, portanto Clodes perdeu
        printf("Bezaliel\n");
    }
    else if (dano_incrementado_acumulado_jogador1 * quant_rodadas_restantes >= vida2)
    {
        // O dano acumulado de Clodes durante as rodadas restantes ultrapassou a vida de Belaziel, portanto Clodes ganhou
        printf("Clodes\n");
    }
    else
    {
        batalha(quant_rodadas_para_derrota_jogador1, dano1, vida2, round_atual + 1);
    }
}

void batalhas(int quant_batalhas)
{
    if (quant_batalhas > 0)
    {
        int vida1, dano1, vida2, dano2;
        scanf("%d %d %d %d", &vida1, &vida2, &dano1, &dano2);

        // O dado do jogador 2 (dano2) é fixo durante todos os rounds
        int quant_rodadas_para_derrota_jogador1 = vida1 / dano2;

        // Caso a divisão possua casas decimais, adicionamos 1 à quantidade de rodadas para que o jogador 1 perca, visto que é immpossível perder 1/2 partida, por exemplo
        if (vida1 % dano2 != 0)
        {
            quant_rodadas_para_derrota_jogador1 += 1;
        }

        // printf("\n-> Batalha %d:\n", quant_batalhas);
        batalha(quant_rodadas_para_derrota_jogador1, dano1, vida2, 0);

        batalhas(quant_batalhas - 1);
    }
}

int main()
{
    int quantidade_de_batalhas;
    scanf("%d", &quantidade_de_batalhas);

    batalhas(quantidade_de_batalhas);
    return 0;
}