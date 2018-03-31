// sort.h

#pragma once

#include <stdlib.h>
#include <sys/types.h>

/*
**** Defines
*/

#define ALGO_TAB (const char *[]) {	\
			"raddix",	\
			"selection",	\
			"bubble",	\
			"insert",	\
			NULL,		\
}

#define SWAP(a, b) {\
		__typeof__(a) tmp = a;\
		a = b;\
		b = tmp;\
	}

/*
**** Functions Prototypes
*/

/* tab.c */
void swap(ssize_t *, ssize_t *);
void dump_tab(const ssize_t*, size_t);
void init_tab(ssize_t *, const char **);

/* usage.c */
void usage(const char **, const char *);

/* SORT */
void raddix_sort(ssize_t [], size_t);
void selection_sort(ssize_t [], size_t);
void bubble_sort(ssize_t [], size_t);
void insert_sort(ssize_t [], size_t);

/*
**** Function Pointers
*/

typedef void (*fptr)(ssize_t [], size_t);

static const fptr fptr_tab[] = {
	&raddix_sort,
	&selection_sort,
	&bubble_sort,
	&insert_sort,
};
