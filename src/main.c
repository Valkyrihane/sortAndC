// main.c

#include <string.h>
#include "sort.h"

int main(int argc, char const *argv[])
{
	if (argc < 3 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
		usage(ALGO_TAB, argv[0]);
		return (EXIT_SUCCESS);
	}
	if (sortAndC(argv[1], argv[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
