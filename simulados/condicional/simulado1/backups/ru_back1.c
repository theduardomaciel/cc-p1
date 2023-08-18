#include <stdio.h>

// 1 (Guerreiro), 2 (Mago) ou 3 (Arqueiro).
// Ataque e vida são > 0.

int menor_valor(double num1, double num2, double num3) {
    if (num1 < num2 && num1 < num3) {
		return num1;
	} else if (num2 < num3) {
		return num2;
	} else {
		return num3;
	}	
}

int main() {
    int classe1_pedro, classe2_pedro, classe3_pedro;
    double ataque1_pedro, ataque2_pedro, ataque3_pedro, vida1_pedro, vida2_pedro, vida3_pedro;

    int classe1_tulio, classe2_tulio, classe3_tulio;
    double ataque1_tulio, ataque2_tulio, ataque3_tulio, vida1_tulio, vida2_tulio, vida3_tulio;


    // Duelo 1

    // Passo 1: a carta com menos vida ataca primeiro (Caso sejam iguais, Pedro começa).
    double ataque_duelo1;

    double ataque_pedro_rodada1;
    // Primeiro verificamos qual a carta com menos vida de Pedro, e salvamos seu ataque para compará-lo com os de Tulio
    ataque_pedro_rodada1 = menor_valor(vida1_pedro, vida2_pedro, vida3_pedro);
    if (vida1_pedro < vida2_pedro && vida1_pedro < vida3_pedro) {
		ataque_pedro_rodada1 = ataque1_pedro;
	} else if (vida2_pedro < vida3_pedro) {
		ataque_pedro_rodada1 = ataque2_pedro;
	} else {
		ataque_pedro_rodada1 = ataque3_pedro;
	}

    double ataque_tulio_rodada1;
    // Agora comparamos com as cartas de Tulio para vermos se há alguma com vida mais baixa
    if (vida1_tulio < vida2_tulio && vida1_tulio < vida3_tulio) {
		ataque_tulio_rodada1 = ataque1_tulio;
	} else if (vida2_tulio < vida3_tulio) {
		ataque_tulio_rodada1 = ataque2_tulio;
	} else {
		ataque_tulio_rodada1 = ataque3_tulio;
	}

    if (ataque_tulio_rodada1 < ataque_pedro_rodada1) {
        ataque_duelo1 = ataque_tulio_rodada1;
    } else {
        ataque_duelo1 = ataque_pedro_rodada1;
    }

    // Caso 1: Duelo entre Guerreiro (1) e Arqueiro (3). O guerreiro recebe um aumento de 30% em relação a sua vida.
    if (classe1_pedro == 1 && classe1_tulio == 3) {
        vida1_pedro = vida1_pedro + ((30.0 / 100.0) * vida1_pedro);
    } else if (classe1_pedro == 3 && classe1_tulio == 1) {
        vida1_tulio = vida1_tulio + ((30.0 / 100.0) * vida1_tulio);
    }

    // Caso 2: Duelo entre Arqueiro (3) e Mago (2). O arqueiro recebe um aumento de 25% em relação ao seu ataque.
    if (classe1_pedro == 3 && classe1_tulio == 2) {
        ataque3_pedro = ataque3_pedro + ((25.0 / 100.0) * ataque3_pedro);
    } else if (classe1_pedro == 2 && classe1_tulio == 3) {
        ataque3_tulio = ataque3_tulio + ((25.0 / 100.0) * ataque3_tulio);
    }

    // Caso 3: Duelo entre Mago (2) e Guerreiro (1). O mago recebe um aumento de 15% em sua vida e em seu ataque.
    if (classe1_pedro == 2 && classe1_tulio == 1) {
        ataque2_pedro = ataque2_pedro + ((15.0 / 100.0) * ataque2_pedro);
        vida2_pedro = vida2_pedro + ((15.0 / 100.0) * vida2_pedro);
    } else if (classe1_pedro == 1 && classe1_tulio == 2) {
        ataque3_tulio = ataque3_tulio + ((25.0 / 100.0) * ataque3_tulio);
    }

    // Passo 2: Se a carta que sofreu o ataque não morrer, ela irá atacar de volta, encerrando o duelo com apenas um ataque de cada.

    return 0;
}