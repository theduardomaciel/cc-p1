#include <stdio.h>

// banda com 7 integrantes
// todos os dias da semana há um ensaio na cada de um integrante diferente

// Pedro, Túlio, Gabriel, Yanka, Paloma, Vinicius e Elias

/* int x_pedro, y_pedro = 0, 0;
int x_tulio, y_tulio = 0, 3;
int x_gabriel, y_gabriel = 0, 5;
int x_yanka, y_yanka = 2, 3;
int x_paloma, y_paloma = 3, 4;
int x_vinicius, y_vinicius = 4, 3;
int x_elias, y_elias = 5, 5; */

int x_pedro = 0;
int y_pedro = 0;

int x_tulio = 0;
int y_tulio = 3;

int x_gabriel = 0;
int y_gabriel = 5;

int x_yanka = 2;
int y_yanka = 3;

int x_paloma = 3;
int y_paloma = 4;

int x_vinicius = 4;
int y_vinicius = 3;

int x_elias = 5;
int y_elias = 5;

int valor_unidade = 100;

int distancia(int x1, int y1, int x2, int y2) {
    return (x2 - x1) + (y2 - y1);
} 

int main() {
    int distancia_pedro, distancia_tulio, distancia_gabriel, distancia_yanka, distancia_paloma, distancia_vinicius, distancia_elias;

    scanf("%d %d %d %d %d %d %d", &distancia_pedro, &distancia_tulio, &distancia_gabriel, &distancia_yanka, &distancia_paloma, &distancia_vinicius, &distancia_elias);
    
    // Dia 1: Pedro
    distancia_tulio -= ((x_tulio - x_pedro) + (y_tulio - y_pedro)) * valor_unidade;
    distancia_gabriel -= ((x_gabriel - x_pedro) + (y_gabriel - y_pedro)) * valor_unidade;
    distancia_yanka -= ((x_yanka - x_pedro) + (y_yanka - y_pedro)) * valor_unidade;
    distancia_paloma -= ((x_paloma - x_pedro) + (y_paloma - y_pedro)) * valor_unidade;
    distancia_vinicius -= ((x_vinicius - x_pedro) + (y_vinicius - y_pedro)) * valor_unidade;
    distancia_elias -= ((x_elias - x_pedro) + (y_elias - y_pedro)) * valor_unidade;

    /* printf("Pedro: %d\n Tulio: %d\n Gabriel: %d\n Yanka: %d\n Paloma: %d\n Vinicius: %d\n Elias: %d\n", distancia_pedro, distancia_tulio, distancia_gabriel, distancia_yanka, distancia_paloma, distancia_vinicius, distancia_elias); */

    // Dia 2: Túlio

    return 0;
}