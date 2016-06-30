#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void pause(int);

int main()
{
	SetConsoleTitleA( "LAB3 by vk.com/KIVINEW" ) ;
	setlocale(LC_ALL, "russian");
	char array[20],
		*charPtr;
	charPtr = array;
	int i, 
		*intPtr,
		shift = 0,
		number = 2456;
	for (i = 0; i < 20; i++)
	{
		if (i == 5)
		{
			intPtr = (int*) (charPtr+i);
			*intPtr = number;
			shift = 4;
			//charPtr +=4;
		}
		else
		{
			array[i+shift] = i + 65;
		}
	}
	//charPtr = array;
	for (i = 0; i < 20/*&&(*charPtr!='\0'&&*(charPtr+1)!='\0')*/; i++)
	{
		if (i == 5)
		{
			printf("Number %d: %d\n", i, *(int*) charPtr);
			charPtr += 4;
		}
		else
			printf("Number %d: %c\n", i, *(char*) charPtr++);
	}
	pause(3);
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