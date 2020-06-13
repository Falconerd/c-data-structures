#include <stddef.h>

struct list
{
	int count;
	int max;
	size_t isize;
	void *items;
};

void *list_add(struct list *list, void *value);
void list_rm(struct list *list, void *value);
void list_rmall(struct list *list, void *value);
int list_has(struct list *list, void *value);
struct list *list_new(size_t isize);
void list_free(struct list *list);

