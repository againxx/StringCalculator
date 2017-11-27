#include "Str.h"

unsigned int lengthOfString(char *str)
{
	if (str == NULL)
		return 0;

	unsigned int i = 0;
	while (*(str + i) != '\0')
		++i;

	return i;
}

char *joinString(char *str1, char *str2)
{
	unsigned int strLength1 = lengthOfString(str1);
	unsigned int strLength2 = lengthOfString(str2);
	unsigned int newStrLength = strLength1 + strLength2;
	char *newStr = (char *)malloc((newStrLength + 1) * sizeof(char));

	int i;
	for (i = 0; i < newStrLength; ++i)
	{
		if (i < strLength1)
			*(newStr + i) = *(str1 + i);
		else
			*(newStr + i) = *(str2 + i - strLength1);
	}
	*(newStr + i) = '\0';
	if (str1 != NULL)
		free(str1);

	return newStr;
}

int compareString(char *str1, char *str2)
{
	if (str1 == NULL)
	{
		if (str2 == NULL)
			return 0;
		else
			return -(*str2);
	}
	else if (str2 == NULL)
	{
		return *str1;
	}

	int i = 0;
	while (*(str1 + i) == *(str2 + i))
	{
		if (*(str1 + i) == '\0')
			return 0;
		++i;
	}
	return (*(str1 + i) - *(str2 + i));
}

char *copyString(char *str1, char *str2)
{
	if (str1 != NULL)
		free(str1);
	if (str2 == NULL)
	{
		return NULL;
	}

	str1 = (char *)malloc((lengthOfString(str2) + 1) * sizeof(char));
	int i;
	for (i = 0; i < lengthOfString(str2) + 1; ++i)
	{
		*(str1 + i) = *(str2 + i);
	}
	return str1;
}

char *insertString(char *str1, unsigned int pos, char *str2)
{
	unsigned int strLength1 = lengthOfString(str1);
	unsigned int strLength2 = lengthOfString(str2);
	unsigned int newStrLength = strLength1 + strLength2;
	char *newStr = (char *)malloc((newStrLength + 1) * sizeof(char));

	int i;
	for (i = 0; i < newStrLength; ++i)
	{
		if (i < pos)
			*(newStr + i) = *(str1 + i);
		else if (i >= pos && i < pos + strLength2)
			*(newStr + i) = *(str2 + i - pos);
		else
			*(newStr + i) = *(str1 + i - strLength2);
	}
	*(newStr + i) = '\0';
	if (str1 != NULL)
		free(str1);

	return newStr;
}

char *subString(char *str, unsigned int pos, unsigned int num)
{
	char *newStr = (char *)malloc((num + 1) * sizeof(char));
	int i;
	for (i = 0; i < num; ++i)
	{
		*(newStr + i) = *(str + pos + i);
	}
	*(newStr + i) = '\0';
	return newStr;
}

int searchString(char *str1, char *str2)
{
	unsigned int strLength1 = lengthOfString(str1);
	unsigned int strLength2 = lengthOfString(str2);

	int i, j;
	for (i = 0; i < strLength1; ++i)
	{
		if (strLength1 - i < strLength2)
			return -1;

		if (*(str1 + i) == *str2)
		{
			int isEqual = 1;
			for (j = 1; j < strLength2; ++j)
			{
				if (*(str1 + i + j) != *(str2 + j))
				{
					isEqual = 0;
					break;
				}
			}

			if (isEqual)
				return i;
		}
	}
	return -1;
}

char *replaceString(char *str1, char *str2, char *str3)
{
	if (str1 == NULL)
		return NULL;

	char tempStr[500];
	int i;
	for (i = 0; i < lengthOfString(str1) + 1; ++i)
	{
		tempStr[i] = *(str1 + i);
	}

	int lengthDiff = (int)lengthOfString(str2) - (int)lengthOfString(str3);
	int foundPlace = 0, beginPlace = 0;
	while ((foundPlace = searchString(tempStr + beginPlace, str2)) != -1)
	{
		foundPlace += beginPlace;

		if (lengthDiff < 0)
		{
			for (i = lengthOfString(tempStr); i >= foundPlace + lengthOfString(str2); --i)
			{
				tempStr[i + abs(lengthDiff)] = tempStr[i];
			}
		}
		else if (lengthDiff > 0)
		{
			for (i = foundPlace + lengthOfString(str2); i <= lengthOfString(tempStr); ++i)
			{
				tempStr[i - abs(lengthDiff)] = tempStr[i];
			}
		}

		for (i = 0; i < lengthOfString(str3); ++i)
		{
			tempStr[foundPlace + i] = *(str3 + i);
		}

		beginPlace = foundPlace + lengthOfString(str3);
	}

	free(str1);
	str1 = (char *)malloc((lengthOfString(tempStr) + 1) * sizeof(char));
	for (i = 0; i < lengthOfString(tempStr) + 1; ++i)
	{
		*(str1 + i) = tempStr[i];
	}
	return str1;
}
