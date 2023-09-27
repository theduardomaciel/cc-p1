#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Consiste de um tabuleiro com n casas, numeradas de 0 a n - 1.
// Por ser muito popular, vários jogadores podem jogar. Eles vão se alternando. A cada rodada, primeiro o jogador 1 joga o dado, depois o 2, depois o 3, depois o n ... e assim por diante.

// Inicialmente os jogadores colocam seus sapos na casa 0.

// As casas são neutras, bonificam ou penalizam o jogador.
// Uma casa neutra possui valor 0, uma casa positiva possui um valor positivo e uma casa  negativa um valor negativo.

// Suponha que o valor da casa é x.
/*
    + Se x é positivo, significa que o sapo deve pular para frente(avançar) x casas. Por exemplo, se ele está na casa 4 e x for 3, então ele deve ir para a casa 7.
    - Se x é negativo, significa que o sapo deve pular para trás (retroceder) x casas.
    Se x é 0, então significa que o sapo não deve retroceder ou avançar.
*/

/*
    Mais um detalhe importante: OS SAPOS PODEM DAR VÁRIOS VOLTAS NO TABULEIRO.
    """"Ou seja, depois da casa n - 1 a casa seguinte é a 0.""""
    O mesmo ocorre no sentido inverso, por exemplo, se ele estiver na casa 1 e tiver que retroceder 4 casas, ele deve ir para casa n - 3.

    Sua missão é ao final das rodadas identificar em que casa do tabuleiro está cada sapo.
*/

/*
    ENTRADA:
    A primeira linha consiste dos inteiros n, m e o, onde:
        1. n corresponde ao número de casas do tabuleiro;
        2. m corresponde ao número de jogadores;
        3. o corresponde ao número de rodadas;

    Depois serguirão n linhas, correspondendo aos valores de cada uma das casas do tabuleiro.
    Depois você receberá o * m linhas com números inteiros (valores (v) do dado obtidos por cada jogador em cada rodada.)
 */

int check_position(int position, int movement, int limit)
{
    int new_position = (position + movement) % limit;

    if (new_position < 0)
    {
        // Se a posição for negativa, ajustamos para o final do tabuleiro
        new_position += limit;
    }

    return new_position;
}

int main()
{
    int houses_amount, players_amount, rounds_amount;
    scanf("%d %d %d", &houses_amount, &players_amount, &rounds_amount);
    // printf("%d %d %d\n", houses_amount, players_amount, rounds_amount);

    // Obtemos os valores das casas
    int board_houses[houses_amount];
    for (int i = 0; i < houses_amount; i++)
    {
        scanf("%d", &board_houses[i]);
    }

    // Obtemos os valores dos dados dos jogadores
    int dices[rounds_amount][players_amount];
    // QUE ÓDIOOOOOOOOOOO. Passei 5 HORAS, debugando essa questão :)

    for (int round = 0; round < rounds_amount; round++)
    {
        for (int player = 0; player < players_amount; player++)
        {
            scanf("%d", &dices[round][player]);
            // printf("%d\t", dices[player][round]);
        }
    }

    int players_positions[players_amount];
    memset(players_positions, 0, sizeof(players_positions)); // todos os jogadores começam na casa 0

    for (int round = 0; round < rounds_amount; round++)
    {
        // printf("//// Round: %d ////\n", round);
        for (int player = 0; player < players_amount; player++)
        {
            // printf("-> Player: %d\n", player);

            int dice = dices[round][player];
            int new_position = players_positions[player];

            // Devemos mover o jogador para a nova posição
            new_position = check_position(players_positions[player], dice, houses_amount);

            // Após movermos o jogador, devemos atualizar sua posição com o valor da casa
            new_position = check_position(new_position, board_houses[new_position], houses_amount);

            players_positions[player] = new_position;
            // printf("------------------\n");
        }
    }

    for (int player = 0; player < players_amount; player++)
    {
        printf("%d\n", players_positions[player]);
    }

    return 0;
}
