#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Se concordar votam 1, se não concordar votam 0, para cada princesa.

/*
    ENTRADA:
        A primeira linha da entrada é composta por um número natural P, referente a quantidade de princesas
        A segunda linha tem um número natural E, representando a quantidade de eleitores.

        Cada uma das próximas E linhas contém P números que podem ser 1 ou 0, separados por espaço. Essas linhas representam os votos de um eleitor. Em cada uma dessas linhas, os P números correspondem, em ordem as princesas 1, 2, 3,...,P.
*/

/*
    SAÍDA:
        A saída deve conter P linhas, uma para cada princesa, no seguinte formato:

        Princesa K: X voto(s)
        K representa o número da princesa e X a quantidade de votos da mesma. As linhas devem estar em ordem da princesa 1 até a princesa P.
*/

int main()
{
    int quant_princesas = 0;
    scanf("%d", &quant_princesas);

    int quant_eleitores = 0;
    scanf("%d", &quant_eleitores);

    int votos[quant_princesas][quant_eleitores];

    for (int i = 0; i < quant_eleitores; i++)
    {
        for (int j = 0; j < quant_princesas; j++)
        {
            scanf("%d", &votos[j][i]);
        }
    }

    for (int i = 0; i < quant_princesas; i++)
    {
        int total_votos = 0;
        for (int j = 0; j < quant_eleitores; j++)
        {
            total_votos += votos[i][j];
        }

        printf("Princesa %d: %d voto(s)\n", i + 1, total_votos);
    }

    return 0;
}