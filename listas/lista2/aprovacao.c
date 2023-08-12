#include <stdio.h>

int main() {
    int quant_problemas, quant_resolvidos;

    scanf("%d %d", &quant_problemas, &quant_resolvidos);

    double percentual_cumprido = (quant_resolvidos * 100.0) / quant_problemas;

    // Calculando a chance de aprovação
    if (percentual_cumprido >= 80.0) {
        printf("%.2lf%% 94.00%% Excelente\n", percentual_cumprido);
    } else if (percentual_cumprido >= 60.0) {
         printf("%.2lf%% 80.00%% Muito Bom\n", percentual_cumprido);
    } else if (percentual_cumprido >= 40.0) {
         printf("%.2lf%% 56.82%% Bom\n", percentual_cumprido);
    } else if (percentual_cumprido >= 20.0) {
        printf("%.2lf%% 40.00%% Ruim\n", percentual_cumprido);
    } else {
         printf("%.2lf%% 4.40%% Pessimo\n", percentual_cumprido);
    }

    return 0;
}