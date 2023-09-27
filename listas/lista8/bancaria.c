#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// O programa aceita até 100 operações de crédito e débito.
/*
    O programa deve obrigatoriamente ser dividido em 3 partes que:
        1 - Lê as operações de uma vez salvando-as em um array com duas dimensões (operação e valor);
        2 - Varre o array executando as operações;
        3 - Imprime um resumo com os totais de valores a) creditados, b) debitados, e c) o saldo final resultante.

    Todas as operações são executadas em uma mesma conta bancária. O saldo inicial da conta é zero.
*/

/*
    ENTRADA:
        Uma sequência de até 100 linhas, cada uma contendo dois valores.
        O primeiro (do tipo int) indica as operações de crédito (1) ou débito (0).
        O segundo (do tipo double) representa o valor a ser utilizado na operação.
        O que define o final da lista de operações é uma linha adicional, contendo apenas o valor int -1. Esta linlha final não deve ser armazenada no array.
*/

int main()
{
    double balance = 0; // saldo

    double operations[100][2];

    int operation = 0;
    double value = 0;

    int operations_amount = 0;

    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &operation);

        // Caso a operação seja -1, paramos de ler as operações.
        if (operation == -1)
            break;

        scanf(" %lf", &value);

        operations[i][operation] = value;
        operations_amount++;
    }

    double credit = 0;
    double debit = 0;

    for (int i = 0; i < operations_amount; i++)
    {
        balance += operations[i][1];
        credit += operations[i][1];

        balance -= operations[i][0];
        debit += operations[i][0];
    }

    printf("Creditos: R$ %.2lf\n", credit);
    printf("Debitos: R$ %.2lf\n", debit);
    printf("Saldo: R$ %.2lf\n", balance);

    return 0;
}