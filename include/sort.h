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
			"insertion",	\
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

/* sort_and.c */
int sortAndC(const char *, const char *);

/* tab.c */
void dump_tab(const ssize_t*, size_t);
int init_tab(ssize_t **, const char *, size_t *);

/* usage.c */
void usage(const char **, const char *);

/* SORT */
void raddix_sort(ssize_t [], size_t);
void selection_sort(ssize_t [], size_t);
void bubble_sort(ssize_t [], size_t);
void insertion_sort(ssize_t [], size_t);

/*
**** Function Pointers
*/

typedef void (*fptr)(ssize_t [], size_t);

static const fptr fptr_tab[] = {
        &raddix_sort,
	&selection_sort,
	&bubble_sort,
        &insertion_sort,
};
