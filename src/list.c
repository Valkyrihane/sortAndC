// list.c

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int init_list(list_t *list, const char **numbers)
{
	(void)list;
	(void)numbers;
	return (EXIT_SUCCESS);
}

void dump_list(const list_t * const list)
{
	const list_t *tmp = list;

	while (tmp) {
		printf("%ld\n", tmp->val);
		tmp = tmp->next;
	}
}
