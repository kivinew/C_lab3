//////////////////////////////////////////////   Кудрявцев И.В. Поток 09.2015.  /////
/* Разработать две функции, одна из которых вводит с клавиатуры набор данных	/////
в произвольной последовательности и размещает в памяти в переменном формате.	/////
Другая функция читает эти данные и выводит на экран.							/////
Программа запрашивает и размещает в памяти несколько наборов данных при помощи	/////
первой функции, а затем читает их и выводит на экран при помощи второй.Размещение ///
данных производить в статическом массиве байтов фиксированной размерности с		/////
контролем его переполнения.														/////
Вариант 5. Упакованная строка, содержащая символьное представление целых чисел. /////
Все символы строки, кроме цифр, помещаются в последовательность в исходном виде./////
Последовательность цифр преобразуется в целую переменную, которая записывается	/////
в упакованную строку, предваренную символом \0. Конец строки - два подряд		/////
идущих символа \0.																/////
Пример:																			/////
-исходная строка: "aa2456bbbb6665"												/////
-упакованная строка: 'a' 'a' '\0' 2456 'b' 'b' 'b' 'b' '\0' 6665 '\0' '\0'		 *///
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
