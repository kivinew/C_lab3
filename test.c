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
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define SIZE 80
#define ESC         27
#define ENTER       13
#define EXIT_CODE   -1
typedef char* string;

void pause(int),
	gotoxy(int, int),
	place(int),
	show();
int enterString();

int charShift = 0,
	length = SIZE;
string	charPtr,
		str,
		myArray[SIZE];

int main()
{
	SetConsoleTitleA("LAB3 by KIVINEW");
	setlocale(LC_ALL, "rus");

	int number = 1010101010;
	str = (string)malloc(length);
	charPtr = myArray;	// указатель - в начало статического массива
	printf("\nInput your string to array: ");
	length = enterString();
	place(number);
	show();
	pause(3);
	return 0;
}

int enterString()
{                                                                           // возвращает длину введённой строки
	int i;                                                                  // ввод невизуальных символов игнорируется
	for (i = 0; i < length; i++, str++)
	{
		*str = _getch();
		if (*str == ESC)
		{
			str -= i;
			return EXIT_CODE;
		}
		if (*str == ENTER) break;
		if (*str < '!')
		{
			str--;
			i--;
			continue;
		}
		printf("%c", *str);
	}
	str -= i;
	return i;
}

void place(int number)
{
	int i, length = strlen(str);
	for (i = 0; i < length - charShift * 3; i++)
	{
		if (str[i] == '0') // условие, когда нужно
		{ // положить интовое число в массив 
			*charPtr = '\0';
			*(int*)charPtr++ = number; // вот тут помещаю интеджер в массив
			charShift++; // это сдвиг для того, чтобы буквы не пропускать
		} //
		else //
		{ //
			*charPtr++ = *str++; // тут помещаю чар с кодом символов англ. алфавита
		} //
	}
	charPtr = myArray; // возврат указателя в начало массива
}

void show()
{
	printf("\n");
	int i, number;
	for (i = 0; i < length - charShift * 3; i++)
	{
		if (charPtr[i] == '\0') // условие, когда нужно
		{ // извлечь интовое число
			if (charPtr[i + 1] == '\0')
				break;
			number = *(int*)charPtr++; // извлекаем из приведённого указателя число и сдвигаем его
			printf("# %d: %d\n", i, number);
		}
		else
			printf("# %d: %c\n", i, *charPtr++); // извлекаем значение и сдвигаем указатель
	}
}

void pause(int time)
{
	int i;
	printf("\n");
	for (i = 0; i < time; i++)
	{
		printf("\tTime to exit: %d sec\r", time - i);
		Sleep(1000);
	}
	if (_kbhit())
	{
		printf("\n\n\tPress again for exit program :-)");
		_getch();
		_getch();
	}
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
