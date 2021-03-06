#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "Str.h"
#include "Utils.h"

#define STR_BUFFER_SIZE 500
#define MAX_STRING_NUM 99

/*! \brief Show program name "String Calculator"
 *
 * \return void
 */
void showProgramName(void)
{
	printf("\n");
	printf("   ,88888    88                                        ,88888            88                    88             88                       \n");
	printf("   88        88             88                        88                 88                    88             88                       \n");
	printf("   88       88888   ,88888      ,88888,  ,88888,     88        ,88888,   88   ,88888  88   88  88   ,88888,  88888   ,88888,  ,88888   \n");
	printf("   '88888,   88     88      88  88   88  88   88     88        88   88   88   88      88   88  88   88   88   88     88   88  88       \n");
	printf("        88   88     88      88  88   88  88   88     88        88   88   88   88      88   88  88   88   88   88     88   88  88       \n");
	printf("        88   88     88      88  88   88  '888888      88       88   88   88   88      88   88  88   88   88   88     88   88  88       \n");
	printf("   888888'   '8888  88      88  88   88       88       '88888  '8888'88  '88  '88888  '88888'  '88  '8888'88  '8888  '88888'  88       \n");
	printf("                                              88                                                                                       \n");
	printf("                                           8888'                                                                                       \n");
	printf("\n");
}

/*! \brief Show program's main menu
 *
 *  Both digit's and letter's input can be handled
 *
 * \return void
 */
void showMenu(void)
{
	printf("\n");
	printf("            菜                 单\n");
	printf("\n");
	printf("            1. 输  入  字  符  串 (a)\n");
	printf("            2. 显  示  字  符  串 (v)\n");
	printf("            3. 删  除  字  符  串 (d)\n");
	printf("            4. 求  串  长 (l)\n");
	printf("            5. 串  连  接 (j)\n");
	printf("            6. 串  比  较 (c)\n");
	printf("            7. 串  复  制 (y)\n");
	printf("            8. 串  插  入 (i)\n");
	printf("            9. 求  子  串 (s)\n");
	printf("           10. 串  查  找 (f)\n");
	printf("           11. 串  置  换 (r)\n");
	printf("           12. 退  出 (q)\n");
	printf("\n");
	printf("请 输 入 要 进 行 的 操 作 (数 字 或 字 母):");
}

/*! \brief Convert operator from string to int
 *
 *  Examples:
 *  	"1" -> 1
 *  	"10" -> 10
 *  	"a" -> 97
 *  	"q" -> 113
 *
 * \param Operator in string form
 * \return Operator in int form
 */
int convertInputToCommand(char *input)
{
	if (lengthOfString(input) > 2 || lengthOfString(input) == 0)
	{
		return 0;
	}
	else if (lengthOfString(input) == 2)
	{
		return atoi(input);
	}
	else
	{
		if (*input >= '0' && *input <= '9')
			return (*input - '0');
		else
			return *input;
	}
}

/*! \brief Initialize string data by dynamic allocation
 *
 *  Dynamically allocate a 2-D char ** pointer according to current capacity
 *
 * \param Current capacity of string data
 * \return Dynamically allocated 2-D pointer
 */
char **initializeStringData(unsigned int capacity)
{
	char **stringData = (char **)malloc(capacity * sizeof(char *));

	int i;
	for (i = 0; i < capacity; ++i)
	{
		*(stringData + i) = NULL;
	}
	return stringData;
}

void destroyStringData(char **stringData, unsigned int capacity)
{
	int i;
	for (i = 0; i < capacity; ++i)
	{
		if (*(stringData + i) != NULL)
			free(*(stringData + i));
	}
	free(stringData);
}

/*! \brief Expand string data capacity
 *
 *  Expand string data capacity depend
 *
 * \param Original string data
 * \param pointer to capacity
 * \param Insert position
 * \return New pointer
 */
char **expandCapacity(char **stringData, unsigned int *capacity, unsigned int position)
{
	unsigned int newCapacity = *capacity;
	if (position == MAX_STRING_NUM)
		newCapacity = MAX_STRING_NUM;

	while (newCapacity < position)
		newCapacity *= 2;

	char **tempData = stringData;
	stringData = initializeStringData(newCapacity);

	unsigned int i;
	for (i = 0; i < *capacity; ++i)
	{
		if (*(tempData + i) != NULL)
		{
			*(stringData + i) = *(tempData + i);
		}
	}
	free(tempData);
	*capacity = newCapacity;
	return stringData;
}

void inputString(char **stringData, unsigned int capacity, char *inputStr, unsigned int position)
{
	if (*(stringData + position - 1) != NULL)
	{
		free(*(stringData + position -1));
		*(stringData + position - 1) = NULL;
	}
	
	if (lengthOfString(inputStr) == 0)
		return;

	*(stringData + position - 1) = (char *)malloc((lengthOfString(inputStr) + 1) * sizeof(char));

	int i = 0;
	while (*(inputStr + i) != '\0')
	{
		*(*(stringData + position - 1) + i) = *(inputStr + i);
		++i;
	}
	*(*(stringData + position -1) + i) = '\0';
}

void deleteString(char **stringData, unsigned int position)
{
	if (*(stringData + position - 1) != NULL)
	{
		free(*(stringData + position - 1));
		*(stringData + position - 1) = NULL;
	}
}

void listAllStrings(char **stringData, unsigned int capacity)
{
	printf("\n");
	
	unsigned int i, j, maxLength = 0;
	for (i = 0; i < capacity; ++i)
	{
		unsigned int tempLength = lengthOfString(*(stringData + i));
		if (tempLength > maxLength)
			maxLength = tempLength;
	}

	printf("__|");
	for (i = 0; i < maxLength + 1; ++i)
	{
		printf("___|");
	}
	printf("\n");

	for (i = 0; i < capacity; ++i)
	{
		printf("  |");
		for (j = 0; j < maxLength + 1; ++j)
		{
			printf("   |");
		}
		printf("\n");

		if ((i + 1) / 10 > 0)
			printf("%d|", i + 1);
		else
			printf(" %d|", i + 1);

		unsigned int strLength = lengthOfString(*(stringData + i));
		if (strLength)
		{
			for (j = 0; j < maxLength + 1; ++j)
			{
				if (j < strLength)
				{
					printf(" %c |", *(*(stringData + i) + j));
				}
				else if (j == strLength)
				{
					printf(" \\0|");
				}
				else
				{
					printf("   |");
				}
			}
		}
		else
		{
			for (j = 0; j < maxLength + 1; ++j)
			{
				printf("   |");
			}
		}
		printf("\n");

		printf("__|");
		for (j = 0; j < maxLength + 1; ++j)
		{
			printf("___|");
		}
		printf("\n");
	}
}

void runLoop(void)
{
	char **stringData = NULL;
	unsigned int capacity = 10;
	stringData = initializeStringData(capacity);

	showProgramName();
	showMenu();

	char input[STR_BUFFER_SIZE];
	fgets(input, STR_BUFFER_SIZE, stdin);
	filterEndline(input);
	int command = convertInputToCommand(input);

	unsigned int position1, position2, position3, num;
	while (command != 'q' && command != 12)
	{
		switch (command)
		{
			case  1:
			case 'a':
				printf("请 输 入 一 个 新 的 字 符 串:");
				fgets(input, STR_BUFFER_SIZE, stdin);
				filterEndline(input);

				printf("请 输 入 要 存 放 的 位 置 (目 前 容 量 %d, 大 于 %d 将 扩 容):", capacity, capacity);
				inputPosition(&position1, 1, MAX_STRING_NUM);

				if (position1 > capacity)
					stringData = expandCapacity(stringData, &capacity, position1);

				if (decideOverwrite(stringData, position1))
					inputString(stringData, capacity, input, position1);

				break;
			case  2:
			case 'v':
				listAllStrings(stringData, capacity);
				break;
			case  3:
			case 'd':
				printf("请 输 入 要 删 除 的 字 符 串 的 位 置:");
				inputPosition(&position1, 1, capacity);
				deleteString(stringData, position1);
				break;
			case  4:
			case 'l':
				printf("请 输 入 要 计 算 长 度 的 字 符 串 的 位 置:");
				inputPosition(&position1, 1, capacity);
				printf("字 符 串 长 度 为: %u\n", lengthOfString(*(stringData + position1 - 1)));
				break;
			case  5:
			case 'j':
				printf("请 输 入 要 连 接 的 字 符 串 的 位 置 (目 标 串):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 连 接 的 字 符 串 的 位 置 (源 串):");
				inputPosition(&position2, 1, capacity);
				*(stringData + position1 - 1) = joinString(*(stringData + position1 - 1), *(stringData + position2 - 1));
				break;
			case  6:
			case 'c':
				printf("请 输 入 要 比 较 的 字 符 串 的 位 置 (串 1):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 比 较 的 字 符 串 的 位 置 (串 2):");
				inputPosition(&position2, 1, capacity);
				printf("字 符 串 比 较 结 果: %d\n", compareString(*(stringData + position1 -1), *(stringData + position2 - 1)));
				break;
			case  7:
			case 'y':
				printf("请 输 入 要 复 制 的 字 符 串 的 位 置 (目 标 串):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 复 制 的 字 符 串 的 位 置 (源 串):");
				inputPosition(&position2, 1, capacity);

				if (decideOverwrite(stringData, position1))
					*(stringData + position1 - 1) = copyString(*(stringData + position1 - 1), *(stringData + position2 - 1));

				break;
			case  8:
			case 'i':
				printf("请 输 入 要 插 入 的 字 符 串 的 位 置 (主 串):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 插 入 的 字 符 串 的 位 置 (子 串):");
				inputPosition(&position2, 1, capacity);
				printf("请 输 入 在 主 串 中 插 入 的 位 置:");
				inputPosition(&position3, 0, lengthOfString(*(stringData + position1 - 1)));
				*(stringData + position1 - 1) = insertString(*(stringData + position1 - 1), position3, *(stringData + position2 - 1));
				break;
			case  9:
			case 's':
				printf("请 输 入 要 求 子 串 的 字 符 串 的 位 置:");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 子 串 的 开 始 位 置:");
				inputPosition(&position2, 0, lengthOfString(*(stringData + position1 - 1)) - 1);
				printf("请 输 入 子 串 的 长 度:");
				inputPosition(&num, 0, lengthOfString(*(stringData + position1 - 1)) - position2);

				char *newStr = subString(*(stringData + position1 - 1), position2, num);

				printf("获 得 的 子 串 为: %s, 是 否 保 存 (y / n):", newStr);
				char choice = getchar();
				clearInputBuffer();
				if (choice != 'y')
				{
					free(newStr);
				}
				else
				{
					printf("请 输 入 保 存 的 位 置:");
					inputPosition(&position1, 1, capacity);
					if (decideOverwrite(stringData, position1))
					{
						*(stringData + position1 - 1) = newStr;
					}
				}

				break;
			case 10:
			case 'f':
				printf("请 输 入 要 查 找 的 字 符 串 的 位 置 (主 串):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 查 找 的 字 符 串 的 位 置 (子 串):");
				inputPosition(&position2, 1, capacity);

				if (lengthOfString(*(stringData + position2 - 1)) == 0)
					printf("子 串 为 空!\n");
				else
				{
					int foundPlace = searchString(*(stringData + position1 - 1), *(stringData + position2 - 1));
					if (foundPlace == -1)
						printf("没 有 找 到 子 串!\n");
					else
						printf("子 串 所 在 的 下 标: %d\n", foundPlace);
				}
				break;
			case 11:
			case 'r':
				printf("请 输 入 要 置 换 的 字 符 串 的 位 置 (主 串):");
				inputPosition(&position1, 1, capacity);
				printf("请 输 入 要 置 换 的 字 符 串 的 位 置 (查 找 串):");
				inputPosition(&position2, 1, capacity);
				printf("请 输 入 要 置 换 的 字 符 串 的 位 置 (置 换 串):");
				inputPosition(&position3, 1, capacity);

				*(stringData + position1 - 1) = replaceString(*(stringData + position1 - 1),
															  *(stringData + position2 - 1),
															  *(stringData + position3 - 1));
				
				break;
			default:
				printf("操 作 不 正 确，请 重 新 输 入:");
				break;
		}
		showMenu();
		fgets(input, STR_BUFFER_SIZE, stdin);
		filterEndline(input);
		command = convertInputToCommand(input);
	}
	destroyStringData(stringData, capacity);
}

int main(int argc, char *argv[])
{
	runLoop();
	return 0;
}
