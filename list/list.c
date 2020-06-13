#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list *list_new(size_t isize) {
	struct list *list = malloc(sizeof(struct list));
	list->isize = isize;
	list->count = 0;
	list->max = 0;
	list->items = NULL;
}

void *list_add(struct list *list, void *value)
{
	char *pos = NULL;

	if (NULL == list->items) {
		list->items = malloc(list->isize);
		list->max = 1;
	} else if (list->count == list->max) { 
		size_t size = list->isize * list->max * 2;
		void *items = realloc(list->items, size);
		if (NULL == items) {
			puts("realloc failed.");
			exit(EXIT_FAILURE);
		}
		list->items = items;
		list->max *= 2;
	}

	pos = (char*)list->items+(list->count * list->isize);

	if (NULL == memcpy(pos, value, list->isize)) {
		printf("error copying value\n");
	}

	list->count++;
	return pos;
}

void list_rm(struct list *list, void *value)
{
	int i = 0;
	char *pos = (char*)list->items;
	int count = 0;
	size_t remainder = 0;

	for (i = 0; i < list->count; ++i) {
		if (0 == memcmp(pos, value, list->isize))
			goto rm;

		pos += list->isize;
	}
rm:
	count = list->max - i - 1;
	remainder = count * list->isize;
	if (NULL == memcpy(pos, pos+list->isize, remainder)) {
		puts("memcpy failed");
	}
	list->count--;
}

void list_rmall(struct list *list, void *value)
{
	int i = 0;
	int count = 0;
	char *pos = (char*)list->items;

	for (i = 0; i < list->count; ++i) {
		if (0 == memcmp(pos, value, list->isize))
			count++;

		pos += list->isize;
	}

	for (i = 0; i < count; ++i)
		list_rm(list, value);
}

int list_has(struct list *list, void *value)
{
	int i = 0;
	char *pos = (char*)list->items;

	for (i = 0; i < list->count; ++i) {
		if (0 == memcmp(pos, value, list->isize))
			return 1;

		pos += list->isize;
	}

	return 0;
}

void list_free(struct list *list)
{
	if (list->count > 0)
		free(list->items);
	free(list);
}

