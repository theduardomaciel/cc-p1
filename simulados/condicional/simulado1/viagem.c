#include <stdio.h>

int main() {
    double salario, tarifa_fixa, valor_km, distancia_km;
    int fim_de_semana;

    scanf("%lf %lf %lf %lf", &salario, &tarifa_fixa, &valor_km, &distancia_km);
    scanf("%d", &fim_de_semana);

    double gasto_max = (30.0 / 100.0) * salario;
    double tarifa_final = tarifa_fixa + (valor_km * distancia_km);

    // Como Pedro está viajando num final de semana, sua viagem sairá mais cara
    if (fim_de_semana) {
        tarifa_final = tarifa_final + ((10.0 / 100.0) * tarifa_final);
    } 

    // Caso a tarifa final exceda o gasto máximo estipulado por Pedro, ele não poderá realizar a viagem
    if (tarifa_final > gasto_max) {
        printf("Não vai poder viajar.\n");
        printf("%.2lf\n", tarifa_final - gasto_max);
    } else {
        // Caso contrário, ele está dentro do seu gasto estipulado
        printf("Vai poder viajar.\n");
        printf("%.2lf\n", tarifa_final);
        printf("%.2lf\n", gasto_max - tarifa_final);
    }

    return 0;
}