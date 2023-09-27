#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char *numberA_string = (char *)malloc(1000000 * sizeof(char));
    gets(numberA_string);

    char *numberB_string = (char *)malloc(1000000 * sizeof(char));
    gets(numberB_string);

    size_t length_A = strlen(numberA_string);
    size_t length_B = strlen(numberB_string);

    size_t base_size = length_A > length_B ? length_A : length_B;

    char *sum_string = (char *)malloc(base_size * sizeof(char) + 1);
    sum_string[base_size] = '\0';

    // printf("Tamanho da array da soma resultante: %ld\n", base_size);

    int carry = 0;

    for (int index = (base_size - 1); index >= 0; index--)
    {
        // printf("index: %d, length A: %d, length B: %d\n", index, length_A, length_B);

        int numberA = 0, numberB = 0;

        if (length_A > 0)
        {
            numberA = numberA_string[length_A - 1] - '0';
            length_A--;
        }

        if (length_B > 0)
        {
            numberB = numberB_string[length_B - 1] - '0';
            length_B--;
        }

        if (length_A > length_B)
        {
            numberA += carry;
        }
        else
        {
            numberB += carry;
        }

        // printf("A: %d, B: %d\n", numberA, numberB);

        if (numberA + numberB > 9)
        {
            // printf("A soma de %d (A) + %d (B) é maior que 9 (%d)\n", numberA, numberB, numberA + numberB);
            carry = 1;

            // Caso a soma seja maior, mantemos o último digito...
            sum_string[index] = ((numberA + numberB) % 10) + '0';
        }
        else
        {
            // printf("A soma de %d (A) + %d (B) é menor ou igual a 9 (%d)\n", numberA, numberB, numberA + numberB);
            carry = 0;

            // Caso não, somamos normalmente
            sum_string[index] = (numberA + numberB) + '0';
        }
        // printf("O valor de sum_string[%d] é %c\n", index, sum_string[index]);
        // printf("------------------------------------\n");
    }

    if (carry == 1)
    {
        char *carry_string = (char *)malloc(2 * sizeof(char)); // Array para o dígito extra
        carry_string[1] = '\0';                                // Null-terminate a string
        carry_string[0] = '1';

        // Concatamos o dígito extra na frente da soma
        char *result_string = (char *)malloc((base_size + 2) * sizeof(char));
        strcpy(result_string, carry_string); // Copiamos o dígito extra para a string final...
        strcat(result_string, sum_string);   // ...e concatenamos a soma atual à string final

        free(sum_string);

        sum_string = result_string; // Atribuímos o valor da string final à soma atual

        free(carry_string);
        // por algum motivo, o free() resultou em erro ao colocar os dois seguidos
    }

    puts(sum_string);

    free(numberA_string);
    free(numberB_string);
    free(sum_string);

    return 0;
}