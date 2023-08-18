#include <stdio.h>

/*
    Descrição
    Kcaj e Ordep são grandes fazendeiros e vizinhos, certo dia eles decidiram iniciar uma competição para saber qual fazenda é a maior produtora de leite.

    Antes do inicio da competição eles registraram os valores inteiros P1 e P2, representando quanto cada um produz diariamente.
    A competição vai durar X dias, onde ***a competição iniciará no dia 1***. Eles concordaram com seguintes as regras:

    Regras para Kcaj:
        1. Quando o dia é primo, a produção de Kcaj terá um aumento de 5% em relação a sua produção diaria.
        2. Quando o somatório dos dígitos resultantes do fatorial do dia for um número primo, Kcaj vai roubar 10% da coleta de Ordep até aquele momento.

    Regras para Ordep:
        1. A partir do fatorial do dia, faça o somatório dos dígitos resultantes do fatorial, caso o somatório seja divisor da produção diária de Ordep, adicione 30 litros de leite na coleta de Ordep.
        2. Quando a coleta diária de Ordep for coprimo do dia, Ordep vai roubar 10% da coleta de Kcaj até aquele momento.

    Cada fazenda tem sua própria produção diária por competição, que será informado juntamente a quantidade de dias que a competição vai acontecer.
    O objetivo é dizer qual fazenda ganhou a competição e qual foi sua coleta de leite.

    OBS.1: As regras somente serão utilizadas no final do dia, ou seja, após ambas as fazendas terem produzido sua quantidade diária.
    OBS.2: Os fazendeiros entraram em um acordo e decidiram que primeiro é feito as duas verificações das regras de Kcaj, após isso será feitas as duas verificações das regras de Ordep.
    OBS.3: Dois números são coprimos quando o MDC deles é 1.

    NÃO HAVERÁ EMPATE.

    -> Formato de entrada
        Um inteiro X, representando a quantidade de dias que a competição vai acontecer
        Um inteiro P1, para a produção diária de Kcaj
        Um inteiro P2, para a produção diária de Ordep

    -> Formato de saída
        O nome do fazendeiro que ganhou, da seguinte forma: "Kcaj Ganhou!" ou "Ordep Ganhou!" seguido de uma quebra de linha com a quantidade de leite que o ganhador produziu nos X dias, com duas casas decimais.
*/

long fatorial(int numero)
{
    // Checamos o caso base
    if (numero <= 0)
    {
        return 1;
    }

    // Caso contrário, realizamos a recursão
    return numero * fatorial(numero - 1);
}

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

int primo(int num, int divisor)
{
    // Caso base: se o divisor se tornar 1, o número é primo
    if (divisor == 1)
    {
        return 1; // Verdadeiro (primo)
    }

    // Se o número é divisível pelo divisor atual, não é primo
    if (num % divisor == 0)
    {
        return 0; // Falso (não é primo)
    }

    // Chama a função recursivamente com o próximo divisor
    return primo(num, divisor - 1);
}

int eh_primo(int num)
{
    // Trata o caso especial para números menores que 2
    if (num <= 1)
    {
        return 0; // Falso (não é primo)
    }

    // Inicia a verificação recursiva a partir do divisor máximo (num - 1)
    return primo(num, num - 1);
}

void loop(int quant_dias, int diaria_jack, int diaria_pedro, double prod_total_jack, double prod_total_pedro, int dia_atual)
{
    prod_total_jack += diaria_jack;
    prod_total_pedro += diaria_pedro;

    int fatorial_do_dia = fatorial(dia_atual);
    int somatorio_dos_digitos_do_fatorial_do_dia = somatorio(fatorial_do_dia);

    // Regra 1 de Jack: Quando o dia é primo, a produção de Kcaj terá um aumento de 5% em relação a sua produção diaria.
    if (eh_primo(dia_atual))
    {
        prod_total_jack += (5.0 / 100.0) * diaria_jack;
    }

    // Regra 2 de Jack: Quando o somatório dos dígitos resultantes do fatorial do dia for um número primo, Kcaj vai roubar 10% da coleta de Ordep até aquele momento.
    if (eh_primo(somatorio_dos_digitos_do_fatorial_do_dia))
    {
        double prod_roubada = (10.0 / 100.0) * prod_total_pedro;
        prod_total_jack += prod_roubada;
        prod_total_pedro -= prod_roubada;
    }

    // Regra 1 de Pedro: A partir do fatorial do dia, faça o somatório dos dígitos resultantes do fatorial, caso o somatório seja divisor da produção diária de Ordep, adicione 30 litros de leite na coleta de Ordep.
    if (diaria_pedro % somatorio_dos_digitos_do_fatorial_do_dia == 0)
    {
        prod_total_pedro += 30;
    }

    // Regra 2 de Pedro: Quando a coleta diária de Ordep for coprimo do dia, Ordep vai roubar 10% da coleta de Kcaj até aquele momento.
    if (mdc(diaria_pedro, dia_atual) == 1)
    {
        double prod_roubada = (10.0 / 100.0) * prod_total_jack;
        prod_total_pedro += prod_roubada;
        prod_total_jack -= prod_roubada;
    }

    if (dia_atual == quant_dias)
    {

        if (prod_total_jack > prod_total_pedro)
        {
            printf("Kcaj Ganhou!\n");
            printf("%.2lf\n", prod_total_jack);
        }
        else
        {
            printf("Ordep Ganhou!\n");
            printf("%.2lf\n", prod_total_pedro);
        }

        return;
    }

    loop(quant_dias, diaria_jack, diaria_pedro, prod_total_jack, prod_total_pedro, dia_atual + 1);
}

int main()
{
    int quant_dias, diaria_jack, diaria_pedro;
    scanf("%d %d %d", &quant_dias, &diaria_jack, &diaria_pedro);

    loop(quant_dias, diaria_jack, diaria_pedro, 0, 0, 1);

    return 0;
}

/*
    FUNÇÕES BASE:
    int mdc(int x, int y){
        if(x%y == 0)
        {
            return y;
        }

        return mdc(y, x%y);
    }

    int fatorial(int x){

        if(x <= 0)
        {
            return 1;
        }

        return x * fatorial(x-1);
    }

    int primo(int n, int divid)
    {
        if(n < 2)
        {
            return 0;
        }
        if(n == divid)
        {
            return 1;
        }
        if(n % divid == 0)
        {
            return 0;
        }
        primo(n, divid+1);
    }

    int somatorio(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        return n%10 + somatorio(n/10);
    }
 */