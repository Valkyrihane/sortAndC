// tab.c

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void init_tab(ssize_t *tab, const char **numbers)
{
	for (size_t idx = 0; numbers[idx]; idx++)
		tab[idx] = strtoll(numbers[idx], NULL, 10);
}

void dump_tab(const ssize_t *tab, size_t size)
{
	for (size_t idx = 0; idx < size; idx++)
		printf("%ld\n", tab[idx]);
}
