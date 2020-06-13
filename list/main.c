#include <stdio.h>

#include "list.h"

int vals[5] = { 23, 42, 53, 69, 71 };

void print_list(struct list *list)
{
	int i = 0;
	int *items = (int*)list->items;
	for (i = 0; i < list->count; ++i) {
		printf("%d: %d\n", i, items[i]);
	}
}

int main(void)
{
	struct list *list = list_new(sizeof(int));
	list_add(list, &vals[0]);
	list_add(list, &vals[1]);
	list_add(list, &vals[2]);
	list_add(list, &vals[3]);
	list_add(list, &vals[4]);
	list_add(list, &vals[0]);

	if (list_has(list, &vals[0])) {
		printf("found %d\n", vals[0]);
	}

	if (list_has(list, &vals[1])) {
		printf("found %d\n", vals[1]);
	}

	if (list_has(list, &vals[2])) {
		printf("found %d\n", vals[2]);
	}

	if (list_has(list, &vals[3])) {
		printf("found %d\n", vals[3]);
	}

	list_rm(list, &vals[2]);

	if (!list_has(list, &vals[2])) {
		printf("cannot find %d\n", vals[2]);
	}

	print_list(list);
	list_rmall(list, &vals[0]);
	print_list(list);

	list_free(list);

	return 0;
}
