#include <stdio.h>

// N - valor inicial das camadas que serão iteradas (ex: se for 0, as adições começarão a partir de 0)
// T - camada (index) que eles se encontram (desejada), da qual o valor deverá ser retornado

int criar_serie(int index, int camada_atual, int camada_desejada, int valor_atual)
{
    if (camada_desejada == 0)
    {
        return valor_atual;
    }

    if (index == 0)
    {
        // Caso estejamos iterando um n?mero [ímpar], utilizaremos o primeiro caso do padrão: adicionar 3
        // printf("Somando 3... (camada atual = %d)\n", camada_atual);
        valor_atual += 3;
        index = 1;
    }
    else
    {
        // Caso contrário, utilizaremos o segundo caso do padrão: adicionar o resto da divis?o por 5 do numero anterior
        // printf("Somando o resto da divisão por 5 do número anterior (camada atual = %d)\n", camada_atual);
        valor_atual += (valor_atual % 5);
        index = 0;
    }

    // printf("Camada desejada: %d\n", camada_desejada);
    // printf("Valor atual: %d\n", valor_atual);

    // Iteramos enquanto o index do n?mero desejado n?o seja alcan?ado
    if (camada_atual + 1 < camada_desejada)
    {
        return criar_serie(index, camada_atual + 1, camada_desejada, valor_atual);
    }
    else
    {
        return valor_atual;
    }
}

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    printf("%d\n", criar_serie(0, 0, T, N));

    return 0;
}