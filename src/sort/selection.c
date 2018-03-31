// selection.c

#include <stdbool.h>
#include "sort.h"

void selection_sort(ssize_t *tab, size_t size)
{
	size_t idx = 0;
        size_t min_idx = 0;

	while (idx < size) {
		min_idx = idx;
		for (size_t i = idx + 1; i < size; i++) {
			if (tab[i] < tab[min_idx])
				min_idx = i;
		}
		SWAP(tab[idx], tab[min_idx]);
		++idx;
	}
}
