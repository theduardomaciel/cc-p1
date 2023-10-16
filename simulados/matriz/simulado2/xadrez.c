#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
	PONTUAÇÃO DAS PEÇAS:
		- Peão: 1 ponto
		- Bispo: 3 pontos
		- Cavalo: 3 Pontos
		- Torre: 8 pontos
		- Dama: 9 Pontos
		- Rei: 0 pontos
*/

/*
	NOTAÇÃO DAS PEÇAS:
		- Peão: p
		- Bispo: b
		- Cavalo: c
		- Torre: t
		- Dama: d
		- Rei: r

	// Para casas vazias, ou seja, que não tem nenhuma peça, usaremos o caractere 'L
	// Para representar a cor das peças usaremos a inicial da cor, ou seja, 'b' para as brancas e 'p' para as pretas. Para o caso da casa estar sem peças também usaremos o caractere 'L'
*/

// Está melhor na posição aquele que tem a maior soma.

int main()
{
	char board[8][8];
	char board_colors[8][8];

	int white_score = 0, black_score = 0;

	for (int line = 0; line < 8; line++)
	{
		for (int column = 0; column < 8; column++)
		{
			char *string = (char *)malloc(3 * sizeof(char));
			scanf("%s", string);

			board[line][column] = string[0];
			board_colors[line][column] = string[1];
		}
	}

	/* for (int line = 0; line < 8; line++)
	{
		for (int column = 0; column < 8; column++)
		{
			printf("%c\t", board[line][column]);
		}
		printf("\n");
	} */

	for (int line = 0; line < 8; line++)
	{
		for (int column = 0; column < 8; column++)
		{
			// printf("Peça: %c\n", board[line][column]);
			switch (board[line][column])
			{
			case 'p': // Se for um peão...
				// ...branco, adicionamos às brancas
				if (board_colors[line][column] == 'b')
				{
					white_score += 1;
				}
				// ...preto, adicionamos às pretas
				else
				{
					black_score += 1;
				}
				break;
			case 'b':
			case 'c': // Se for um bisco ou cavalo...
				// ...branco, adicionamos às brancas
				if (board_colors[line][column] == 'b')
				{
					white_score += 3;
				}
				// ...preto, adicionamos às pretas
				else
				{
					black_score += 3;
				}
				break;
			case 't': // Se for uma torre...
				// ...branca, adicionamos às brancas
				if (board_colors[line][column] == 'b')
				{
					white_score += 8;
				}
				// ...preta, adicionamos às pretas
				else
				{
					black_score += 8;
				}
				break;
			case 'd': // Se for uma dama...
				// ...branca, adicionamos às brancas
				if (board_colors[line][column] == 'b')
				{
					white_score += 9;
				}
				// ...preta, adicionamos às pretas
				else
				{
					black_score += 9;
				}
				break;
			default:
				break;
			}
		}
	}

	if (white_score == black_score)
	{
		printf("Empate\n");
	}
	else if (white_score > black_score)
	{
		printf("Brancas\n");
	}
	else if (black_score > white_score)
	{
		printf("Negras\n");
	}

	return 0;
}