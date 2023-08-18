#include <stdio.h>

/*
    Nosredna começa com um número específico e, passo a passo, escolhe outro número para combiná-lo com o número gerado anteriormente (ambos os números são sempre inteiros positivos)
    Este processo é repetido N vezes, seguindo um conjunto específico de regras em ordem. Apenas uma regra é aplicada por vez, na sequência abaixo:
        1 - Se ambos os números, a e b, forem primos, ele os soma.
        2 - Se a e b não forem primos, ele faz o somatório dos dígitos de cada um e os multiplica.

    -> Formato de entrada
        linha 1: Um inteiro N, representando o número de vezes que Nosredna irá combinar os números.
        linha 2: Um inteiro I, representando o valor inicial escolhido por Nosredna.
        linha 3: Em seguida, uma sequência de N números a serem combinados.

    -> Formato de saída
        O número finalmente gerado após todas as combinações.
*/

int primo(int num, int divisor)
{
    // Caso base: se o divisor se tornar 1, o número é primo
    if (divisor == 1)
    {
        return 1; // Verdadeiro (primo)
    }

    // Se o número é divisível pelo divisor atual, não é primo
    if (num % divisor == 0)
    {
        return 0; // Falso (não é primo)
    }

    // Chama a função recursivamente com o próximo divisor
    return primo(num, divisor - 1);
}

int eh_primo(int num)
{
    // Trata o caso especial para números menores que 2
    if (num <= 1)
    {
        return 0; // Falso (não é primo)
    }

    // Inicia a verificação recursiva a partir do divisor máximo (num - 1)
    return primo(num, num - 1);
}

int somatorio(int num)
{
    if (num == 0)
    {
        return 0; // Caso base: quando o número é zero, o somatório é zero
    }
    else
    {
        return (num % 10) + somatorio(num / 10); // Somar o último dígito e chamar a função para o resto do número
    }
}

void combinacao(int quant_combinacoes, int valor_anterior, int combinacao_atual)
{
    if (combinacao_atual < quant_combinacoes)
    {
        int novo_numero;
        scanf("%d", &novo_numero);

        if (eh_primo(novo_numero) && eh_primo(valor_anterior))
        {
            int nova_combinacao = novo_numero + valor_anterior;
            return combinacao(quant_combinacoes, nova_combinacao, combinacao_atual + 1);
        }
        else
        {
            int nova_combinacao = somatorio(novo_numero) * somatorio(valor_anterior);
            return combinacao(quant_combinacoes, nova_combinacao, combinacao_atual + 1);
        }
    }
    else
    {
        printf("%d\n", valor_anterior);
    }
}

int main()
{
    int quant_combinacoes, valor_inicial;
    scanf("%d %d", &quant_combinacoes, &valor_inicial);

    combinacao(quant_combinacoes, valor_inicial, 0);

    return 0;
}