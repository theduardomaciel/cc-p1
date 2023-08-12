#include <stdio.h>

int main() {
    double lado1, lado2, lado3;

    scanf("%lf %lf %lf", &lado1, &lado2, &lado3);

    int quantidade_de_lados_iguais = 0;

    if (lado1 == lado2 || lado1 == lado3) {
        quantidade_de_lados_iguais = quantidade_de_lados_iguais + 1;
    }
    
    if (lado2 == lado1 || lado2 == lado3) {
        quantidade_de_lados_iguais = quantidade_de_lados_iguais + 1;
    }

    if (lado3 == lado1 || lado3 == lado2) {
        quantidade_de_lados_iguais = quantidade_de_lados_iguais + 1;
    }

    if (quantidade_de_lados_iguais == 3) {
        printf("equilatero\n");
    } else if (quantidade_de_lados_iguais == 2) {
        printf("isosceles\n");
    } else {
        printf("escaleno\n");
    }

    return 0;
}