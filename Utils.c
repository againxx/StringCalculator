#include "Utils.h"

void filterEndline(char *input)
{
	int i = 0;
	while (*(input + i) != '\0')
	{
		if (*(input + i) == '\n')
		{
			*(input + i) = '\0';
			break;
		}
		++i;
	}
}

void clearInputBuffer(void)
{
	char getBuff;
	getBuff = getchar();
	while (getBuff != '\n' && getBuff != EOF)
		getBuff = getchar();
}

void inputPosition(unsigned int *position, unsigned int lowerBound, unsigned int upperBound)
{
	scanf("%u", position);
	clearInputBuffer();

	while (*position < lowerBound || *position > upperBound)
	{
		printf("位 置 无 效, 请 重 新 输 入 (%u - %u):", lowerBound, upperBound);
		scanf("%u", position);
		clearInputBuffer();
	}
}

int decideOverwrite(char **stringData, unsigned int position)
{
	if (*(stringData + position - 1) != NULL)
	{
		printf("该 位 置 上 已 有 字 符 串, 是 否 覆 盖 (y / n):");
		char choice = getchar();
		clearInputBuffer();
		if (choice != 'y')
			return 0;
	}
	return 1;
}
