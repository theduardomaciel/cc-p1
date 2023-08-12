#include <stdio.h>

int main() {
    int credito1, credito2, credito3;

    scanf("%d%d%d", &credito1, &credito2, &credito3);

    // para ser possível com duas viagens, elas devem se anular;
    int e_possivel_com_duas_viagens = credito1 == credito2 || credito1 == credito3 || credito2 == credito3;

    // para ser possível com três viagens, a soma de duas delas deve ser igual a uma eventual viagem de volta;
    int e_possivel_com_tres_viagens_de_ida_ou_volta = credito1 + credito2 == credito3 || credito1 + credito3 == credito2 || credito2 + credito3 == credito1;

    if (e_possivel_com_duas_viagens || e_possivel_com_tres_viagens_de_ida_ou_volta) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}