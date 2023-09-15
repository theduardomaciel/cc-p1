#include <stdio.h>

#define LIN 5
#define COL 4

void ler_linha(float notas[LIN][COL], int coluna, int linha, int colunas)
{
    // condição de parada: quando não houver mais colunas
    if (coluna == colunas)
        return;

    scanf("%f", &notas[linha][coluna]);
    printf("Lido notas[%d][%d] = %f\n", linha, coluna, notas[linha][coluna]);

    ler_linha(notas, coluna + 1, linha, colunas);
}

void ler_matriz(float notas[LIN][COL], int linha, int quant_linhas, int colunas)
{
    // condição de parada: quando não houver mais linhas
    if (linha == quant_linhas)
        return;

    // ler a linha
    ler_linha(notas, 0, linha, colunas);

    // repetimos a função, mudando a linha e continuando a leitura
    ler_matriz(notas, linha + 1, quant_linhas, colunas);
}
int main()
{
    float notas[LIN][COL];

    ler_matriz(notas, 0, LIN, COL);
    return 0;
}