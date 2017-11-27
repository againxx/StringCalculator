#ifndef STR_H_
#define STR_H_ 

#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>

unsigned int lengthOfString(char *str);

char *joinString(char *str1, char *str2);

int compareString(char *str1, char *str2);

char *copyString(char *str1, char *str2);

char *insertString(char *str1, unsigned int pos, char *str2);

char *subString(char *str, unsigned int pos, unsigned int num);

int searchString(char *str1, char *str2);

char *replaceString(char *str1, char *str2, char *str3);

#endif /* ifndef STR_H_ */
