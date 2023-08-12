#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int numero_input;
    
    scanf("%d", &numero_input);
    
    int antecessor = numero_input - 1;
    int sucessor = numero_input + 1;
    
    printf("%d %d", antecessor, sucessor);
    
	return 0;
}