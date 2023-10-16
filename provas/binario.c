#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// O robô funciona apenas com números binários na hora de fazer a soma e também retorna um número binário.
// Então, você receberá [dois números binários de N dígitos] e dará [um número binário também de N dígitos que é o resultado da soma]
// Note que se o resultado da soma ultrapassar um número binário de N dígitos (Exemplo: 1 0 0 + 1 0 0 = 1 0 0 0), o robô exibe a mensagem "OVERFLOW".

/*
    Número 1:   0 1 0 1 1
    Número 2:   1 0 0 0 1
    Resultado:  1 1 1 0 0

    Exemplo: Se N for 5, o número binário pode ser 1 0 1 0 0
*/

// DICA: Faça a matemática da direita para a esquerda.

int somar_binarios(int index, int tamanho_inicial, int array_1[], int array_2[], int binario_final[], int tamanho_binario_final, int precisa_somar_1)
{
    if (index == 0)
    {
        if (precisa_somar_1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int index_real = index - 1;

    // printf("array 1: %d e array 2: %d\n", array_1[index_real], array_2[index_real]);

    // "Se ambos forem 0, o resultado é 0"
    if (array_1[index_real] == 0 && array_2[index_real] == 0)
    {
        // printf("Os dois dígitos são: igual a 0.\n");

        binario_final[tamanho_binario_final] = precisa_somar_1 ? 1 : 0;
        precisa_somar_1 = 0;
    }
    else if (array_1[index_real] == 1 && array_2[index_real] == 1)
    {
        //  "[...] se ambos forem 1, o resultado vai ser 0 mas a soma a esquerda vai receber mais 1."

        // printf("Os dois dígitos são: igual a 1, portanto, deve-se somar 1 ao próximo.\n");
        binario_final[tamanho_binario_final] = 0;
        precisa_somar_1 = 1;
    }
    else
    {
        //  [...] se tiver 1 e 0 o resultado é 1

        // printf("Os dois dígitos são: 1 ou 0, portanto, deve-se somar 1 ao próximo caso na iteração atual seja preciso somar um.\n");
        binario_final[tamanho_binario_final] = precisa_somar_1 ? 0 : 1;
    }

    tamanho_binario_final++;

    if (tamanho_binario_final > tamanho_inicial)
    {
        return 0;
    }

    somar_binarios(index - 1, tamanho_inicial, array_1, array_2, binario_final, tamanho_binario_final, precisa_somar_1);
}

void array_print(int index, int end, int array_numeros[])
{
    if (index == 0)
    {
        return;
    }

    printf("%d", array_numeros[index - 1]);

    if (index != 1)
    {
        printf(" ");
    }

    return array_print(index - 1, end, array_numeros);
}

void request_input(int index, int amount, int array[])
{
    if (index == amount)
    {
        return;
    }

    scanf("%d", &array[index]);

    request_input(index + 1, amount, array);
}

int main()
{
    int tamanho;
    scanf("%d", &tamanho);

    int binario_final[tamanho];
    int tamanho_binario_final = 0;

    int array1[tamanho], array2[tamanho];
    request_input(0, tamanho, array1);
    request_input(0, tamanho, array2);

    /* printf("array 1: \n");
    array_print(0, tamanho, array1);

    printf("array 2: \n");
    array_print(0, tamanho, array2); */

    int sucesso = somar_binarios(tamanho, tamanho, array1, array2, binario_final, tamanho_binario_final, 0);

    array_print(0, tamanho, binario_final);

    if (!sucesso)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        array_print(tamanho, tamanho, binario_final);
        printf("\n");
    }

    return 0;
}