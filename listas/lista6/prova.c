#include <stdio.h>
#include <string.h>

// Cada prova tem 10 questões, cada questão valendo um ponto
// O programa encerra a entrada quando o número de um aluno dado for igual a 9999

/*
    Entrada:
        Uma sequência de 10 caracteres correspondendo ao gabarito.
        Uma sequência de números inteiros representando o aluno e a uma sequencia de caracteres correspondendo a sua resposta.
*/

/*
    Saída:
        Para cada aluno lido, na mesma ordem de leitura, deve ser impresso seu número e sua nota. A nota deve ser formatada com uma casa decimal.

        Ao final, deve ser impresso a porcentagem de aprovação, sabendo-se que a nota mínima para aprovação é de 6. O percentual deve ser impresso com uma casa decimal seguido do caractere %.

        Por fim, deve ser impressa a nota que teve a maior frequência absoluta, ou seja, a nota que apareceu o maior número de vezes (supondo a inexistência de empates).
*/

int checar_questao(char gabarito, char resposta)
{
    if (gabarito == resposta)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// o "index" corresponde à questão sendo checada na iteração atual
// o "size" corresponde à quantidade de questões que a prova possui
int nota_individual(char gabarito[], char resposta[], int index, int size)
{
    if (index == size)
    {
        return 0;
    }

    if (checar_questao(gabarito[index], resposta[index]))
    {
        return 1 + nota_individual(gabarito, resposta, index + 1, size);
    }
    else
    {
        return nota_individual(gabarito, resposta, index + 1, size);
    }
}

void request_input(char gabarito[], int *quant_alunos, int *quant_aprovados, int frequencia[])
{
    int numero_aluno;
    scanf("%d", &numero_aluno);

    if (numero_aluno == 9999)
    {
        // printf("NÚMERO ALUNO:%d\n", numero_aluno);
        return;
    }

    char resposta_aluno[22];
    scanf("%s", resposta_aluno);
    // fgets(resposta_aluno, sizeof(resposta_aluno), stdin);

    // printf("GABARITO ALUNO:%s", resposta_aluno);
    //  puts(resposta_aluno);

    int nota = nota_individual(gabarito, resposta_aluno, 0, 10);

    printf("%d %.1f\n", numero_aluno, (double)nota);

    if (nota >= 6)
    {
        *quant_aprovados += 1;
    }

    frequencia[nota] += 1;
    *quant_alunos += 1;

    return request_input(gabarito, quant_alunos, quant_aprovados, frequencia);
}

void array_print(int index, int end, int array_numeros[])
{
    if (index == end)
    {
        printf("\n");
        return;
    }

    printf("%d ", array_numeros[index]);

    return array_print(index + 1, end, array_numeros);
}

void obter_nota_mais_frequente(int frequencias[], int index, int size, int maior_frequencia, int *nota)
{
    if (index == size)
    {
        return;
    }

    if (frequencias[index] != 0 && frequencias[index] >= maior_frequencia)
    {
        // printf("%d é maior que %d, portanto o index: %d é o com a nota de maior frequência!\n", frequencias[index], maior_frequencia, index);
        maior_frequencia = frequencias[index];
        *nota = index;
    }

    return obter_nota_mais_frequente(frequencias, index + 1, size, maior_frequencia, nota);
}

int main()
{
    char gabarito[11];
    scanf("%s", gabarito);

    /* printf("GABARITO: ");
    puts(gabarito); */

    int quant_alunos = 0;
    int quant_aprovados = 0;
    int frequencia[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    request_input(gabarito, &quant_alunos, &quant_aprovados, frequencia);

    // array_print(0, 11, frequencia);

    int nota_mais_frequente = 0;
    obter_nota_mais_frequente(frequencia, 0, 11, 0, &nota_mais_frequente);

    printf("%.1lf%%\n", (double)(quant_aprovados * 100) / quant_alunos);
    printf("%.1lf\n", (double)nota_mais_frequente);

    return 0;
}