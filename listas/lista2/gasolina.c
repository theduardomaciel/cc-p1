#include <stdio.h>

/* 
    Álcool:
        - até 20 litros, desconto de 3% por litro
        - acima de 20 litros, desconto de 5% por litro
    Gasolina:
        - até 20 litros, desconto de 4% por litro
        - acima de 20 litros, desconto de 6% por litro
    Diesel:
        - até 25 litros, não existe desconto
        - acima de 25 litros, desconto de 4% por litro
 */

int main() {
    double quantidade_combustivel;
    char tipo_combustivel;

    scanf("%lf", &quantidade_combustivel);
    scanf(" %c", &tipo_combustivel);

    double preco_A = 1.9;
    double preco_G = 2.5;
    double preco_D = 1.66;

    // A em ASCII: 65
    if (tipo_combustivel == 65) {
        double preco_final_A;

        if (quantidade_combustivel <= 20) {
            preco_final_A = preco_A - (preco_A * 0.03);
        } else {
            preco_final_A = preco_A - (preco_A * 0.05);
        }

        printf("R$ %.2lf\n", preco_final_A * quantidade_combustivel);
    // G em ASCII: 71
    } else if (tipo_combustivel == 71) {
        double preco_final_G;

        if (quantidade_combustivel <= 20) {
            preco_final_G = preco_G - (preco_G * 0.04);
        } else {
            preco_final_G = preco_G - (preco_G * 0.06);
        }

        printf("R$ %.2lf\n", preco_final_G * quantidade_combustivel);
    // A em ASCII: 68
    } else if (tipo_combustivel == 68) {
        double preco_final_D;

        if (quantidade_combustivel <= 25) {
            preco_final_D = preco_D;
        } else {
            preco_final_D = preco_D - (preco_D * 0.04);
        }

        printf("R$ %.2lf\n", preco_final_D * quantidade_combustivel);
    }

    return 0;
}