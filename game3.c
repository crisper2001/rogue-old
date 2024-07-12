#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	INICIO:
	srand(time(NULL));
	int T = rand() % 10 + 10;
	char Screen[T][T + 1], Input;
	int I, J, X, Y, Score = 0, Gold = 0;
	for (I = 0; I < T; I ++)
	{
		for (J = 0; J < T; J ++)
		{
			if (I == 0 || I == T - 1 || J == 0 || J == T - 1)
			{
				Screen[I][J] = '#';	
			}
			else if (rand() % 100 > 5)
			{
				Screen[I][J] = ' ';
			}
			else
			{
				Screen[I][J] = '*';
				Gold ++;
			}
		}
		Screen[I][J] = '\0';
	}
	if (Screen[1 + rand() % (T - 2)][1 + rand() % (T - 2)] != '*' && Gold > 0) Screen[1 + rand() % (T - 2)][1 + rand() % (T - 2)] = '@';
	else goto INICIO;
	if (Gold == 0) goto INICIO;
	do {
		system("cls");
		printf("Crisper's Rogue\n\n");
		for (I = 0; I < T; I ++)
		{
			for (J = 0; J < T; J ++)
			{		
				if (Screen[I][J] == '@')
				{
					Y = I;
					X = J;
				}
			}
		}
		for (I = 0; I < T; I ++) puts(Screen[I]);
		printf("\nScore: %d\n\nX: %d\nY: %d\nT: %dx%d\n", Score, X, Y, T - 2, T - 2);
		Input = getch();
		switch (tolower(Input))
		{
			case 'd':
				if (Screen[Y][X + 1] != '#')
				{
					if (Screen[Y][X + 1] == '*') Score ++;
					Screen[Y][X] = ' ';
					Screen[Y][X + 1] = '@';
				}
				break;
			case 'a':
				if (Screen[Y][X - 1] != '#')
				{
					if (Screen[Y][X - 1] == '*') Score ++;
					Screen[Y][X] = ' ';
					Screen[Y][X - 1] = '@';
				}
				break;
			case 'w':
				if (Screen[Y - 1][X] != '#')
				{
					if (Screen[Y - 1][X] == '*') Score ++;
					Screen[Y][X] = ' ';
					Screen[Y - 1][X] = '@';
				}
				break;
			case 's':
				if (Screen[Y + 1][Y] != '#')
				{
					if (Screen[Y + 1][X] == '*') Score ++;
					Screen[Y][X] = ' ';
					Screen[Y + 1][X] = '@';
				}
				break;
			case 'r':
				goto INICIO;
		}
	} while (Input != 'e' && Score != Gold);
	system("cls");
	if (Score == Gold) printf("You won!\n\n");
	else printf("You left the dungeon...\n\n");
	system("pause");
	return 0;
}
