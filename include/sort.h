// sort.h

#pragma once

#include <stdlib.h>
#include "list.h"

/*
**** Defines
*/

#define ALGO_TAB (const char *[]) {	\
			"raddix",	\
			"bubble",	\
			"insert",	\
			NULL,		\
}

/*
**** Functions Prototypes
*/

/* usage.c */
void usage(const char **, const char *);

/* raddix.c */
void raddix_sort(list_t *);

/* bubble.c */
void bubble_sort(list_t *);

/* insert.c */
void insert_sort(list_t *);

/*
**** Function Pointers
*/

typedef void (*fptr)(list_t *);

static const fptr fptr_tab[] = {
	&raddix_sort,
	&bubble_sort,
	&insert_sort,
};
