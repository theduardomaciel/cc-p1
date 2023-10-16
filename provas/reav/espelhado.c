#include <stdio.h>
#include <stdlib.h>

/*
    -> Descrição:
    Considere uma matriz quadrada de lado L, onde L > 1, onde:
        - as linhas são numeradas de cima para baixo a partir de 1
        - as colunas são numeradas da esquerda para a direita a partir de 1.

    As coordenadas nessa matriz são compostas pelo número da linha e da coluna.
    Por exemplo, a coordenada (3,5) é localizada na 3ª linha (y) e 5ª coluna (x).

    Agora, considere uma sequência de coordenadas nessa matriz.

    Sua tarefa é IMPRIMIR A SEQUÊNCIA ESPELHADA dessas coordenadas, como se houvesse um espelho no lado direito dessa matriz, usando as seguintes regras:
    Movimentos para cima e para baixo:
        -> NÃO SE ALTERAM na matriz espelhada.
    Movimentos para os lados direito e esquerdo:
        -> SE INVERTEM na matriz espelhada. (a inversão segue o seguinte padrão: 1 vira 3, 3 vira 1)

    O formato da entrada é o tamanho de um dos lados da matriz quadrada em uma linha e a sequência de coordenadas na linha seguinte, onde cada coordenada é informada entre parênteses (veja o exemplo da entrada).
    A saída deve ser a sequência de coordenadas espelhadas.

    -> Formato de entrada
    Um valor inteiro na primeira linha representando a quantidade de linhas ou colunas da matriz quadrada de lado L, onde L > 1, e uma sequência de coordenadas (mínimo de 1 coordenada).

    -> Formato de saída
    Sequência de coordenadas espelhadas.
*/

int main()
{
    int size;
    scanf("%d ", &size); // esse espaço faltando aqui me tomou um tempo...
    // printf("Tamanho: %d\n", size);

    // A contagem começa em 1, não em 0 (🫠)
    for (int i = 1; i <= size * size; i++)
    {
        int number1, number2;
        char separator;

        int amount_of_inputs = scanf("(%d,%d)%c", &number1, &number2, &separator);
        // printf("amount_of_inputs: %d | separator: %c\n", amount_of_inputs, separator);

        if (amount_of_inputs >= 2 && separator != '\n')
        {
            // printf("\n%d e %d\n", number1, number2);

            // Imprimimos o primeiro valor normalmente e o segundo espelhado
            printf("(%d,%d)", number1, size + 1 - number2);

            // Adicionamos uma vírgula se o loop ainda não tiver chegado no fim
            if (amount_of_inputs == 3)
            {
                printf(",");
            }
        }
        else
        {
            // O input de coordenadas acabou, então podemos quebrar o loop
            // printf("loop chegou ao fim\n");
            break;
        }
    }

    printf("\n");

    return 0;
}