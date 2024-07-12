#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define T 100

void DrawCustomLevel(FILE *LevelFile, int LevelX, int LevelY);
void ScanCustomLevel(FILE *LevelFile);
void LoadCustomLevel(void);
void MainMenu(void);

int main(void)
{
	MainMenu();
	return 0;
}

void DrawCustomLevel(FILE *LevelFile, int LevelX, int LevelY)
{
	char Caracter, LevelArray[LevelY][LevelX];
	int I = 0, J = 0;
	while ((Caracter = getc(LevelFile)) != EOF)
	{
		printf("%c", Caracter);
		if (Caracter != '\n')
		{
			LevelArray[I][J] = Caracter;
			printf("%c", LevelArray[I][J]);
		}
		else I ++;
		J ++;
	}
	system("pause");
}

void ScanCustomLevel(FILE *LevelFile)
{
	char Caracter;
	int I = 0, J = 0, LevelX = 1, LevelY = 1;
	system("cls");
	while ((Caracter = getc(LevelFile)) != EOF)
	{
		printf("%c", Caracter);
		LevelX ++;
		if (Caracter == '\n')
		{
			LevelY ++;
			J = 0;
			LevelX = 0;
		}
		I ++;
		J ++;
	}
	printf("%dx%d\n\n", LevelX, LevelY);
	system("pause");
	//fclose(LevelFile);
	//DrawCustomLevel(LevelFile, LevelX, LevelY);
}

void LoadCustomLevel(void)
{
	char Filename[T];
	FILE *LevelFile;
	system("cls");
	printf("What is the name of the file? ");
	scanf("%s", Filename);
	fflush(stdin);
	LevelFile = fopen(Filename, "r");
	while (LevelFile == NULL)
	{
		system("cls");
		printf("File not found.\n\n");
		system("pause");
		system("cls");
		printf("What is the name of the file? ");
		scanf("%s", Filename);
		fflush(stdin);
		LevelFile = fopen(Filename, "r");
	}
	ScanCustomLevel(LevelFile);
}

void MainMenu(void)
{
	int Option;
	do
	{
		system("cls");
		printf("Crisper's Rogue v0.5.0\n\n");
		printf("1 - Start a new adventure\n");
		printf("2 - Load an ongoing adventure\n");
		printf("3 - Options\n");
		printf("4 - Exit\n\n");
		printf("Option: ");
		scanf("%d", &Option);
		switch (Option)
		{
			case 1:
				system("cls");
				printf("Option not implemented yet.\n\n");
				system("pause");
				break;
			case 2:
				LoadCustomLevel();
				break;
			case 4:
				system("cls");
				printf("Goodbye!\n\n");
				system("pause");
				break;
			default:
				system("cls");
				printf("Option nonexistent.\n\n");
				system("pause");
		}
	} while (Option != 4);
}
