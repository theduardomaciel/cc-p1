#include <stdio.h>

// 1 (Guerreiro), 2 (Mago) ou 3 (Arqueiro).
// Ataque e vida são > 0.

double menor_valor(double num1, double num2, double num3) {
    if (num1 < num2 && num1 < num3) {
		return num1;
	} else if (num2 < num3) {
		return num2;
	} else {
		return num3;
	}	
}

double buff_vida(int classe1, int classe2, double vida) {
    // Caso 1: Duelo entre Guerreiro (1) e Arqueiro (3). O guerreiro recebe um aumento de 30% em relação a sua vida.
    if (classe1 == 1 && classe2 == 3) {
        return vida + ((30.0 / 100.0) * vida);
    } else if (classe1 == 2 && classe2 == 1) {
        // Caso 3: Duelo entre Mago (2) e Guerreiro (1). O mago recebe um aumento de 15% em sua vida e em seu ataque.
        return vida + ((15.0 / 100.0) * vida);
    }
}

double buff_ataque(int classe1, int classe2, double ataque) {
    // Caso 2: Duelo entre Arqueiro (3) e Mago (2). O arqueiro recebe um aumento de 25% em relação ao seu ataque.
    if (classe1 == 3 && classe2 == 2) {
        return ataque + ((25.0 / 100.0) * ataque);
    } else if (classe1 == 2 && classe2 == 1) {
        // Caso 3: Duelo entre Mago (2) e Guerreiro (1). O mago recebe um aumento de 15% em sua vida e em seu ataque.
        return ataque + ((15.0 / 100.0) * ataque);
    }
}

int checar_vitoria() {
    
}

int main() {
    int classe1_pedro, classe2_pedro, classe3_pedro;
    double ataque1_pedro, ataque2_pedro, ataque3_pedro, vida1_pedro, vida2_pedro, vida3_pedro;

    int classe1_tulio, classe2_tulio, classe3_tulio;
    double ataque1_tulio, ataque2_tulio, ataque3_tulio, vida1_tulio, vida2_tulio, vida3_tulio;

    scanf("%d %lf %lf", &classe1_pedro, &ataque1_pedro, &vida1_pedro);
    scanf("%d %lf %lf", &classe2_pedro, &ataque2_pedro, &vida2_pedro);
    scanf("%d %lf %lf", &classe3_pedro, &ataque3_pedro, &vida3_pedro);

    scanf("%d %lf %lf", &classe1_tulio, &ataque1_tulio, &vida1_tulio);
    scanf("%d %lf %lf", &classe2_tulio, &ataque2_tulio, &vida2_tulio);
    scanf("%d %lf %lf", &classe3_tulio, &ataque3_tulio, &vida3_tulio);

    int vitorias_pedro = 0;
    int vitorias_tulio = 0;

    // Duelo 1

    // Pré-passos, antes de qualquer coisa: Buff das cartas
    vida1_pedro = buff_vida(classe1_pedro, classe1_tulio, vida1_pedro);
    ataque1_pedro = buff_ataque(classe1_pedro, classe1_tulio, ataque1_pedro);

    vida1_tulio = buff_vida(classe1_tulio, classe1_pedro, vida1_tulio);
    ataque1_tulio = buff_ataque(classe1_tulio, classe1_pedro, ataque1_tulio);

    // Passo 1: a carta com menos vida ataca primeiro (Caso sejam iguais, Pedro começa).
    // Passo 2: Se a carta que sofreu o ataque não morrer, ela irá atacar de volta, encerrando o duelo com apenas um ataque de cada.
    if (vida1_tulio < vida1_pedro) {
        vida1_pedro -= ataque1_tulio;

        // Passo 2
        if (vida1_pedro > 0) {
            vida1_tulio -= ataque1_pedro;
        }
    } else {
        vida1_tulio -= ataque1_pedro;

        // Passo 2
        if (vida1_tulio > 0) {
            vida1_pedro -= ataque1_pedro;
        }
    }

    // Condição de vitória 1: O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga.
    if (vida1_pedro < 0) {
        printf("Rodada1: Pedro\n");
        vitorias_pedro += 1;
    } else if (vida1_tulio < 0) {
        printf("Rodada1: Tulio\n");
        vitorias_tulio += 1;
    } else {
        // Condição de vitória 2: O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga.
        if (vida1_pedro > vida1_tulio) {
            printf("Rodada1: Pedro\n");
            vitorias_pedro += 1;
        } else if (vida1_tulio > vida1_pedro) {
            printf("Rodada1: Tulio\n");
            vitorias_tulio += 1;
        } else {
            // Condição de vitória 3: Caso ainda tenha empates, o vencedor será aquele com maior pontos de ataque.
            // É garantido que os ataques nunca serão iguais.
            if (ataque1_pedro > ataque1_tulio) {
                printf("Rodada1: Pedro\n");
                vitorias_pedro += 1;
            } else {
                printf("Rodada1: Tulio\n");
                vitorias_tulio += 1;
            }
        }
    }

    return 0;
}