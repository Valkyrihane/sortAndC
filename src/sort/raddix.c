// raddix.c

#include <string.h>
#include "sort.h"

static ssize_t get_largest(ssize_t *tab, size_t size)
{
	ssize_t nb = 0;

	for (size_t i = 0; i < size; i++)
		if (tab[i] > nb)
			nb = tab[i];
	return (nb);
}

void raddix_sort(ssize_t *tab, size_t size)
{
	ssize_t bucket[19][size];
	size_t bucket_count[19];
	ssize_t largest = get_largest(tab, size);
	size_t pos = 0;
	int digit = 0;

	for (int den = 1; den < largest; den *= 10) {
		memset((char *)bucket_count, 0, sizeof(size_t) * 19);
		for (size_t idx = 0; idx < size; idx++) {
			digit = ((tab[idx] / den) % 10) + 9;
			bucket[digit][bucket_count[digit]++] = tab[idx];
		}
		pos = 0;
		for (size_t i = 0; i < 19; i++)
			for (size_t idx = 0; idx < bucket_count[i]; idx++)
				tab[pos++] = bucket[i][idx];
	}
}
