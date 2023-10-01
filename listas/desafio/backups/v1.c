#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Pedro e Túlio decidiram se aventurar numa floresta cheia de monstros, onde COMEÇARÃO EM POSIÇÕES DIFERENTES do mapa.
// A floresta terá tamanho N x N, e seus valores vão representar o id do monstro que está em determinada posição, ou -1 caso não aja monstro na posição.

/*
    Os monstros vão ter:

        - id (inteiro MAIOR que 0)
        - classe (string)
        - vida (inteiro MAIOR que 0)
        - dano (inteiro MAIOR que 0)
        - experiência dada ao morrer (inteiro MAIOR que 0)
*/

typedef struct initial
{
    int line;
    int column;
    int life;
    char name;
} initial;

typedef struct monster
{
    unsigned int id;
    char class[10];
    int life;
    unsigned int damage;
    unsigned int experience_on_death;
    initial initial;
} monster;

/*
    Pedro e Túlio terão:
        - classe (string)
        - dano (inteiro MAIOR que 0)
        - vida (inteiro MAIOR que 0)
        - experiência acumulada (inteiro)
*/

typedef struct player
{
    char class[10];
    unsigned int damage;
    int life;
    int experience;
    int line;
    int column;
    initial initial;
} player;

/*
    Movimentos possíveis:
        1 - para cima
        2 - para baixo
        3 - para esquerda
        4 - para direita
*/

// Caso um monstro seja encontrado, O JOGADOR IRÁ LUTAR CONTRA ELE e terá as duas possibilidades:
/*
    ao GANHAR:
        - ganha a experiência do monstro,
        - vida permanecerá com a baixa sofrida pelo monstro
        - o monstro deixa de existir naquela posição.

    ao PERDER:
    - experiencia acumulada reduzida pela metade (exp /= 2)
    - vida volta a ficar completa
    - volta pra posição inicial (dada na entrada)
    - monstro volta a ter a vida completa
*/

// O JOGADOR SEMPRE INICIARÁ ATACANDO o monstro e eles se atacarão até que um dos dois morra.

/*
    BONIFICAÇÃO DAS CLASSES (não acumulada, ou seja, SÓ DURA DURANTE A LUTA ATUAL):
        - assassino dobra seu dano contra arqueiro (apenas uma vez)
        - arqueiro dobra seu dano contra mago (apenas uma vez)
        - mago dobra seu dano conta assassino (apenas uma vez)
*/

/*
    OBSERVAÇÕES:
    - A EXPERIÊNCIA de ambos os jogadores serão INICIADAS EM 0.
    - Caso tenha algum monstro nas posições iniciais de algum deles, não acontecerá nenhuma batalha naquele momento (ou seja, só tem batalha na posição após a primeira movimentação)

    - Caso os dois jogadores se encontrem, não haverá luta entre eles, ou seja, APENAS HAVERÁ DUELO ENTRE OS MONSTROS.
    - !!! Caso o jogador tente ultrapassar os limites da floresta, o movimento será desconsiderado e ele permanecerá no mesmo local.
    - PEDRO SE MOVIMENTA PRIMEIRO que Túlio.
    - !!! A luta só ocorrerá, quando o movimento for para um local válido.
    - A bonificação só será feita para os jogadores, então MONSTROS NÃO GANHAM BONIFICAÇÕES.
    - Caso tenha um monstro na posição inicial e você receba um movimento para local inválido, não acontecerá luta.
*/

void forest_map(int forest_size, int forest[forest_size][forest_size], player player1, player player2)
{
    printf("\t0\t1\t2\t3\t4\n");
    printf("\t--------------------------------\n");
    for (int line = 0; line < forest_size; line++)
    {
        printf("%d |\t", line);
        for (int column = 0; column < forest_size; column++)
        {
            if (line == player1.line && column == player1.column)
            {
                if (forest[line][column] == -1)
                {
                    printf("%c\t", player1.initial.name);
                }
                else
                {
                    printf("%c (%d)\t", player1.initial.name, forest[line][column]);
                }
            }
            else if (line == player2.line && column == player2.column)
            {
                if (forest[line][column] == -1)
                {
                    printf("%c\t", player2.initial.name);
                }
                else
                {
                    printf("%c (%d)\t", player2.initial.name, forest[line][column]);
                }
            }
            else
            {
                if (forest[line][column] == -1)
                {
                    printf("-\t");
                }
                else
                {
                    printf("%d\t", forest[line][column]);
                }
            }
        }
        printf("\n");
    }
}

int move_player(int movement, player *player, int forest_size, int forest[forest_size][forest_size], int other_pos[2])
{
    int is_invalid = 0;
    switch (movement)
    {
    case 1: // pra cima
        // new_pos = player->line - 1;
        if (player->line - 1 < 0 || (player->line - 1 == other_pos[0] && player->column == other_pos[1]))
        {
            printf("\t-> O jogador tentou ir para uma posição inválida (cima)\n");
            is_invalid = 1;
            break;
        }
        player->line -= 1;
        printf("O jogador se moveu para cima [%d, %d]", player->line, player->column);
        break;
    case 2: // pra baixo
        // new_pos = player->line + 1;
        if (player->line + 1 >= forest_size || (player->line + 1 == other_pos[0] && player->column == other_pos[1]))
        {
            printf("\t-> O jogador tentou ir para uma posição inválida (baixo)\n");
            is_invalid = 1;
            break;
        }
        player->line += 1;
        printf("O jogador se moveu para baixo [%d, %d]", player->line, player->column);
        break;
    case 3: // pra esquerda
        // new_pos = player->column - 1;
        if (player->column - 1 < 0 || (player->line == other_pos[0] && player->column - 1 == other_pos[1]))
        {
            printf("\t-> O jogador tentou ir para uma posição inválida (esquerda)\n");
            is_invalid = 1;
            break;
        }
        player->column -= 1;
        printf("O jogador se moveu para esquerda [%d, %d]", player->line, player->column);
        break;
    case 4: // pra direita
        // new_pos = player->column + 1;
        if (player->column + 1 >= forest_size || (player->line == other_pos[0] && player->column + 1 == other_pos[1]))
        {
            printf("\t-> O jogador tentou ir para uma posição inválida (direita)\n");
            is_invalid = 1;
            break;
        }
        player->column += 1;
        printf("O jogador se moveu para direita [%d, %d]", player->line, player->column);
        break;
    default:
        break;
    }

    return is_invalid;
}

void apply_buff(player *player, monster monster)
{
    // BONIFICAÇÃO: dobro de dano
    // Caso Túlio seja assassino e o monstro seja arqueiro
    if (player->class == "assasino" && monster.class == "arqueiro")
    {
        printf("O Jogador é ASSASSINO e o Monstro é ARQUEIRO\n");
        player->damage *= 2;
    }

    // Caso o jogador seja arqueiro e o monstro seja mago
    if (player->class == "arqueiro" && monster.class == "mago")
    {
        printf("O Jogador é ARQUEIRO e o Monstro é MAGO\n");
        player->damage *= 2;
    }

    // Caso o jogador seja mago e o monstro seja assassino
    if (player->class == "mago" && monster.class == "assassino")
    {
        printf("O Jogador é MAGO e o Monstro é ASSASSINO\n");
        player->damage *= 2;
    }
}

void player_action(player *player, int forest_size, int forest[forest_size][forest_size], int monsters_amount, monster monsters[], int *defeated_monsters_amount)
{
    // Caso tenha um monstro na posição atual do jogador, ele irá lutar contra ele
    if (forest[player->line][player->column] != -1)
    {
        printf(" e encontrou o monstro %d\n", forest[player->line][player->column]);
        for (int i = 0; i < monsters_amount; i++)
        {
            printf("Procurando o monstro %d\n", monsters[i].id);
            // Caso o id do monstro seja igual ao id do monstro na posição atual do jogador, encontramos o monstro com quem o jogador lutará
            if (monsters[i].id == forest[player->line][player->column])
            {
                monster current_monster = monsters[i];

                apply_buff(player, current_monster); // aplicamos a bonificação do jogador

                // Enquanto o jogador e o monstro estiverem vivos, eles irão lutar
                while (player->life > 0 && current_monster.life > 0)
                {
                    printf("Monstro: %d (-%d) = %d\n", current_monster.life, player->damage, current_monster.life - player->damage);

                    current_monster.life -= player->damage; // o monstro perde a vida que a qual o jogador deu dano

                    // Caso Túlio ganhe a luta
                    if (current_monster.life <= 0)
                    {
                        printf("o JOGADOR ganhou a luta\n");
                        *defeated_monsters_amount += 1; // incrementamos a quantidade de monstros derrotados

                        printf("Experiência do jogador: %d (+%d) = %d\n", player->experience, current_monster.experience_on_death, player->experience + current_monster.experience_on_death);
                        player->experience += current_monster.experience_on_death; // o jogador ganha a experiência do monstro
                        forest[player->line][player->column] = -1;                 // o monstro deixa de existir naquela posição

                        break;
                    }
                    else if (player->life <= 0)
                    {
                        printf("o MONSTRO ganhou a luta\n");
                        // Caso Túlio perca a luta
                        player->experience /= 2;                 // o jogador perde metade da experiência acumulada
                        player->life = player->initial.life;     // a vida do jogador volta a ficar completa
                        player->line = player->initial.line;     // O jogador volta pra linha inicial (dada na entrada)
                        player->column = player->initial.column; // O jogador volta pra coluna inicial (dada na entrada)

                        break;
                    }

                    printf("Jogador: %d (-%d) = %d\n", player->life, current_monster.damage, player->life - current_monster.damage);

                    player->life -= current_monster.damage; // o jogador perde a vida que o monstro deu dano
                }

                break;
            }
            else
            {
                printf("Não encontrou o monstro %d\n", forest[player->line][player->column]);
            }
        }
    }
    else
    {
        printf("\nNão há monstro na posição atual do jogador\n");
    }
}

int main()
{
    int monsters_amount;
    scanf("%d", &monsters_amount);
    printf("Quantidade de monstros: %d\n", monsters_amount);
    printf("id:\tclasse:\t\tvida:\tdano:\txp:\n");

    monster monsters[monsters_amount];
    for (int i = 0; i < monsters_amount; i++)
    {
        // Registramos os dados de cada monstro
        scanf("%u %s %u %u %u", &monsters[i].id, monsters[i].class, &monsters[i].life, &monsters[i].damage, &monsters[i].experience_on_death);
        monsters[i].initial.life = monsters[i].life; // salvamos a vida inicial do monstro

        printf("%u\t%s\t%u\t%u\t%u\n", monsters[i].id, monsters[i].class, monsters[i].life, monsters[i].damage, monsters[i].experience_on_death);
    }

    printf("---------------\n");

    player pedro;
    pedro.experience = 0; // inicializamos a experiência como 0

    scanf("%s %u %u %d %d", pedro.class, &pedro.damage, &pedro.life, &pedro.line, &pedro.column); // Registramos os dados de Pedro

    // Salvamos os dados que serão reiniciados no caso de uma derrota
    pedro.initial.life = pedro.life;
    pedro.initial.line = pedro.line;
    pedro.initial.column = pedro.column;
    pedro.initial.name = 'P';

    printf("Pedro | %s\t%u\t%u [%d, %d]\n", pedro.class, pedro.life, pedro.damage, pedro.line, pedro.column);

    player tulio;
    tulio.experience = 0; // inicializamos a experiência como 0

    /// INVERTER O X E O Y DEU CERTO????
    scanf("%s %u %u %d %d", tulio.class, &tulio.damage, &tulio.life, &tulio.line, &tulio.column); // Registramos os dados de Túlio

    // Salvamos os dados que serão reiniciados no caso de uma derrota
    tulio.initial.life = tulio.life;
    tulio.initial.line = tulio.line;
    tulio.initial.column = tulio.column;
    tulio.initial.name = 'T';

    printf("Túlio | %s\t%u\t%u [%d, %d]\n", tulio.class, tulio.life, tulio.damage, tulio.line, tulio.column);

    // Inicializamos o mapa da floresta
    int forest_size;
    scanf("%d", &forest_size);

    printf("\nMAPA DA FLORESTA %dx%d:\n", forest_size, forest_size);

    int forest[forest_size][forest_size];

    for (int line = 0; line < forest_size; line++)
    {
        for (int column = 0; column < forest_size; column++)
        {
            // Registramos o id do monstro na posição atual da floresta (ou -1 caso não tenha monstro)
            scanf("%d", &forest[line][column]);
        }
    }
    // forest_map(forest_size, forest, pedro.line, pedro.column, "P");
    forest_map(forest_size, forest, pedro, tulio);

    int rounds_amount;
    scanf("%d", &rounds_amount);
    printf("\nQuantidade de rodadas: %d\n", rounds_amount);

    int movements[rounds_amount][2]; // [rodada][jogador (0 = pedro, 1 = tulio))]

    for (int round = 0; round < rounds_amount; round++)
    {
        // Registramos os movimentos de cada jogador
        scanf("%d %d", &movements[round][0], &movements[round][1]);
        // printf("Rodada %d | Pedro: %d\tTúlio: %d\n", round, movements[round][0], movements[round][1]);
    }

    int defeated_monsters_amount_pedro = 0, defeated_monsters_amount_tulio = 0;

    int pedro_current_round = 0, tulio_current_round = 0;
    while (pedro_current_round < rounds_amount || tulio_current_round < rounds_amount)
    {
        // Primeiramente, fazemos a lógica de Pedro
        if (pedro_current_round < rounds_amount)
        {
            printf("\nPedro: (rodada %d)\n", pedro_current_round + 1);

            int tulio_pos[2] = {tulio.line, tulio.column}; // verificamos em que posição o outro jogador está
            // Tentamos colocar o personagem na "casa" para a qual ele se movimentou
            int is_invalid = move_player(movements[pedro_current_round][0], &pedro, forest_size, forest, tulio_pos);
            if (!is_invalid)
            {
                pedro_current_round++; // o jogador conseguiu se movimentar, então incrementamos sua rodada atual
                player_action(&pedro, forest_size, forest, monsters_amount, monsters, &defeated_monsters_amount_pedro);
                forest_map(forest_size, forest, pedro, tulio);
            }
        }

        // Em seguida, fazemos a lógica de Túlio
        if (tulio_current_round < rounds_amount)
        {
            printf("\nTúlio: (rodada %d)\n", tulio_current_round + 1);

            int pedro_pos[2] = {pedro.line, pedro.column}; // verificamos em que posição o outro jogador está
            // Tentamos colocar o personagem na "casa" para a qual ele se movimentou
            int is_invalid = move_player(movements[tulio_current_round][1], &tulio, forest_size, forest, pedro_pos);
            if (!is_invalid)
            {
                tulio_current_round++;
                player_action(&tulio, forest_size, forest, monsters_amount, monsters, &defeated_monsters_amount_tulio);
                forest_map(forest_size, forest, pedro, tulio);
            }
        }
    }

    printf("%d %d %d %d\n", pedro.life, pedro.initial.life, pedro.experience, defeated_monsters_amount_pedro);
    printf("%d %d %d %d\n", tulio.life, tulio.initial.life, tulio.experience, defeated_monsters_amount_tulio);

    return 0;
}