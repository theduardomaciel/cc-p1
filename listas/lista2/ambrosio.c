#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int codigo, quantidade;
    double preco;

    scanf("%d %d", &codigo, &quantidade);

    if (codigo == 1) {
        preco = 5.3;
    } else if (codigo == 2) {
        preco = 6.0;
    } else if (codigo == 3) {
        preco = 3.2;
    } else {
        preco = 2.5;
    }

    double total = preco * quantidade;

    // Caso o preço total seja superior a R$ 40 ou a quantidade de produtos seja maior ou igual a 15
    if (total >= 40 || quantidade >= 15) {
        printf("R$ %.2lf\n", total - ((15 / 100.0) * total));
    } else {
        printf("R$ %.2lf\n", total);
    }

	return 0;
}