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
