#include <stdio.h>

// 1 (Guerreiro), 2 (Mago) ou 3 (Arqueiro).
// Ataque e vida são > 0.

void buffs(int classe_pedro, int classe_tulio, double* vida_pedro, double* ataque_pedro, double* vida_tulio, double* ataque_tulio) {
    // Caso 1: Duelo entre Guerreiro (1) e Arqueiro (3). O guerreiro recebe um aumento de 30% em relação a sua vida.
    if (classe_pedro == 1 && classe_tulio == 3) {
        *vida_pedro = *vida_pedro + (vida_pedro * (30.0 / 100.0));
    } else if (classe_pedro == 3 && classe_tulio == 1) {
        *vida_tulio = *vida_tulio + (vida_tulio * (30.0 / 100.0));
    }

    // Caso 2: Duelo entre Arqueiro (3) e Mago (2). O arqueiro recebe um aumento de 25% em relação ao seu ataque.
    if (classe_pedro == 3 && classe_tulio == 2) {
        *ataque_pedro = *ataque_pedro + ((25.0 / 100.0) * ataque_pedro);
    } else if (classe_pedro == 2 && classe_tulio == 3) {
        *ataque_tulio = *ataque_tulio + ((25.0 / 100.0) * ataque_tulio);
    }

    // Caso 3: Duelo entre Mago (2) e Guerreiro (1). O mago recebe um aumento de 15% em sua vida e em seu ataque.
    if (classe_pedro == 2 && classe_tulio == 1) {
        *ataque_pedro = *ataque_pedro + (ataque_pedro * (15.0 / 100.0));
        *vida_pedro = *vida_pedro + (vida_pedro * (15.0 / 100.0));
    } else if (classe_pedro == 1 && classe_tulio == 2) {
        *ataque_tulio = *ataque_tulio + (ataque_tulio * (15.0 / 100.0));
        *vida_tulio = *vida_tulio + (vida_tulio * (15.0 / 100.0));
    }
}

// Call by Reference
// Instead of passing the value of a variable, we can pass the reference or pointer of the variable as input parameter of the function. Using that pointer we’d be able to change the variable. 

int ataques_rodada(double* vida_pedro, double* vida_tulio, double ataque_pedro, double ataque_tulio) {
    // a carta com menos vida ataca primeiro (Caso sejam iguais, Pedro começa).
    // Condição: Se a carta que sofreu o ataque não morrer, ela irá atacar de volta, encerrando o duelo com apenas um ataque de cada.
    if (vida_tulio < vida_pedro) {
        // Túlio ataca primeiro
        *vida_pedro = *vida_pedro - ataque_tulio;

        // Caso a carta de Pedro não morra, ela ataca de volta
        if (vida_pedro > 0) {
            *vida_tulio = *vida_tulio - ataque_pedro;
        }
    } else {
        // Pedro ataca primeiro
        *vida_tulio = *vida_tulio - ataque_pedro;

        // Caso a carta de Túlio não morra, ela ataca de volta
        if (vida_tulio > 0) {
            *vida_pedro = *vida_pedro - ataque_tulio;
        }
    }
}

void checar_vitoria(double vida_pedro, double vida_tulio, double ataque_pedro, double ataque_tulio, int* vitorias_pedro, int* vitorias_tulio, int rodada) {
    // Condição de vitória 1: O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga.
    if (vida_tulio < 0) {
        printf("Rodada%d: Pedro\n", rodada);
        *vitorias_pedro = *vitorias_pedro + 1;
    } else if (vida_pedro < 0) {
        printf("Rodada%d: Tulio\n", rodada);
        *vitorias_tulio = *vitorias_tulio + 1;
    } else {
        // Condição de vitória 2: Em casos em que nenhuma carta foi eliminada, o vencedor é aquele com mais pontos de vida.
        if (vida_pedro > vida_tulio) {
            printf("Rodada%d: Pedro\n", rodada);
            *vitorias_pedro = *vitorias_pedro + 1;
        } else if (vida_tulio > vida_pedro) {
            printf("Rodada%d: Tulio\n", rodada);
            *vitorias_tulio = *vitorias_tulio + 1;
        } else {
            // Condição de vitória 3: Caso ainda tenha empates, o vencedor será aquele com maior pontos de ataque.
            // É garantido que os ataques nunca serão iguais.
            if (ataque_pedro > ataque_tulio) {
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
    buffs(classe1_pedro, classe1_tulio, &vida1_pedro, &ataque1_pedro, &vida1_tulio, &ataque1_tulio);

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
    buffs(classe2_pedro, classe2_tulio, &vida2_pedro, &ataque2_pedro, &vida2_tulio, &ataque2_tulio);

    // Ataques
    ataques_rodada(&vida2_pedro, &vida2_tulio, ataque2_pedro, ataque2_tulio);

    // Vitória da Rodada
    checar_vitoria(vida2_pedro, vida2_tulio, ataque2_pedro, ataque2_tulio, &vitorias_pedro, &vitorias_tulio, 2);

    // -> Duelo 3
    
    // Pré-passos, antes de qualquer coisa: Buff das cartas
    buffs(classe3_pedro, classe3_tulio, &vida3_pedro, &ataque3_pedro, &vida3_tulio, &ataque3_tulio);

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