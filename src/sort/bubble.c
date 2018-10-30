// bubble.c

#include <stdbool.h>
#include "sort.h"

void bubble_sort(ssize_t *tab, size_t size)
{
	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (size_t i = 0; i < size - 1; i++) {
			if (tab[i] > tab[i + 1]) {
				sorted = false;
				SWAP(
				     tab[i],
				     tab[i + 1]);
			}
		}
	}
}
