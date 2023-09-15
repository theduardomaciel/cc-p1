#include <stdio.h>

// O dado tem 1500 faces (de 1 a 1500)
// O "X" será o mesmo para ambos, somente irá ficar alternando entre os dois até cada um dos dois jogarem "X" vezes
// Caso valor do dado seja inválido, a partida é anulada e devesse printar "valor fora do limite!"

/* Com isso, o fator principal dessa disputa é a soma do:
        -> menor elemento do array + do maior elemento do array + o valor central do array (com o array ordenado).
    Note que cada jogador vai ter seu próprio fator principal.
*/

/*
    Nesse jogo são dadas 3 condições, aquele que conseguir passar em mais condições ganha a partida.
    As regras são:
        1 - O fator principal ser primo.
        2 - O fator principal e o maior elemento do array serem coprimos.
        3 - O somatório dos dígitos do próximo primo do fator principal ser um número primo.
*/

// Aquele que conseguir satisfazer mais regras vence. Caso empate devesse printar "empate"

// Bubble sort com uma só função
void sort(int i, int j, int arr[], int limit)
{
    if (i >= limit)
    {
        return;
    }

    if (j >= limit)
    {
        return sort(i + 1, i + 2, arr, limit);
    }

    if (arr[i] > arr[j])
    {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
    sort(i, j + 1, arr, limit);
}

int eh_primo(int x, int i)
{
    if (x < 2)
    {
        return 0;
    }
    else if (x == 2 || i * i > x)
    {
        return 1;
    }
    else if (x % 2 == 0 || x % i == 0)
    {
        return 0;
    }
    else
    {
        return eh_primo(x, i + 1);
    }
}

int proximo_primo(int x)
{
    if (eh_primo(x, 2))
        return x;
    else
        return proximo_primo(x & 1 ? x + 2 : x + 1);
}

// Conceito Matemático:
// Chamamos números primos entre si (ou coprimos) ao conjunto de números onde o único divisor comum a todos eles é o número 1.
int mdc(int dividendo, int divisor)
{
    // Quando não houver resto entre a divisão do dividendo e do divisor, podemos retornar o divisor como o maior possível
    if (dividendo % divisor == 0)
    {
        return divisor;
    }
    else
    {
        return mdc(divisor, dividendo % divisor);
    }
}

int somatorio(int num)
{
    if (num == 0)
    {
        return 0; // Caso base: quando o número é zero, o somatório é zero
    }
    else
    {
        return (num % 10) + somatorio(num / 10); // Somar o último dígito e chamar a função para o resto do número
    }
}

void read_array(int i, int limit, int array[], int array2[])
{
    if (i == limit)
    {
        return;
    }

    scanf("%d %d", &array[i], &array2[i]);
    read_array(i + 1, limit, array, array2);
}

// Apesar de parecer confuso, é só uma função pra verificar se é inválido
// A forma com que isso funciona é: A maioria das operações (<, >, ==) retornam um valor de 0 (Falso) ou 1 (Verdadeiro)
// Então Caso alguma dessas condições seja atendida vai retornar 1, ou seja dado inválido
int is_invalid_dice(int arr[], int x)
{
    return arr[0] < 1 || arr[0] > 1500 || arr[x - 1] < 1 || arr[x - 1] > 1500 || arr[x / 2] < 1 || arr[x / 2] > 1500;
}

void rolar_dados(int index, int quant_rolamentos, int numeros_pedro[], int size_pedro, int numeros_jack[], int size_jack)
{
    // printf("Rolamento %d. de um total de %d\n", index + 1, quant_rolamentos);

    if (index == quant_rolamentos)
    {
        return;
    }

    int dado_pedro;
    scanf("%d", &dado_pedro);

    int dado_jack;
    scanf("%d", &dado_jack);

    numeros_pedro[size_pedro] = dado_pedro;
    size_pedro += 1;

    numeros_jack[size_jack] = dado_jack;
    size_jack += 1;

    return rolar_dados(index + 1, quant_rolamentos, numeros_pedro, size_pedro, numeros_jack, size_jack);
}

void rodar_partidas(int restante)
{
    if (restante == 0)
    {
        return;
    }

    int X;
    scanf("%d", &X);

    // um inteiro 3 <= X <= 23 ( X sempre ímpar)
    /* printf("Quantidade de jogadas: %d\n", X);
    if (X < 3 || X > 23 || X % 2 == 0)
    {
        printf("Entrou na quantidade de jogadas do dado por jogador\n");
        printf("valor fora do limite!\n");
        return;
    } */

    int numeros_pedro[X];
    int numeros_jack[X];

    rolar_dados(0, X, numeros_pedro, 0, numeros_jack, 0);

    // Ordenamos as arrays de forma crescente (do menor para o maior)
    sort(0, 1, numeros_pedro, X);
    sort(0, 1, numeros_jack, X);

    // Calculamos o fator principal individual
    int fator_principal_pedro = numeros_pedro[0] + numeros_pedro[X - 1] + numeros_pedro[X / 2];
    int fator_principal_jack = numeros_jack[0] + numeros_jack[X - 1] + numeros_jack[X / 2];

    // printf("fator_principal_pedro: %d\n", fator_principal_pedro);
    // printf("fator_principal_jack: %d\n", fator_principal_jack);

    // Verificamos a quantidade de regras que cada um satisfez
    int quant_regras_pedro = 0, quant_regras_jack = 0;

    // Regra 1: O fator principal ser primo.
    if (eh_primo(fator_principal_pedro, 2))
    {
        // printf("O fator principal de pedro é primo!\n");
        quant_regras_pedro += 1;
    }

    if (eh_primo(fator_principal_jack, 2))
    {
        // printf("O fator principal de jack é primo!\n");
        quant_regras_jack += 1;
    }

    // printf("último elemento da array de jack: %d\n", numeros_jack[X - 1]);
    //  printf("último elemento da array de jack: %d\n", numeros_jack[X - 1]);

    // Regra 2: O fator principal e o maior elemento do array serem coprimos.
    if (mdc(fator_principal_pedro, numeros_pedro[X - 1]) == 1)
    {
        quant_regras_pedro += 1;
    }

    if (mdc(fator_principal_jack, numeros_jack[X - 1]) == 1)
    {
        quant_regras_jack += 1;
    }

    // Regra 3: O somatório dos dígitos do próximo primo do fator principal ser um número primo.
    if (eh_primo(somatorio(proximo_primo(fator_principal_pedro + 1)), 2))
    {
        quant_regras_pedro += 1;
    }

    if (eh_primo(somatorio(proximo_primo(fator_principal_jack + 1)), 2))
    {
        quant_regras_jack += 1;
    }

    // printf("quant_regras_pedro: %d\n", quant_regras_pedro);
    // printf("quant_regras_jack: %d\n", quant_regras_jack);

    if (is_invalid_dice(numeros_jack, X) == 1 || is_invalid_dice(numeros_pedro, X) == 1)
    {
        printf("valor fora do limite!\n");
    }
    else if (quant_regras_pedro > quant_regras_jack)
    {
        printf("Ordep %d\n", fator_principal_pedro);
    }
    else if (quant_regras_jack > quant_regras_pedro)
    {
        printf("Kcaj %d\n", fator_principal_jack);
    }
    else if (quant_regras_jack == quant_regras_pedro)
    {
        printf("empate\n");
    }
    else
    {
        printf("Ordep %d\n", fator_principal_pedro);
    }

    rodar_partidas(restante - 1);
}

int main()
{
    int quant_partidas;
    scanf("%d", &quant_partidas);

    // printf("Quantidade de partidas: %d\n", quant_partidas);

    rodar_partidas(quant_partidas);

    return 0;
}

/*
void imprimir_ao_contrario(char str[], int i)
{
    if (i == -1)
    {
        printf("\n");
        return;
    }
    printf("%c", str[i]);
    imprimir_ao_contrario(str, i - 1);
}

void para_maiusculo(char frase[], int final)
{
    if (final == -1) return;
    if (frase[final] >= 'a' && frase[final] <= 'z')
    {
        frase[final] = frase[final] - ('a' - 'A');
    }
    para_maiusculo(frase, final - 1);
}

*/