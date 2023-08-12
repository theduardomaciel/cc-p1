#include <stdio.h>

// banda com 7 integrantes
// todos os dias da semana há um ensaio na cada de um integrante diferente
// Pedro, Túlio, Gabriel, Yanka, Paloma, Vinicius e Elias

int x_pedro = 0, y_pedro = 0;
int x_tulio = 0, y_tulio = 3;
int x_gabriel = 0, y_gabriel = 5;
int x_yanka = 2, y_yanka = 3;
int x_paloma = 3, y_paloma = 4;
int x_vinicius = 4, y_vinicius = 3;
int x_elias = 5, y_elias = 5;

int casa1_x = 1, casa1_y = 4;
int casa2_x = 1, casa2_y = 0;
int casa3_x = 5, casa3_y = 0;

#define valor_unidade 100;

int distancia(int x1, int y1, int x2, int y2)
{
    int x = x2 - x1;
    if (x < 0)
    {
        x = x * -1;
    }

    int y = y2 - y1;
    if (y < 0)
    {
        y = y * -1;
    }

    int valor_da_distancia = (x + y) * valor_unidade;
    return valor_da_distancia * 2;
}

int main()
{
    int distancia_pedro, distancia_tulio, distancia_gabriel, distancia_yanka, distancia_paloma, distancia_vinicius, distancia_elias;

    scanf("%d %d %d %d %d %d %d", &distancia_pedro, &distancia_tulio, &distancia_gabriel, &distancia_yanka, &distancia_paloma, &distancia_vinicius, &distancia_elias);

    // era ida E VOLTA kodsjasioduhjasuidahsd asdsioj

    // Dia 1: Pedro
    distancia_tulio -= distancia(x_pedro, y_pedro, x_tulio, y_tulio);
    distancia_gabriel -= distancia(x_pedro, y_pedro, x_gabriel, y_gabriel);
    distancia_yanka -= distancia(x_pedro, y_pedro, x_yanka, y_yanka);
    distancia_paloma -= distancia(x_pedro, y_pedro, x_paloma, y_paloma);
    distancia_vinicius -= distancia(x_pedro, y_pedro, x_vinicius, y_vinicius);
    distancia_elias -= distancia(x_pedro, y_pedro, x_elias, y_elias);

    // printf("Após dia 1:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // é nesses momentos que você fica triste por não poder usar um loop...
    // Dia 2: Túlio
    distancia_pedro -= distancia(x_tulio, y_tulio, x_pedro, y_pedro);
    distancia_gabriel -= distancia(x_tulio, y_tulio, x_gabriel, y_gabriel);
    distancia_yanka -= distancia(x_tulio, y_tulio, x_yanka, y_yanka);
    distancia_paloma -= distancia(x_tulio, y_tulio, x_paloma, y_paloma);
    distancia_vinicius -= distancia(x_tulio, y_tulio, x_vinicius, y_vinicius);
    distancia_elias -= distancia(x_tulio, y_tulio, x_elias, y_elias);

    // printf("Após dia 2:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // Dia 3: Gabriel
    distancia_tulio -= distancia(x_gabriel, y_gabriel, x_tulio, y_tulio);
    distancia_pedro -= distancia(x_gabriel, y_gabriel, x_pedro, y_pedro);
    distancia_yanka -= distancia(x_gabriel, y_gabriel, x_yanka, y_yanka);
    distancia_paloma -= distancia(x_gabriel, y_gabriel, x_paloma, y_paloma);
    distancia_vinicius -= distancia(x_gabriel, y_gabriel, x_vinicius, y_vinicius);
    distancia_elias -= distancia(x_gabriel, y_gabriel, x_elias, y_elias);

    // printf("Após dia 3:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // Dia 4: Yanka
    distancia_gabriel -= distancia(x_yanka, y_yanka, x_gabriel, y_gabriel);
    distancia_tulio -= distancia(x_yanka, y_yanka, x_tulio, y_tulio);
    distancia_pedro -= distancia(x_yanka, y_yanka, x_pedro, y_pedro);
    distancia_paloma -= distancia(x_yanka, y_yanka, x_paloma, y_paloma);
    distancia_vinicius -= distancia(x_yanka, y_yanka, x_vinicius, y_vinicius);
    distancia_elias -= distancia(x_yanka, y_yanka, x_elias, y_elias);

    // printf("Após dia 4:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // Dia 5: Paloma
    distancia_yanka -= distancia(x_paloma, y_paloma, x_yanka, y_yanka);
    distancia_gabriel -= distancia(x_paloma, y_paloma, x_gabriel, y_gabriel);
    distancia_tulio -= distancia(x_paloma, y_paloma, x_tulio, y_tulio);
    distancia_pedro -= distancia(x_paloma, y_paloma, x_pedro, y_pedro);
    distancia_vinicius -= distancia(x_paloma, y_paloma, x_vinicius, y_vinicius);
    distancia_elias -= distancia(x_paloma, y_paloma, x_elias, y_elias);

    // printf("Após dia 5:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // Dia 6: Vinicius
    distancia_paloma -= distancia(x_vinicius, y_vinicius, x_paloma, y_paloma);
    distancia_yanka -= distancia(x_vinicius, y_vinicius, x_yanka, y_yanka);
    distancia_gabriel -= distancia(x_vinicius, y_vinicius, x_gabriel, y_gabriel);
    distancia_tulio -= distancia(x_vinicius, y_vinicius, x_tulio, y_tulio);
    distancia_pedro -= distancia(x_vinicius, y_vinicius, x_pedro, y_pedro);
    distancia_elias -= distancia(x_vinicius, y_vinicius, x_elias, y_elias);

    // printf("Após dia 6:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // Dia 7: Elias
    distancia_vinicius -= distancia(x_elias, y_elias, x_vinicius, y_vinicius);
    distancia_paloma -= distancia(x_elias, y_elias, x_paloma, y_paloma);
    distancia_yanka -= distancia(x_elias, y_elias, x_yanka, y_yanka);
    distancia_gabriel -= distancia(x_elias, y_elias, x_gabriel, y_gabriel);
    distancia_tulio -= distancia(x_elias, y_elias, x_tulio, y_tulio);
    distancia_pedro -= distancia(x_elias, y_elias, x_pedro, y_pedro);

    // printf("Após dia 7:\n");
    // printf("Pedro: %d\n", distancia_pedro);

    // printf("Pedro: %d\n Tulio: %d\n Gabriel: %d\n Yanka: %d\n Paloma: %d\n Vinicius: %d\n Elias: %d\n", distancia_pedro, distancia_tulio, distancia_gabriel, distancia_yanka, distancia_paloma, distancia_vinicius, distancia_elias);

    // Caso essa limitação seja ultrapassada, o integrante que ultrapassou o limite não irá se apresentar no show.
    // "No último dia da semana, ou seja, sábado, além do ensaio, Pedro e seus amigos farão uma apresentação na casa de show onde terá o maior pagamento acumulado."
    // Resumindo, depois de todos os ensaios, eles irão para a casa de shows em que a maior quantidade de integrantes da banda puder comparecer.
    // Para isso, precisamos verificar qual casa comportará mais integrantes com base na distância e no limite restante deles
    // detalhe! não podemos atualizar o valor da distância pessoal de cada um pois iremos realizar diversas verificações

    int integrantes_permitidos_casa1 = 0;

    // de novo, a dor por não poder usar um loop...
    if (distancia_pedro - distancia(casa1_x, casa1_y, x_pedro, y_pedro) >= 0)
    {
        /* printf("Pedro pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_pedro - distancia(casa1_x, casa1_y, x_pedro, y_pedro)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_tulio - distancia(casa1_x, casa1_y, x_tulio, y_tulio) >= 0)
    {
        /* printf("Tulio pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_tulio - distancia(casa1_x, casa1_y, x_tulio, y_tulio)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_gabriel - distancia(casa1_x, casa1_y, x_gabriel, y_gabriel) >= 0)
    {
        /* printf("Gabriel pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_gabriel - distancia(casa1_x, casa1_y, x_gabriel, y_gabriel)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_yanka - distancia(casa1_x, casa1_y, x_yanka, y_yanka) >= 0)
    {
        /* printf("Yanka pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_yanka - distancia(casa1_x, casa1_y, x_yanka, y_yanka)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_paloma - distancia(casa1_x, casa1_y, x_paloma, y_paloma) >= 0)
    {
        /* printf("Paloma pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_paloma - distancia(casa1_x, casa1_y, x_paloma, y_paloma)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_vinicius - distancia(casa1_x, casa1_y, x_vinicius, y_vinicius) >= 0)
    {
        /* printf("Vinicius pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_vinicius - distancia(casa1_x, casa1_y, x_vinicius, y_vinicius)); */
        integrantes_permitidos_casa1 += 1;
    }

    if (distancia_elias - distancia(casa1_x, casa1_y, x_elias, y_elias) >= 0)
    {
        /* printf("Elias pode ir para a casa 1\n");
        printf("Distância: %d\n", distancia_elias - distancia(casa1_x, casa1_y, x_elias, y_elias)); */
        integrantes_permitidos_casa1 += 1;
    }

    /* === */

    int integrantes_permitidos_casa2 = 0;

    // de novo, a dor por não poder usar um loop...
    if (distancia_pedro - distancia(casa2_x, casa2_y, x_pedro, y_pedro) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_tulio - distancia(casa2_x, casa2_y, x_tulio, y_tulio) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_gabriel - distancia(casa2_x, casa2_y, x_gabriel, y_gabriel) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_yanka - distancia(casa2_x, casa2_y, x_yanka, y_yanka) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_paloma - distancia(casa2_x, casa2_y, x_paloma, y_paloma) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_vinicius - distancia(casa2_x, casa2_y, x_vinicius, y_vinicius) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    if (distancia_elias - distancia(casa2_x, casa2_y, x_elias, y_elias) >= 0)
    {
        integrantes_permitidos_casa2 += 1;
    }

    /* === */

    int integrantes_permitidos_casa3 = 0;

    // de novo, a dor por não poder usar um loop...
    if (distancia_pedro - distancia(casa3_x, casa3_y, x_pedro, y_pedro) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_tulio - distancia(casa3_x, casa3_y, x_tulio, y_tulio) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_gabriel - distancia(casa3_x, casa3_y, x_gabriel, y_gabriel) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_yanka - distancia(casa3_x, casa3_y, x_yanka, y_yanka) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_paloma - distancia(casa3_x, casa3_y, x_paloma, y_paloma) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_vinicius - distancia(casa3_x, casa3_y, x_vinicius, y_vinicius) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    if (distancia_elias - distancia(casa3_x, casa3_y, x_elias, y_elias) >= 0)
    {
        integrantes_permitidos_casa3 += 1;
    }

    // printf("Integrantes Casa 1: %d\n Integrantes Casa 2: %d\n Integrantes Casa 3: %d\n", integrantes_permitidos_casa1, integrantes_permitidos_casa2, integrantes_permitidos_casa3);

    // Verificamos qual casa pagará melhor
    // Observação: No caso de ter casas de show's diferentes pagando o mesmo valor, o critério de desempate será a quantidade de integrantes que irão se apresentar, ou seja, deverá ser pego a casa de show onde irá mais integrantes.
    int valor_casa1 = 10 * integrantes_permitidos_casa1;
    int valor_casa2 = 20 * integrantes_permitidos_casa2;
    int valor_casa3 = 30 * integrantes_permitidos_casa3;

    // printf("Valor Casa 1: %d\n Valor Casa 2: %d\n Valor Casa 3: %d\n", valor_casa1, valor_casa2, valor_casa3);

    if (integrantes_permitidos_casa1 == 0 && integrantes_permitidos_casa2 == 0 && integrantes_permitidos_casa3 == 0)
    {
        printf("NAO TERA SHOW!");
    }
    else if (valor_casa1 >= valor_casa2 && valor_casa1 >= valor_casa3)
    {
        printf("CASA 1\n%d\n%d\n", valor_casa1, integrantes_permitidos_casa1);
    }
    else if (valor_casa2 >= valor_casa3)
    {
        printf("CASA 2\n%d\n%d\n", valor_casa2, integrantes_permitidos_casa2);
    }
    else
    {
        printf("CASA 3\n%d\n%d\n", valor_casa3, integrantes_permitidos_casa3);
    }

    return 0;
}