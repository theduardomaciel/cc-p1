#include <stdio.h>
#include <stdlib.h>

/*
    Descrição
    Leia duas strings e verifique o número de ocorrências da segunda string na primeira.
        Exemplo: Se a primeira string digitada for "abracadabra" e a segunda "bra", então o número de ocorrências é 2.

    Formato de entrada
    Você receberá duas linhas. Cada linha com uma string.

    Formato de saída
    Você deve imprimir um número inteiro indicando o número de ocorrências encontradas.
        Imprima também o final de linha.
*/

// Como não podemos utilizar a biblioteca <string.h>, realizamos a contagem de caracteres manualmente (🫠)
int custom_strlen(char *string)
{
    int size = 0;

    // Enquanto o caractere atual da string não for o caractere nulo ('\0'), continuamos percorrendo a string
    while (*string != '\0')
    {
        size++;    // Incrementamos o tamanho da string
        *string++; // Avançamos para o próximo caractere na string

        // deve dar pra simplificar isso aqui mas a preguiça bate mais forte...
    }

    return size; // Retornamos o tamanho da string com base na quantidade de caracteres encontrada
}

int main()
{
    char *string1 = (char *)malloc(1000000 * sizeof(char));
    gets(string1);

    char *string2 = (char *)malloc(1000000 * sizeof(char));
    gets(string2);

    int substrings_amount = 0;

    int string_length = custom_strlen(string1);
    int substring_length = custom_strlen(string2);

    // printf("Tamanho da string 1: %d\n", custom_strlen(string1));
    // printf("Tamanho da string 2: %d\n", custom_strlen(string2));

    int substring_index = 0;
    for (int search_index = 0; search_index < string_length; search_index++)
    {
        if (substring_index < substring_length && string1[search_index] == string2[substring_index])
        {
            // printf("(i: %d | substring_i: %d) Caractere 1: %c | Caractere 2: %c\n", search_index, substring_index, string1[search_index], string2[substring_index]);
            // printf("\t-> Encontrado caractere da substring!\n");
            substring_index++;
        }
        else
        {
            // printf("\t-> A corrente da substring foi quebrada. Reiniciando contagem...\n");
            if (substring_index == substring_length)
            {
                // printf("Fim de substring encontrada!\n");
                substrings_amount++;
            }

            substring_index = 0;

            // printf("(i: %d | substring_i: %d) Caractere 1: %c | Caractere 2: %c\n", search_index, substring_index, string1[search_index], string2[substring_index]);

            if (string1[search_index] == string2[substring_index])
            {
                // printf("\t-> Encontrado caractere da substring!\n");
                substring_index++;
            }
        }
    }

    // printf("Actual: %d\n", substring_index);
    //  Caso o loop acabe com o fim de uma substring, somamos essa substring ao total
    if (substring_index == substring_length)
    {
        // printf("Adicionando uma extra pois a substring está no final\n");
        substrings_amount++;
    }

    printf("%d\n", substrings_amount);

    return 0;
}