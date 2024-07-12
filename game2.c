#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	INICIO:
	srand(time(NULL));
	int T = rand() % 17 + 3;
	char Screen[T][T + 1], Input;
	int I, J, X, Y;
	for (I = 0; I < T; I ++)
	{
		for (J = 0; J < T; J ++)
		{
			if (I == 0 || I == T - 1 || J == 0 || J == T - 1) Screen[I][J] = '#';
			else Screen[I][J] = ' ';
		}
		Screen[I][J] = '\0';
	}
	Screen[1 + rand() % (T - 2)][1 + rand() % (T - 2)] = '@';
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
		printf("\nX: %d\nY: %d\nT: %d\n\n", X, Y, T - 2, T - 2);
		scanf("%c", &Input);
		switch (tolower(Input))
		{
			case 'd':
				if (Screen[Y][X + 1] == ' ')
				{
					Screen[Y][X] = ' ';
					Screen[Y][X + 1] = '@';
				}
				break;
			case 'a':
				if (Screen[Y][X - 1] == ' ')
				{
					Screen[Y][X] = ' ';
					Screen[Y][X - 1] = '@';
				}
				break;
			case 'w':
				if (Screen[Y - 1][X] == ' ')
				{
					Screen[Y][X] = ' ';
					Screen[Y - 1][X] = '@';
				}
				break;
			case 's':
				if (Screen[Y + 1][Y] == ' ')
				{
					Screen[Y][X] = ' ';
					Screen[Y + 1][X] = '@';
				}
				break;
			case 'r':
				goto INICIO;
		}
	} while (Input != 'e');
	system("cls");
	printf("Goodbye!\n\n");
	system("pause");
	return 0;
}
