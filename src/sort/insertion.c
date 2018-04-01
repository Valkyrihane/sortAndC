// insert.c

#include "sort.h"

void insertion_sort(ssize_t *tab, size_t size)
{
	size_t extracted = 0;

	for (size_t idx = 0; idx < size; idx++) {
		extracted = idx + 1;
		while (extracted &&
		       extracted < size &&
		       tab[extracted] < tab[extracted - 1]) {
			SWAP(tab[extracted], tab[extracted - 1]);
			--extracted;
		}
	}
}
