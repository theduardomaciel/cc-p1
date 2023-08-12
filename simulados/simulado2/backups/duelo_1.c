#include <stdio.h>

double multiplicar_1_a_5 = 1.20;
double multiplicar_6_a_10 = 1.50;
double multiplicar_11_a_15 = 1.80;
double multiplicar_16_a_20 = 2.00;

int main() {
    int nivel_personagem, nivel_inimigo;
    double dano_personagem, vida_inimigo;

    scanf("%d %lf %d %lf", &nivel_personagem, &dano_personagem, &nivel_inimigo, &vida_inimigo);

    // Verificando a validade dos níveis
    if (nivel_inimigo < 1 || nivel_personagem < 1) {
        printf("Nivel abaixo\n");
    } else if (nivel_inimigo > 20 || nivel_personagem > 20) {
        printf("Nivel acima\n");
    } else {
        double multiplicador_personagem, multiplicador_inimigo;

         // Buffamos o personagem
        if (nivel_personagem >= 15) {
            dano_personagem *= multiplicar_16_a_20;
        } else if (nivel_personagem >= 11) {
            dano_personagem *= multiplicar_11_a_15;
        } else if (nivel_personagem >= 6) {
            dano_personagem *= multiplicar_6_a_10;
        } else {
            dano_personagem *= multiplicar_1_a_5;
        }

        //printf("Dano: %lf\n", dano_personagem);

        // Buffamos o inimigo
        if (nivel_inimigo >= 16) {
            vida_inimigo *= multiplicar_16_a_20;
        } else if (nivel_inimigo >= 11) {
            vida_inimigo *= multiplicar_11_a_15;
        } else if (nivel_inimigo >= 6) {
            vida_inimigo *= multiplicar_6_a_10;
        } else {
            vida_inimigo *= multiplicar_1_a_5;
        }

        //printf("Vida: %lf\n", vida_inimigo);

        // (Vida do inimigo * multiplicador baseado no nível dele) – (Seu dano * multiplicador baseado no seu nível)
        vida_inimigo -= dano_personagem;
        
        if (vida_inimigo > 0) {
            printf("Personagem 2 venceu\n");
            printf("Vida restante: %.2lf\n", vida_inimigo);
        } else {
            printf("Personagem 1 venceu\n");
            printf("Dano causado: %.2lf\n", dano_personagem);
        }
    }

    return 0;
}