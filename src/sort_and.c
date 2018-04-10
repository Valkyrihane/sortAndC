// sort_and_c.c

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

static int check_algo_name(const char **algo_tab, const char *name)
{
	for (size_t idx = 0; algo_tab[idx]; idx++)
		if (!strcmp(algo_tab[idx], name))
			return (idx);
	fprintf(stderr, "%s: Not in algorithm list\n", name);
	return (-1);
}

int sortAndC(const char *algo, const char *file)
{
	int idx = 0;
	size_t ms = 0;
	size_t size = 0;
	clock_t timer;
	ssize_t *tab = NULL;

	idx = check_algo_name(ALGO_TAB, algo);
	if (idx == -1 || init_tab(&tab, file, &size))
		return (EXIT_FAILURE);
	timer = clock();
	fptr_tab[idx](tab, size);
	ms = (clock() - timer) * 1000 / CLOCKS_PER_SEC;
	dump_tab(tab, size);
	printf("\nComputation time : %ld.%lds\n", ms / 1000, ms % 1000);
	free(tab);
	return (EXIT_SUCCESS);
}
