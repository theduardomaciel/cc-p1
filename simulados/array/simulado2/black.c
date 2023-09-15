#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void array_print(int index, int end, int array_numeros[])
{
    if (index == end)
    {
        printf("\n");
        return;
    }

    printf("%d", array_numeros[index]);

    // Não inserimos o espaço no final
    if (index != end - 1)
    {
        printf(" ");
    }

    return array_print(index + 1, end, array_numeros);
}

void swap(int *a, int *b)
{
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

void bubble(int array[], int array_size, int index, int isDescending)
{
    // Condição de parada: paramos sempre um elemento antes para evitar o overflow (acessar um elemento que não existe na array)
    if (index >= array_size - 1)
        return;

    // Se o elemento anterior for menor que o posterior, trocamos de lugar
    if (!isDescending && array[index] > array[index + 1] || isDescending && array[index] < array[index + 1])
    {
        swap(&array[index], &array[index + 1]);
    }

    return bubble(array, array_size, index + 1, isDescending);
}

// index = inicia no tamanho da array
void ordenar_array(int array[], int index, int isDescending)
{
    // Condição de parada: chegamos ao index 0, ou seja, percorremos toda a array
    if (index == 0)
        return;

    // Aplicamos o algoritmo bubble desde o elemento inicial (array[0]) ao elemento final.
    // Em razão da otimização, consideramos (array[index]) como elemento final, visto que os outros elementos já foram ordenados
    bubble(array, index, 0, isDescending);

    return ordenar_array(array, index - 1, isDescending);
}

/*
    -> O objetivo do jogo era achar o maior grupo de indivíduos suspeitos a partir dos depoimentos dos NPC's.
    Um grupo é considerado suspeito se uma testemunha disser que viu esse grupo cometendo o crime da história atual.

    Quando uma testemunha depõe, ela aponta o intervalo de indivíduos que foram vistos cometendo o crime e esses indivíduos somam um "ponto de suspeita".

    // SEM IMPORTÂNCIA PARA A QUESTÃO 🌈
    No fim do jogo, é verificado qual foi o maior ponto de suspeita e os grupos (intervalos) de indivíduos que possuem a maior ponto de suspeita são levados para prestar depoimento.

    Irá ganhar [aquele que apontar o grupo com o maior número de suspeita].
    Caso haja um empate (dois ou mais monitores apontaram grupos com a maior pontuação de suspeita), ganha aquele que escolher o grupo com o maior número de indivíduos com a maior pontuação de suspeita.
*/

/*
    -> SAÍDA:
        A primeira linha contém a [pontuação de cada individuo] separada por espaço (perceba que o ultimo não tem um espaço depois)
        A segunda linha contém a [maior pontuação de suspeito].

        As k linhas seguintes consistem dos grupos que houveram a maior pontuação de suspeita.

        Na linha seguinte ao ultimo intervalo de maior pontuação o tamanho da maior sequencia de indivíduos com a maior pontuação de suspeita, nas linhas abaixo (como descrito nos casos de exemplo), imprima o começo e o fim da referida sequencia.

    Obs: nunca haverá duas sequências com a maior pontuação e a maior quantidade de indivíduos.
*/

void depoimento(int L, int R, int pontuacao_suspeitos[])
{
    if (L > R)
    {
        return;
    }

    // printf("Incrementando 1 na pontuação do suspeito de index %d\n", L);
    pontuacao_suspeitos[L]++;

    return depoimento(L + 1, R, pontuacao_suspeitos);
}

/*
int maior_valor_do_array(int array[], int i, int n, int maior_valor)
{
    if (i == n) return maior_valor;

    if (array[i] > maior_valor) maior_valor = array[i];

    return maior_valor_do_array(array, i + 1, n, maior_valor);
}
*/

void obter_depoimentos(int quant_testemunhas, int pontuacao_suspeitos[])
{
    if (quant_testemunhas == 0)
    {
        return;
    }

    int L, R;
    scanf("%d %d", &L, &R);

    // array_print(0, 10, pontuacao_suspeitos);
    depoimento(L, R, pontuacao_suspeitos);

    return obter_depoimentos(quant_testemunhas - 1, pontuacao_suspeitos);
}

int imprimir_grupo(int index, int inicio, int quant_suspeitos, int pontuacao_suspeitos[], int maior_pontuacao, int maior_sequencia[])
{
    /* printf("index: %d de %d (iniciou em %d)\n", index, quant_suspeitos, inicio);
    printf("pontuação atual: %d e pontuação anterior: %d\n", pontuacao_suspeitos[index], pontuacao_suspeitos[index - 1]);
    printf("maior pontuação: %d\n", maior_pontuacao); */

    if (index == inicio)
    {
        if (pontuacao_suspeitos[index] != maior_pontuacao)
        {
            // printf("O elemento analisado não é o de maior pontuação. Verificando a partir do próximo index...\n---------------------------------------------------------------\n\n");
            return index;
        }
    }
    else
    {
        if (
            index == quant_suspeitos ||                                                // caso cheguemos ao fim da array, acabamos com o grupo
            index > 0 && pontuacao_suspeitos[index] != pontuacao_suspeitos[index - 1]) // caso a pontuação do suspeito atual seja diferente da pontuação do anterior, acabamos com o grupo
        {
            /* printf("1: %d\n", index == quant_suspeitos);
            printf("2: %d\n", pontuacao_suspeitos[index] != maior_pontuacao);
            printf("3: %d\n", index > 0 && pontuacao_suspeitos[index] != pontuacao_suspeitos[index - 1]);

            printf("FIM DE GRUPO\n\n"); */

            int fim = index - 1;
            printf("%d %d\n", inicio, fim);

            if (fim - inicio > maior_sequencia[1] - maior_sequencia[0])
            {
                maior_sequencia[0] = inicio;
                maior_sequencia[1] = fim;
            }

            return fim;
        }
    }

    // printf("CONTINUANDO GRUPO\n\n");
    return imprimir_grupo(index + 1, inicio, quant_suspeitos, pontuacao_suspeitos, maior_pontuacao, maior_sequencia);
}

void imprimir_grupos(int index, int quant_suspeitos, int pontuacao_suspeitos[], int maior_pontuacao, int maior_sequencia[])
{
    if (index == quant_suspeitos)
    {
        return;
    }

    int fim = imprimir_grupo(index, index, quant_suspeitos, pontuacao_suspeitos, maior_pontuacao, maior_sequencia);

    return imprimir_grupos(fim + 1, quant_suspeitos, pontuacao_suspeitos, maior_pontuacao, maior_sequencia);
}

int *intdup(int const *src, size_t len)
{
    int *p = malloc(len * sizeof(int));
    memcpy(p, src, len * sizeof(int));
    return p;
}

int main()
{
    int quant_suspeitos, quant_testemunhas;
    scanf("%d %d", &quant_suspeitos, &quant_testemunhas);

    int pontuacao_suspeitos[quant_suspeitos];
    memset(pontuacao_suspeitos, 0x00, sizeof(pontuacao_suspeitos));

    obter_depoimentos(quant_testemunhas, pontuacao_suspeitos);

    array_print(0, quant_suspeitos, pontuacao_suspeitos);

    // Ordenamos [uma nova] array (do menor para o maior) para obter o maior valor de suspeito
    int *pontuacao_suspeitos_ordenada = intdup(pontuacao_suspeitos, quant_suspeitos);
    ordenar_array(pontuacao_suspeitos_ordenada, quant_suspeitos, 0);

    int maior_pontuacao = pontuacao_suspeitos_ordenada[quant_suspeitos - 1];

    // printf("ARRAY DEPOIS DA ORDENAÇÃO: \n");
    // array_print(0, quant_suspeitos, pontuacao_suspeitos_ordenada);

    printf("%d\n", maior_pontuacao);

    int maior_sequencia[2] = {0, -1};
    imprimir_grupos(0, quant_suspeitos, pontuacao_suspeitos, maior_pontuacao, maior_sequencia);

    printf("maior sequencia: %d\n", maior_sequencia[1] - maior_sequencia[0] + 1);
    printf("comeca em: %d\n", maior_sequencia[0]);
    printf("termina em: %d\n", maior_sequencia[1]);

    return 0;
}