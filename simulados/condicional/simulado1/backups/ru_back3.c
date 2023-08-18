#include <stdio.h>

// 1 (Guerreiro), 2 (Mago) ou 3 (Arqueiro).
// Ataque e vida são > 0.

/* double menor_valor(double num1, double num2, double num3) {
    if (num1 < num2 && num1 < num3) {
		return num1;
	} else if (num2 < num3) {
		return num2;
	} else {
		return num3;
	}	
} */

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

// Call by Reference
// Instead of passing the value of a variable, we can pass the reference or pointer of the variable as input parameter of the function. Using that pointer we’d be able to change the variable. 

int ataques_rodada(double* vida1_pedro, double* vida1_tulio, double ataque1_pedro, double ataque1_tulio) {
    if (vida1_tulio < vida1_pedro) {
        *vida1_pedro = *vida1_pedro - ataque1_tulio;

        // Passo 2
        if (vida1_pedro > 0) {
            *vida1_tulio = *vida1_tulio - ataque1_pedro;
        }
    } else {
        *vida1_tulio = *vida1_tulio - ataque1_pedro;

        // Passo 2
        if (vida1_tulio > 0) {
            *vida1_pedro = *vida1_pedro - ataque1_pedro;
        }
    }
}

void checar_vitoria(double vida1_pedro, double vida1_tulio, double ataque1_pedro, double ataque1_tulio, int* vitorias_pedro, int* vitorias_tulio, int rodada) {
    // Condição de vitória 1: O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga.
    if (vida1_pedro < 0) {
        printf("Rodada%d: Pedro\n", rodada);
        *vitorias_pedro = *vitorias_pedro + 1;
    } else if (vida1_tulio < 0) {
        printf("Rodada%d: Tulio\n", rodada);
        *vitorias_tulio = *vitorias_tulio + 1;
    } else {
        // Condição de vitória 2: O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga.
        if (vida1_pedro > vida1_tulio) {
            printf("Rodada%d: Pedro\n", rodada);
            *vitorias_pedro = *vitorias_pedro + 1;
        } else if (vida1_tulio > vida1_pedro) {
            printf("Rodada%d: Tulio\n", rodada);
            *vitorias_tulio = *vitorias_tulio + 1;
        } else {
            // Condição de vitória 3: Caso ainda tenha empates, o vencedor será aquele com maior pontos de ataque.
            // É garantido que os ataques nunca serão iguais.
            if (ataque1_pedro > ataque1_tulio) {
                printf("Rodada%d: Pedro\n", rodada);
                *vitorias_pedro = *vitorias_pedro + 1;
            } else {
                printf("Rodada%d: Tulio\n", rodada);
                *vitorias_tulio = *vitorias_tulio + 1;
            }
        }
    }
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

    printf("vitorias pedro: %d\n", vitorias_pedro);
    printf("vitorias tulio: %d\n", vitorias_tulio);

    printf("vida da classe 1 do pedro antes do buff: %lf\n", vida1_pedro);
    printf("ataque da classe 1 do pedro antes do buff: %lf\n", ataque1_pedro);

    printf("vida da classe 1 do tulio antes do buff: %lf\n", vida1_tulio);
    printf("ataque da classe 1 do tulio antes do buff: %lf\n", ataque1_tulio);

    // -> Duelo 1

    // Pré-passos, antes de qualquer coisa: Buff das cartas
    vida1_pedro = buff_vida(classe1_pedro, classe1_tulio, vida1_pedro);
    ataque1_pedro = buff_ataque(classe1_pedro, classe1_tulio, ataque1_pedro);

    vida1_tulio = buff_vida(classe1_tulio, classe1_pedro, vida1_tulio);
    ataque1_tulio = buff_ataque(classe1_tulio, classe1_pedro, ataque1_tulio);

    printf("vida da classe 1 do pedro depois do buff: %lf\n", vida1_pedro);
    printf("ataque da classe 1 do pedro depois do buff: %lf\n", ataque1_pedro);

    printf("vida da classe 1 do tulio depois do buff: %lf\n", vida1_tulio);
    printf("ataque da classe 1 do tulio depois do buff: %lf\n", ataque1_tulio);

    // Ataques
    ataques_rodada(&vida1_pedro, &vida1_tulio, ataque1_pedro, ataque1_tulio);

    // Vitória da Rodada
    checar_vitoria(vida1_pedro, vida1_tulio, ataque1_pedro, ataque1_tulio, &vitorias_pedro, &vitorias_tulio, 1);

    // -> Duelo 2
    
    // Pré-passos, antes de qualquer coisa: Buff das cartas
    vida2_pedro = buff_vida(classe2_pedro, classe2_tulio, vida2_pedro);
    ataque2_pedro = buff_ataque(classe2_pedro, classe2_tulio, ataque2_pedro);

    vida2_tulio = buff_vida(classe2_tulio, classe2_pedro, vida2_tulio);
    ataque2_tulio = buff_ataque(classe2_tulio, classe2_pedro, ataque2_tulio);

    // Ataques
    ataques_rodada(&vida2_pedro, &vida2_tulio, ataque2_pedro, ataque2_tulio);

    // Vitória da Rodada
    checar_vitoria(vida2_pedro, vida2_tulio, ataque2_pedro, ataque2_tulio, &vitorias_pedro, &vitorias_tulio, 2);

    // -> Duelo 3
    
    // Pré-passos, antes de qualquer coisa: Buff das cartas
    vida3_pedro = buff_vida(classe3_pedro, classe3_tulio, vida3_pedro);
    ataque3_pedro = buff_ataque(classe3_pedro, classe3_tulio, ataque3_pedro);

    vida3_tulio = buff_vida(classe3_tulio, classe3_pedro, vida3_tulio);
    ataque3_tulio = buff_ataque(classe3_tulio, classe3_pedro, ataque3_tulio);

    // Ataques
    ataques_rodada(&vida3_pedro, &vida3_tulio, ataque3_pedro, ataque3_tulio);

    // Vitória da Rodada
    checar_vitoria(vida3_pedro, vida3_tulio, ataque3_pedro, ataque3_tulio, &vitorias_pedro, &vitorias_tulio, 3);

    if (vitorias_pedro > vitorias_tulio) {
        printf("Pedro vitorioso\n");
    } else {
        printf("Tulio vitorioso\n");
    }

    return 0;
}