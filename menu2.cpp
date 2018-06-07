// slover_v_menu.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h>


#pragma warning(disable:4996)

void SetRussian();

void CreateDictionary();
void DestroyDictionary();
void PrintDictionary();
void SortDictionary();

const int MASHROOMS_COUNT=20;
int wordsCount=0;
const char* mashrooms[MASHROOMS_COUNT]={"Белый", "Лисичка", "Подосиновик", "Подберезовик", "Моховик", "Маслёнок" ,"Бледная поганка", "Мухомор", "Груздь", "Рыжик", "Дождевик", "Сморчёк", "Вешенка", "Обабок", "Сыроежка", "Польский гриб", "Лжебелый", "Опёнок", "Поддубовик", "Сторчёк"};

const int STR_MAX_LEN=16;

char** dict;




int _tmain(int argc, _TCHAR* argv[])
{
	SetRussian();

	printf("----Словарь 1.0----");

	dict=NULL;
	bool work=true;
	char menuNumber;

	while (work)
	{
		printf("\n0 - Выход, 1 - Создать, 2 - Удалить, 3 - Печать, 4 - Сортировка\n");
		scanf("%c", &menuNumber);

		switch (menuNumber)
		{
			case '0'://exit
			{
				work=false;
				break;
			}
			case '1'://create
			{
				CreateDictionary();
				break;
			}
			case '2'://destroy
			{
				DestroyDictionary();
				break;
			}

			case '3'://print
			{
				PrintDictionary();
				break;
			}

			case '4'://sort
			{
				SortDictionary();
				break;
			}

		default:
			break;
		}
	}
	return 0;
}

void SetRussian()
{
	const UINT CODE_PAGE_ID=1251;
	SetConsoleCP(CODE_PAGE_ID);
	SetConsoleOutputCP(CODE_PAGE_ID);
	setlocale(LC_ALL,"rus");
}

void CreateDictionary()
{
	int wordsLength=0;

	while ((wordsCount<3)||(wordsCount>MASHROOMS_COUNT))
	{
		printf("\nВведите количество слов в словаре от 2 до %d: \n", MASHROOMS_COUNT);
		scanf("%d",&wordsCount);		
	}

	while ((wordsLength<3)||(wordsCount>STR_MAX_LEN))
	{
		printf("\nВведите максимальную длину слова  от 2 до %d:\n", STR_MAX_LEN);
		scanf("%d",&wordsLength);		
	}

	dict=(char**)calloc(wordsCount, sizeof(char*));

	for (int i = 0; i < wordsCount; i++)
	{
		dict[i]=(char*)calloc(wordsLength+1, sizeof(char));
		strncpy(dict[i], mashrooms[i], wordsLength);
	}

}

void DestroyDictionary()
{
	if (!dict)
	{return;}

	for (int i = 0; i < wordsCount; i++)
	{
		free((void*)dict[i]);
	}

	free((void*)dict);
	dict=NULL;
	printf("Словарь удален!\n");
}

void PrintDictionary()
{
	if (!dict)
	{return;}

	printf("Вывод словаря на экран:\n");

	for (int i = 0; i < wordsCount; i++)
	{
		printf("%s\n", dict[i]);
	}
}


void SortDictionary()
{
	if (!dict)
	{return;}

	char* temp;

	for (int i = 0; i < wordsCount-1; i++)
	{
		for (int j = i; j < wordsCount; j++)
		{
			if (strcoll(dict[i], dict[j])>0)
			{
				temp=dict[i];
				dict[i]=dict[j];
				dict[j]=temp;
			}
		}
	}
	printf("Словарь отсортирован!\n");
}