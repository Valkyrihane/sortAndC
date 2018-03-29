// main.c

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

int main(int argc, char const *argv[])
{
	int idx = 0;
	ssize_t tab[argc - 2];

	if (argc <= 2
	    || !strcmp(argv[1], "-h")
	    || !strcmp(argv[1], "--help")) {
		usage(ALGO_TAB, argv[0]);
		return (EXIT_SUCCESS);
	}
	idx = check_algo_name(ALGO_TAB, argv[1]);
	if (idx == -1)
		return (EXIT_FAILURE);
	init_tab(tab, argv + 2);
	fptr_tab[idx](tab, argc - 2);
	dump_tab(tab, argc - 2);
	return (EXIT_SUCCESS);
}
