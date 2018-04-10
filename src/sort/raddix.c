// raddix.c

#include <stdio.h>
#include <string.h>
#include "sort.h"

static void free_buckets(ssize_t **buckets)
{
	for (size_t i = 0; i < 19; i++)
		free(buckets[i]);
	free(buckets);
}

static ssize_t **init_buckets(size_t size)
{
	ssize_t **bucket = NULL;

	bucket = malloc(sizeof(ssize_t *) * 19);
	if (!bucket) {
		perror("malloc");
		return (NULL);
	}
	for (size_t idx = 0; idx < 19; idx++) {
		bucket[idx] = malloc(sizeof(ssize_t) * size);
		if (!bucket[idx]) {
			perror("malloc");
			return (NULL);
		}
	}
	return (bucket);
}

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
	ssize_t **buckets = init_buckets(size);
	size_t bucket_count[19];
	ssize_t largest = get_largest(tab, size);
	size_t pos = 0;
	int digit = 0;

	if (!buckets)
		return;
	for (int den = 1; den < largest; den *= 10) {
		memset((char *)bucket_count, 0, sizeof(size_t) * 19);
		for (size_t idx = 0; idx < size; idx++) {
			digit = ((tab[idx] / den) % 10) + 9;
			buckets[digit][bucket_count[digit]++] = tab[idx];
		}
		pos = 0;
		for (size_t i = 0; i < 19; i++)
			for (size_t idx = 0; idx < bucket_count[i]; idx++)
				tab[pos++] = buckets[i][idx];
	}
	free_buckets(buckets);
}
