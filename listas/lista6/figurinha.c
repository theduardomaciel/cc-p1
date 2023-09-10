#include <stdio.h>

// João ficaria com todas as figurinhas cujo número de série for par e Maria com as ímpares.
// Aquele que obtivesse o MAIOR VALOR SOMANDO OS NÚMEROS DE SÉRIE das figurinhas ganharia como bônus mais R$10,00 reais para comprar figurinhas só para ele.

/*
    Todas as figurinhas possuem números de série diferentes.
    As figurinhas podem ser repetidas. Neste caso, só devemos considerar na soma do número de série uma única vez, mas contamos na quantidade de figurinhas.
*/

/*
    SAÍDA: números inteiros J, M e S,
        J: o número de figurinhas que ficaram com o João
        M: o número de figurinhas que ficaram com Maria
        S: soma dos números de série do irmão que ganhou o bônus do Sr. Carlos.
*/

void request_input(int quant_restante, int numeros[])
{
    if (quant_restante == 0)
    {
        return;
    }

    scanf("%d", &numeros[quant_restante - 1]);

    return request_input(quant_restante - 1, numeros);
}

int procurar_duplicata(int objetivo, int index, int size, int numeros_de_serie[])
{
    if (index == size)
    {
        return 0;
    }

    if (numeros_de_serie[index] == objetivo)
    {
        return 1;
    }

    return procurar_duplicata(objetivo, index + 1, size, numeros_de_serie);
}

void verificar_numeros_de_serie(int numeros_de_serie[], int index, int size, int figurinhas_joao[], int figurinhas_maria[], int figurinhas_sizes[2], int *quant_joao, int *quant_maria)
{
    if (index == size)
    {
        return;
    }

    if (numeros_de_serie[index] % 2 == 0)
    {
        int possuiDuplicata = procurar_duplicata(numeros_de_serie[index], 0, figurinhas_sizes[0], figurinhas_joao);
        if (!possuiDuplicata)
        {
            // printf("+ 1 figurinha para João (série %d)\n", numeros_de_serie[index]);
            figurinhas_joao[figurinhas_sizes[0]] = numeros_de_serie[index];
            figurinhas_sizes[0] += 1;
        }
        *quant_joao += 1;
    }
    else
    {
        int possuiDuplicata = procurar_duplicata(numeros_de_serie[index], 0, figurinhas_sizes[1], figurinhas_maria);
        if (!possuiDuplicata)
        {
            // printf("+ 1 figurinha para Maria (série %d)\n", numeros_de_serie[index]);
            figurinhas_maria[figurinhas_sizes[1]] = numeros_de_serie[index];
            figurinhas_sizes[1] += 1;
        }
        *quant_maria += 1;
    }

    return verificar_numeros_de_serie(numeros_de_serie, index + 1, size, figurinhas_joao, figurinhas_maria, figurinhas_sizes, quant_joao, quant_maria);
}

void realizar_somatorio(int array[], int index, int size, int *soma)
{
    if (index == size)
    {
        return;
    }

    *soma += array[index];

    return realizar_somatorio(array, index + 1, size, soma);
}

void array_print(int index, int end, int array_numeros[])
{
    if (index == end)
    {
        printf("\n");
        return;
    }

    printf("%d ", array_numeros[index]);

    return array_print(index + 1, end, array_numeros);
}

int main()
{
    int quant_figurinhas;
    scanf("%d", &quant_figurinhas);

    int numeros_de_serie[quant_figurinhas];
    request_input(quant_figurinhas, numeros_de_serie);

    // João = 0 e Maria = 1
    int figurinhas_joao[quant_figurinhas];
    int figurinhas_maria[quant_figurinhas];

    int figurinhas_sizes[2] = {0, 0};

    int quant_joao = 0, soma_joao = 0;
    int quant_maria = 0, soma_maria = 0;

    verificar_numeros_de_serie(numeros_de_serie, 0, quant_figurinhas, figurinhas_joao, figurinhas_maria, figurinhas_sizes, &quant_joao, &quant_maria);

    // array_print(0, quant_joao, figurinhas_joao);
    // printf("tamanho da array de João: %d\n", figurinhas_sizes[0]);

    realizar_somatorio(figurinhas_joao, 0, figurinhas_sizes[0], &soma_joao);
    realizar_somatorio(figurinhas_maria, 0, figurinhas_sizes[1], &soma_maria);

    // printf("--------------------------------\n");

    printf("%d\n", quant_joao);
    printf("%d\n", quant_maria);

    if (soma_joao > soma_maria)
    {
        printf("%d\n", soma_joao);
    }
    else
    {
        printf("%d\n", soma_maria);
    }

    return 0;
}