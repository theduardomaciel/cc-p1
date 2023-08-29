#include <stdio.h>
#include <stdlib.h>

void comparation(int array[4], int posicao)
{
    if (posicao < sizeof(*array))
    {
        // printf("Verificando se %d é maior que %d\n", array[posicao], array[posicao + 1]);

        // Verificamos elemento por elemento da array e vamos atualizando o valor do maior e do menor
        int atual = array[posicao];
        int proximo = posicao == sizeof(*array) - 1 ? array[2] : array[posicao + 1]; // temos que tomar cuidado com o último elemento da array, pois ele não possui próximo

        // maior
        if (array[posicao] > proximo)
        {
            // printf("Sim, %d é o novo maior\n", atual);
            array[posicao] = array[2];
            array[2] = atual;
        }

        // menor
        if (proximo < array[0])
        {
            // printf("e %d é o novo menor\n", proximo);
            array[posicao + 1] = array[0];
            array[0] = proximo;
        }

        return comparation(array, posicao + 1);
    }
    else
    {
        // printf("Maior: %d\n", array[2]);
        // printf("Menor: %d\n", array[0]);

        int index1 = array[1];
        int index3 = array[3];

        // Só precisamos descobrir quem são o segundo e o terceiro maior
        if (index1 > index3)
        {
            array[1] = index1;
            array[3] = index3;
        }
        else
        {
            array[1] = index3;
            array[3] = index1;
        }

        // Já temos os valores do maior e do menor
        return;
    }
}

void print_array(int index, int array[4])
{
    if (index < sizeof(*array))
    {
        printf("%.2lf\n", (double)array[index]);
        print_array(index + 1, array);
    }
    return;
}

int main()
{
    int num1, num2, num3, num4;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    int base_array[4] = {num1, num2, num3, num4};

    comparation(base_array, 0);

    print_array(0, base_array);

    return 0;
}