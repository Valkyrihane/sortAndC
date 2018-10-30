// bubble.c

#include <stdbool.h>
#include "sort.h"

void bubble_sort(ssize_t *tab, size_t size)
{
	bool sorted = false;

	for (size_t offset = 0; !sorted; offset++) {
		sorted = true;
		for (size_t i = 0; i < size - 1 - offset; i++) {
			if (tab[i] > tab[i + 1]) {
				sorted = false;
				SWAP(tab[i], tab[i + 1]);
			}
		}
	}
}
