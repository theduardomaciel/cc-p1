#include <stdio.h>

// banda com 7 integrantes
// todos os dias da semana há um ensaio na cada de um integrante diferente

// Pedro, Túlio, Gabriel, Yanka, Paloma, Vinicius e Elias

int x_pedro, y_pedro = 0, 0;
int x_tulio, y_tulio = 0, 3;
int x_gabriel, y_gabriel = 0, 5;
int x_yanka, y_yanka = 2, 3;
int x_paloma, y_paloma = 3, 4;
int x_vinicius, y_vinicius = 4, 3;
int x_elias, y_elias = 5, 5;

int main() {
    int distancia_pedro, distancia_tulio, distancia_gabriel, distancia_yanka, distancia_paloma, distancia_vinicius, distancia_elias;

    scanf("%d %d %d %d %d %d %d", &distancia_pedro, &distancia_tulio, &distancia_gabriel, &distancia_yanka, &distancia_paloma, &distancia_vinicius, &distancia_elias);
    
    // Dia 1: Pedro
    distancia_tulio -= 300;
    distancia_gabriel -= 500;
    distancia_yanka -= 500;
    distancia_paloma -= 700;
    distancia_vinicius -= 700;
    distancia_elias -= 1000;

    // Dia 2: Túlio

    return 0;
}