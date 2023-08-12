#include <stdio.h>

// Observações:
// - O flamengo sempre começa com 100% de chance de vitória
// - Cada jogador lesionado diminui em 2.7% (jogando em casa ou fora de casa) a chance de vitória

// tempo: '1' para sol, '2' para neve e '3' para chuva

int main() {
    int em_casa, tempo, quant_torcedores, quant_lesionados, quant_entrosamento;

    scanf("%d %d %d %d %d", &em_casa, &tempo, &quant_torcedores, &quant_lesionados, &quant_entrosamento);

    double chance = (100 / 100.0);

    // Cada jogador lesionado diminui em 2.7% (jogando em casa ou fora de casa) a chance de vitória
    chance -= ((2.7 / 100.0) * quant_lesionados);

    if (em_casa == 1) {
        if (tempo == 3) {
            // A chuva (3) diminui (-) em 20.7% a chance de vitória
            chance -= (20.7 / 100.0);
        } else if (tempo == 2) {
            // A neve (2) aumenta (+) em 10.51% a chance de vitória
            chance += (10.51 / 100.0);
        } else if (tempo == 1) {
            // O sol (1) aumenta (+) em 33.21% a chance de vitória
            chance += (33.21 / 100.0);
        }

        //printf("Chance depois da chuva: %.2lf\n", chance);

        // Cada torcedor aumenta em 0.0008% a chance de vitória se a quantidade de torcedores presentes for maior que 40000, caso contrário cada torcedor irá diminuir em 0.0008% a chance de vitória
        if (quant_torcedores > 40000) {
            chance += ((0.0008 / 100.0) * quant_torcedores);
        } else {
            chance -= ((0.0008 / 100.0) * quant_torcedores);
        }

        //printf("Chance depois dos torcedores: %.2lf\n", chance);

        // Cada ponto de entrosamento do time aumenta em 2.7% a chance de vitória caso o entrosamento seja maior que zero. Se o entrosamento do time for menor que zero será reduzido 1.8% da chance de vitória para cada ponto.
        if (quant_entrosamento > 0) {
            chance += ((2.7 / 100.0) * quant_entrosamento);
        } else if (quant_entrosamento < 0) {
            chance -= ((2.7 / 100.0) * (quant_entrosamento * -1));
        }

        //printf("Chance depois do entrosamento: %.2lf\n", chance);
    } else {
        // Se chover ou nevar o Flamengo automaticamente desiste da partida, ou seja, a chance de vitória vai automaticamente para 0 (Zero) sem alterações a ela.
        if (tempo == 3 || tempo	 == 2) {
            chance = 0.0;
        } else {
            // O sol diminui em 10.87% a chance de vitória
            if (tempo == 1) {
                chance -= (10.87 / 100.0);
            }

            // Cada torcedor diminui em 0.0003 a chance de vitória se a quantidade de torcedores presentes for maior que 45000, caso contrário cada torcedor irá diminuir em 0.0001% a chance de vitória
            if (quant_torcedores > 45000) {
                chance -= ((0.0003 / 100.0) * quant_torcedores);
            } else {
                chance -= ((0.0001 / 100.0) * quant_torcedores);
            }

            // Cada ponto de entrosamento do time aumenta em 5.2% a chance de vitória caso o entrosamento seja maior que zero. Se o entrosamento do time for menor que zero será reduzido 1.5% da chance de vitória para cada ponto.
            if (quant_entrosamento > 0) {
                chance += ((5.2 / 100.0) * quant_entrosamento);
            } else if (quant_entrosamento < 0) {
                chance -= ((1.5 / 100.0) * (quant_entrosamento * -1));
            }
        }
    }

    //printf("Chance final: %.2lf\n", chance);
    double chance_final = chance * 100.0;

    if (chance_final >= 100) {
        printf("A chance de vitoria do flamengo e de %.2lf\n", 100.00);
    } else if (chance_final < 0) {
        printf("A chance de vitoria do flamengo e de %.2lf\n", 0.00);
    } else {
        printf("A chance de vitoria do flamengo e de %.2lf\n", chance_final);
    }

    return 0;
}