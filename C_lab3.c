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
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#define SIZE 100

char strIn[SIZE];															// исходная строка.
char strOut[SIZE];															// упакованная строка.
char *gcp_letters;															// подстрока с буквами.
char *gcp_digits;															// подстрока с символами цифр.
void fill(int),
	 read(int),
	 pause();
int isDigit(char),
	isLetter(char);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите строку c данными:\n");
	scanf("%99s", strIn);
	int length = strlen(strIn);
	fill(length);
//	read(length);
	return 0;
}

void fill(int length)														// ввод данных в строку                     
{
	gcp_letters = (char*) malloc(length * sizeof(char));
	gcp_digits = (char*) malloc(length * sizeof(char));
	strcpy(gcp_letters, "0");
	strcpy(gcp_digits, "0");
	int	i = 0,
		txtShiftIndex = 0,
		digShiftIndex = 0,
		letterFlag = 0,														// флаг букв
		digitFlag = 0,
		size = strlen(strIn);												// размер исходной строки
	for (; i<size; i++)
	{
		if (isLetter(strIn[i]))
		{
			if (digitFlag == 1)
			{
				*gcp_digits++ = ',';										// вставить в подстроку с цифрами символ ','
				digShiftIndex++;
				digitFlag = 0;
			}
			*gcp_letters++ = strIn[i];
			txtShiftIndex++;
			letterFlag = 1;

		}
		if (isDigit(strIn[i]))												// если встретится цифра,
		{
			if (letterFlag == 1)											// если уже были буквы,...
			{																// ...
				*gcp_letters++ = '.';										// ...вставить в подстроку с буквами символ '.'
				txtShiftIndex++;
				letterFlag = 0;
			}
			*gcp_digits++ = strIn[i];										// и записать эту цифру в подстроку с цифрами.
			digShiftIndex++;
			digitFlag = 1;
		}
	}
	gcp_letters -= txtShiftIndex;
	gcp_digits -= digShiftIndex;
	//int *numArray = (int*)malloc(length*sizeof(int)),						// массив для цифр из строки.
	//	arrLength = 0;														// счётчик длины массива.
	//i = 0;
	//while(isDigit(*gcp_digits))
	//{
	//	numArray[i] = *gcp_digits++-'0';									// помещаем цифру в массив.
	//	arrLength++;
	//	i++;
	//}
	//int numInt = 0,														// число, полученное из цифр в строке.
	//	j;
	//for (j = 0; j < arrLength; j++)
	//{
	//	numInt += numArray[j] * (int) pow(10, arrLength - j - 1);
	//}
	char *tempStr = (char*) malloc(length * sizeof(char));
	if (isLetter(strIn[0]))
	{
		letterFlag = 1;
	}
	else
	{
		letterFlag = 0;
	}
	for (i = 0; strOut[i] == '\0'; i++)
	{
		while (letterFlag == 1)
		{
			if (*gcp_letters == '.')
			{
				gcp_letters++;
				letterFlag = 0;
			}
			strOut[i] = *gcp_letters++;
		}
		while(letterFlag == 0)
		{
			if (*gcp_digits == ',')
			{
				gcp_digits++;
				letterFlag = 1;
			}
			strOut[i] = *gcp_digits++;
		}
		/*if (i == SIZE)
		{
			strOut[i] = '\0';
			return;
		}*/
	}
	printf("\t%d строка: %s\n", i, strOut);
	pause();
	return;
}

void read(int length)														// расшифровка данных
{
	printf("Буквы: %s\n", gcp_letters);
	printf("Цифры: %s\n", gcp_digits);
	int i = 0;
	for (; i < length; i++)
	{

	}
	return;
}

int isDigit(char temp)
{
	if (temp >= '0' && temp <= '9')
		return 1;
	return 0;
}

int isLetter(char temp)
{
	if (temp >= 'a' && temp <= 'z' || temp >= 'а' && temp <= 'я')
		return 1;
	return 0;
}

void pause()
{
	printf("Exit after 2 seconds\r");
	Sleep(1000);
	printf("Exit after 1 second ");
	Sleep(1000);
	if (_kbhit())
	{
		printf("\n\nPress again for exit programm...");
		_getch();
		_getch();
	}
	return;
}