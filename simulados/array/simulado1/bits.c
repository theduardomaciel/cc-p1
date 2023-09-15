#include <stdio.h>

void request_input(int index, int size, int numeros[])
{
    if (index == size)
    {
        return;
    }

    scanf("%d", &numeros[index]);

    request_input(index + 1, size, numeros);
}

int frequencia(int array[], int index, int size, int frequencia_atual, int tamanho_maior_cadeia, int anterior)
{
    if (index == size)
    {
        return tamanho_maior_cadeia;
    }

    if (array[index] == anterior)
    {
        frequencia_atual = 1;
    }
    else
    {
        frequencia_atual++;
    }

    if (frequencia_atual > tamanho_maior_cadeia)
    {
        tamanho_maior_cadeia = frequencia_atual;
    }

    anterior = array[index];

    return frequencia(array, index + 1, size, frequencia_atual, tamanho_maior_cadeia, anterior);
}

void verificar_cadeias(int quant_grupos, int tamanho_maior_cadeia)
{
    if (quant_grupos == 0)
    {
        printf("%d\n", tamanho_maior_cadeia);
        return;
    }

    int tamanho_grupo;
    scanf("%d", &tamanho_grupo);

    int grupo[tamanho_grupo];
    request_input(0, tamanho_grupo, grupo);

    int nova_frequencia = frequencia(grupo, 0, tamanho_grupo, 0, tamanho_maior_cadeia, 0);

    if (tamanho_maior_cadeia < nova_frequencia)
    {
        tamanho_maior_cadeia = nova_frequencia;
    }

    verificar_cadeias(quant_grupos - 1, tamanho_maior_cadeia);
}

int main()
{
    int quant_grupos;
    scanf("%d", &quant_grupos);

    verificar_cadeias(quant_grupos, 0);

    return 0;
}