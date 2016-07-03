#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define N 20

void pause(int);

void gotoxy(int xpos, int ypos);

int main()
{
	SetConsoleTitleA( "LAB3 by KIVINEW" ) ;
	setlocale(LC_ALL, "russian");
	char array[N],
		*charPtr = array;
	int i, 
		shift = 0,
		number = 2456;
	for (i = 0; i < N; i++)
	{
		if (i == 5)
		{
			*(int*)charPtr++ = number;
			shift = 4;
		}
		else
		{
			*charPtr++ = i + 65;
		}
		gotoxy(2, 0+i);
		printf("\t%d\t%d\n", *(charPtr+i), i);
	}

	//for (i = 0; i < N && (*charPtr!='\0'&&*(charPtr+1)!='\0'); i++)
	//{
	//	if (i == 5)
	//	{
	//		printf("Number %d: %d\n", i, *(int*) charPtr);
	//		charPtr += 4;
	//	}
	//	else
	//		printf("Number %d: %c\n", i, *(char*) charPtr++);
	//}
	//pause(3);
	return 0;
}

void pause(int time)
{
	int i;
	for (i = 0; i < time; i++)
	{
		printf("\tTime to exit: %d sec\r", time-i);
		Sleep(1000);
	}	
	if (_kbhit())
	{
		printf("\n\n\tPress again for exit program :-)");
		_getch();
		_getch();
	}
	return;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
