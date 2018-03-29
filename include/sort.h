// sort.h

#pragma once

#include <stdlib.h>
#include <sys/types.h>

/*
**** Defines
*/

#define ALGO_TAB (const char *[]) {	\
			"raddix",	\
			"bubble",	\
			"insert",	\
			NULL,		\
}

#define SWAP(a, b) { a ^= b; b ^= a; a ^= b; }

/*
**** Functions Prototypes
*/

/* tab.c */
void swap(ssize_t *, ssize_t *);
void dump_tab(const ssize_t*, size_t);
void init_tab(ssize_t *, const char **);

/* usage.c */
void usage(const char **, const char *);

/* raddix.c */
void raddix_sort(ssize_t [], size_t);

/* bubble.c */
void bubble_sort(ssize_t [], size_t);

/* insert.c */
void insert_sort(ssize_t [], size_t);

/*
**** Function Pointers
*/

typedef void (*fptr)(ssize_t [], size_t);

static const fptr fptr_tab[] = {
	&raddix_sort,
	&bubble_sort,
	&insert_sort,
};
