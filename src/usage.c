// usage.c

#include <stdio.h>
#include "sort.h"

void usage(const char **algo_tab, const char *name)
{
	printf("USAGE\n\t%s [Alogrithm] [n1] ... [n#]\n\n", name);
	printf("Algorithm list :\n");
	for (unsigned char i = 0; algo_tab[i]; i++)
		printf("\t- %s\n", algo_tab[i]);
	printf("\n");
}
