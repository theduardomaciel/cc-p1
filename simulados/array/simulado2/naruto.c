#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void obter_input(int index, int end, int array[])
{
    if (index == end)
    {
        return;
    }

    int novo_input;
    scanf("%d", &novo_input);

    array[index] = novo_input;

    return obter_input(index + 1, end, array);
}

// Marquinhos só consegue derrotar um ninja que possui energia vital inferior ou igual a dele;
// Ao avistar alguém com nível acima, ele foge! (ou seja, não haverá luta contra tal ninja)

// Marquinhos ganha a diferença de energia vital entre ele e o inimigo ao derrotá-lo

void batalha(int *energia_marquinhos, int energia_inimigo, int *quant_inimigos_derrotados)
{
    if (energia_inimigo > *energia_marquinhos)
    {
        return;
    }

    *energia_marquinhos = *energia_marquinhos + (*energia_marquinhos - energia_inimigo);
    *quant_inimigos_derrotados += 1;
}

void rodar_batalhas(int index, int quant_inimigos, int *quant_inimigos_derrotados, int *energia_marquinhos, int energia_inimigos[], int ordem_inimigos[])
{
    if (index == quant_inimigos)
    {
        return;
    }

    // printf("Energia atual de marquinhos: %d e energia do inimigo atual (ordem %d): %d\n", *energia_marquinhos, ordem_inimigos[index], energia_inimigos[ordem_inimigos[index] - 1]);
    batalha(energia_marquinhos, energia_inimigos[ordem_inimigos[index] - 1], quant_inimigos_derrotados);

    return rodar_batalhas(index + 1, quant_inimigos, quant_inimigos_derrotados, energia_marquinhos, energia_inimigos, ordem_inimigos);
}

int main()
{
    int energia_marquinhos, quant_inimigos;
    scanf("%d %d", &energia_marquinhos, &quant_inimigos);

    int energia_inimigos[quant_inimigos];
    memset(energia_inimigos, 0x00, sizeof(energia_inimigos));
    obter_input(0, quant_inimigos, energia_inimigos);

    int ordem_inimigos[quant_inimigos];
    memset(ordem_inimigos, 0x00, sizeof(ordem_inimigos));
    obter_input(0, quant_inimigos, ordem_inimigos);

    // printf("ORDEM DOS INIMIGOS: \n");
    // array_print(0, quant_inimigos, ordem_inimigos);

    int quant_inimigos_derrotados = 0;
    rodar_batalhas(0, quant_inimigos, &quant_inimigos_derrotados, &energia_marquinhos, energia_inimigos, ordem_inimigos);

    printf("Nível de energia: %d\n", energia_marquinhos);
    printf("%.2lf%%\n", (double)(quant_inimigos_derrotados * 100) / quant_inimigos);

    if (energia_marquinhos > 20000)
    {
        printf("Marquinhos é o novo Mestre da Vila da Árvore!\n");
    }
    else
    {
        printf("Continue tentando!\n");
    }

    return 0;
}