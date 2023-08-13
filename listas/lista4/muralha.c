#include <stdio.h>

// Determinar o número mínimo de moedas de prata que ele (Vaqueiro) precisa levar em sua jornada.

// Muralha é uma reta: y - x = 0
// Um dos reinos está na parte de baixo (inferior) da reta (região em que y < x) e outro na parte de cima (superior) da reta (região em que y > x)

// Os guardas cobram 1 moeda de prata para cada viajante que deseja atravessar a muralha
// Vaqueiro irá começar sua jornada na posição (0, 0)
/*
    A cada movimento ele pode ir:
    -> para direita, 'D', e sair da posição (x, y) para posição (x + 1, y)
    -> para cima, 'C', e sair da posição (x, y) para posição (x, y + 1)
*/

/*
    Entrada:
    - número inteiro positivo N <= 100000, indicando o numero de dias da viagem
    - N linhas, cada uma contendo um caractere 'D', ou 'C', indicando que naquele dia Vaqueiro realizará um movimento para direita ou para cima.

    Saída:
    - o número necessário de moedas para Vaqueiro terminar sua viagem (quantas vezes Vaqueiro vai atravessar a reta y - x = 0 durante sua viagem)

    Observações:
    1. caso Vaqueiro apenas chegue na muralha, mas retorne em seguida para o mesmo reino em que já se encontrava, ele não deverá pagar nenhuma moeda para os guardas.
    2. no início, Vaqueiro já está do lado correto da muralha, ou seja, ele não precisará pagar nenhuma moeda de prata no seu primeiro dia de viagem.
 */

int viagem(int quant_dias, int x, int y, int quant_moedas, int ultimo_movimento)
{
    if (quant_dias > 0)
    {
        char direcao;
        scanf(" %c", &direcao);

        // Temos que verificar se x e y são diferentes de 0 (não estamos na primeira viagem) para atender à Observação 2
        // Só podemos dizer que Vaqueiro passou pela muralha, atendendo à Observação 1, se ele realizar o mesmo movimento que realizou anteriormente, visto que a muralha se encontra na diagonal
        if (x != 0 && y != 0 && y - x == 0 && direcao == ultimo_movimento)
        {
            quant_moedas += 1;
        }

        if (direcao == 'C')
        {
            return viagem(quant_dias - 1, x, y + 1, quant_moedas, direcao);
        }
        else if (direcao == 'D')
        {
            return viagem(quant_dias - 1, x + 1, y, quant_moedas, direcao);
        }
    }
    else
    {
        return quant_moedas;
    }
}

int main()
{
    int quant_dias;
    scanf("%d", &quant_dias);

    printf("%d\n", viagem(quant_dias, 0, 0, 0, 0));

    return 0;
}