#include <stdio.h>

// Uma toca de toupeira é caracterizado por um conjunto de buracos interligados.
// Cada buraco tem exatamente uma ligação, essa ligação é única e sempre forma um ciclo.

void request_input(int array[], int index, int size)
{
    if (index == size)
    {
        return;
    }

    scanf("%d", &array[index]);

    return request_input(array, index + 1, size);
}

void verificar_toca(int ligacoes[], int *quant_tocas, int index, int size, int ignore)
{
    if (index == size)
    {
        return;
    }

    int new_index = ligacoes[index];

    if (ligacoes[index] == -1)
    {
        if (!ignore)
        {
            // printf("\t-> UMA TOCA FOI ENCONTRADA no buraco de index %d: o index seguinte (%d) será verificado\n", index, index + 1);
            *quant_tocas += 1;
        }

        // Como encontramos um elemento já visitado, mesmo que linearmente, checaremos o próximo index, ao invés do definido pelo ligacoes[index]
        new_index = index + 1;

        // Já que visitaremos um elemento linearmente na próxima iteração, devemos ignorar qualquer "toca" encontrada nesse período
        // Novas tocas só poderão ser encontradas ao se deparar com um "ligacoes[index]" diferente de -1, que levará a um novo index de maneira não linear
        ignore = 1;
    }
    else
    {
        // printf("Marcando que o buraco %d (index %d) já foi visitado: o index %d será verificado agora.\n", ligacoes[index], index, ligacoes[index]);
        ligacoes[index] = -1;
        ignore = 0;
    }

    return verificar_toca(ligacoes, quant_tocas, new_index, size, ignore);
}

/* void array_print(int index, int end, int array[])
{
    if (index == end)
    {
        printf("\n");
        return;
    }

    printf("%d", array[index]);

    return array_print(index + 1, end, array);
} */

int main()
{
    int quant_buracos;
    scanf("%d", &quant_buracos);

    int ligacoes[quant_buracos];
    request_input(ligacoes, 0, quant_buracos);

    int quant_tocas = 0;
    verificar_toca(ligacoes, &quant_tocas, 0, quant_buracos, 0);

    printf("%d\n", quant_tocas);

    return 0;
}