//////////////////////////////////////////////   ��������� �.�. ����� 09.2015.  /////
/* ����������� ��� �������, ���� �� ������� ������ � ���������� ����� ������	/////
� ������������ ������������������ � ��������� � ������ � ���������� �������.	/////
������ ������� ������ ��� ������ � ������� �� �����.							/////
��������� ����������� � ��������� � ������ ��������� ������� ������ ��� ������	/////
������ �������, � ����� ������ �� � ������� �� ����� ��� ������ ������.���������� ///
������ ����������� � ����������� ������� ������ ������������� ����������� �		/////
��������� ��� ������������.														/////
������� 5. ����������� ������, ���������� ���������� ������������� ����� �����. /////
��� ������� ������, ����� ����, ���������� � ������������������ � �������� ����./////
������������������ ���� ������������� � ����� ����������, ������� ������������	/////
� ����������� ������, ������������ �������� \0. ����� ������ - ��� ������		/////
������ ������� \0.																/////
������:																			/////
-�������� ������: "aa2456bbbb6665"												/////
-����������� ������: 'a' 'a' '\0' 2456 'b' 'b' 'b' 'b' '\0' 6665 '\0' '\0'		 *///
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
	short myArray[N],
		*charPtr = myArray;
	int i, 
		charShift = 0,
		number = 717171717;
	for (i = 0; i < N; i++)
	{
		if (i == 1 || i == 7)
		{
			*(int*)charPtr++ = number;
			charShift++;
		}
		else
		{
			*charPtr++ = i + 65 - charShift;
		}
	}
	charPtr = myArray;
	for (i = 0; i < N /*&& (*charPtr!='\0'&&*(charPtr+1)!='\0')*/; i++)
	{
		if (i == 1 || i == 7)
		{
			number = *(int*) charPtr++;
			printf("Number %d: %d\n", i, number);
		}
		else
			printf("Number %d: %c\n", i, *charPtr++);
	}
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
