#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>

void filterEndline(char *input);

void clearInputBuffer(void);

void inputPosition(unsigned int *position, unsigned int lowerBound, unsigned int upperBound);

int decideOverwrite(char **stringData, unsigned int position);

#endif /* ifndef UTILS_H_ */
