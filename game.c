#include <stdio.h>
#include <stdlib.h>

#define T 10

int main(void)
{
	char Screen[T], Input;
	int I;
	Screen[0] = '@';
	Screen[T - 1] = '#';
	for (I = 1; I < T - 1; I ++)
	{
		Screen[I] = '-';
	}
	do {
		system("cls");
		for (I = 0; Screen[I] != '@'; I ++);
		switch (Input)
		{
			case 'd':
				if (I != T - 1 && Screen[I + 1] != '#')
				{
					Screen[I] = '-';
					Screen[I + 1] = '@';
				}
				else if (I != T - 1)
				{
					printf("You win!\n\n");
					system("pause");
					return 0;
				}
				break;
			case 'a':
				if (I != 0)
				{
					Screen[I] = '-';
					Screen[I - 1] = '@';
				}
				break;
		}
		puts(Screen);
		scanf("%c", &Input);
	} while (Input != 'e');
	system("cls");
	printf("Goodbye!\n\n");
	system("pause");
	return 0;
}
