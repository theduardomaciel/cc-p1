#include <stdio.h>

int main() {
    double salario_antigo;

    scanf("%lf", &salario_antigo);

    int aumento_percentual;

    if (salario_antigo >= 1500.0) {
        aumento_percentual = 5;
    } else if (salario_antigo >= 700.0) {
        aumento_percentual = 10;
    } else if (salario_antigo > 280.0) {
        aumento_percentual = 15;
    } else {
        aumento_percentual = 20;
    }

    /* 
    - o salário antes do reajuste;
    - o percentual de aumento aplicado;
    - o valor do aumento;
    - o novo salário, após o aumento.
     */

    double aumento = salario_antigo * (aumento_percentual / 100.0);

    printf("%.2lf\n", salario_antigo);
    printf("%d\n", aumento_percentual);
    printf("%.2lf\n", aumento);
    printf("%.2lf\n", salario_antigo + aumento);

    return 0;
}