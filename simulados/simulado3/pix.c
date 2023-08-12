#include <stdio.h>

double valor_a, valor_b, valor_c, valor_d;

double valor_letra(char letra) {
    if (letra == 97) { /* a */
        return valor_a;
    } else if (letra == 98) { /* b */
        return valor_b;
    } else if (letra == 99) { /* c */
        return valor_c;
    } else if (letra == 100) { /* d */
        return valor_d;
    } else {
        return 0;
    }
}

int main() {
    int valor_anderson, valor_guilherme, valor_rita, valor_higor;
    char letra_anderson, letra_guilherme, letra_rita, letra_higor;

    scanf("%d %d %d %d", &valor_anderson, &valor_guilherme, &valor_rita, &valor_higor);
    scanf(" %c %c %c %c", &letra_anderson, &letra_guilherme, &letra_rita, &letra_higor);
    scanf("%lf %lf %lf %lf", &valor_a, &valor_b, &valor_c, &valor_d);

    double media = (valor_anderson + valor_guilherme + valor_rita + valor_higor) / 4;
    double fator;

    if (media >= 0 && media <= 10) {
        fator = 0.4;
    } else if (media > 10 && media <= 30) {
        fator = 0.6;
    } else if (media > 30 && media <= 60) {
        fator = 0.8;
    } else {
        fator = 1.0;
    }

    // Anderson
    double pontuacao_anderson = valor_anderson + valor_letra(letra_anderson) + (valor_letra(letra_anderson) * fator);
    // Guilherme
    double pontuacao_guilherme = valor_guilherme + valor_letra(letra_guilherme) + (valor_letra(letra_guilherme) * fator);
    // Rita
    double pontuacao_rita = valor_rita + valor_letra(letra_rita) + (valor_letra(letra_rita) * fator);
    // Higor
    double pontuacao_higor = valor_higor + valor_letra(letra_higor) + (valor_letra(letra_higor) * fator);

    /* printf("Anderson: %.2lf\n", pontuacao_anderson);
    printf("Guilherme: %.2lf\n", pontuacao_guilherme);
    printf("Rita: %.2lf\n", pontuacao_rita);
    printf("Higor: %.2lf\n", pontuacao_higor); */

    if(pontuacao_anderson < pontuacao_guilherme && pontuacao_anderson < pontuacao_rita && pontuacao_anderson < pontuacao_higor) {
        printf("Anderson quem vai pagar o lanche!:D\n");
    } else if (pontuacao_guilherme < pontuacao_rita && pontuacao_guilherme < pontuacao_higor) {
        printf("Guilherme quem vai pagar o lanche!:D\n");
    } else if (pontuacao_rita < pontuacao_higor) {
        printf("Rita quem vai pagar o lanche!:D\n");
    } else {
        printf("Higor quem vai pagar o lanche!:D\n");
    }

    return 0;
}