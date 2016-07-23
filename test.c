#define _CRT_SECURE_NO_WARNINGS
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
#define N 20

void pause(int),
    gotoxy(int, int),
    place(int),
    extract();

int charShift = 0;
char *charPtr,
    *string,
    myArray[N];

int main()
{
    SetConsoleTitleA("LAB3 by KIVINEW");
    setlocale(LC_ALL, "russian");
    
    int number = 1111111111;
    string = (char*) malloc(N * sizeof(char));                              // указатель - в начало статического массива
    charPtr = myArray;
    printf("\nInput your string to array: ");
    scanf("%20c", string);
    place(number);
    extract();
    _getch();
    //pause(3);
    return 0;
}

void place(int number)
{
    int i, length = strlen(string);
    for (i = 0; i < length - charShift * 3; i++)
    {
        if (string[i] == '0' || string[i] == 'x')                           // условие, когда нужно
        {                                                                   // положить интовое число в массив 
            *charPtr = '\0';
            *((int*) charPtr)++ = number;                                   // вот тут помещаю интеджер в массив
            charShift++;                                                    // это сдвиг для того, чтобы буквы не пропускать
        }                                                                   //
        else                                                                //
        {                                                                   //
            *charPtr++ = *string++;                                         // тут помещаю чар с кодом символов англ. алфавита
        }                                                                   //
    }
    charPtr = myArray;                                                      // возврат указателя в начало массива
    return;
}

void extract()
{
    int i, number;
    for (i = 0; i < N - charShift * 3; i++)
    {
        if (charPtr[i] == '\0')                                             // условие, когда нужно
        {                                                                   // извлечь интовое число
            if (charPtr[i + 1] == '\0')
                break;
            number = *((int*) charPtr)++;                                   // извлекаем из приведённого указателя число и сдвигаем его
            printf("Number %d: %d\n", i, number);
        }
        else
            printf("Number %d: %c\n", i, *charPtr++);                       // извлекаем значение и сдвигаем указатель
    }
    return;
}

void pause(int time)
{
    int i;
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
    return;
}

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
