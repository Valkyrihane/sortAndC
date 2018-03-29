// list.h

#pragma once

#include <stdlib.h>

typedef struct list_s {
	ssize_t val;
	struct list_s *next;
} list_t;

int init_list(list_t *, const char **);
void dump_list(const list_t * const);
