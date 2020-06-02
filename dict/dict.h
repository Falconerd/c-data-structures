#include <stddef.h>

struct dict_item {
	char *key;
	void *value;
	struct dict_item *next;
};

struct dict {
	struct dict_item *buckets;
	size_t size;
	int max_len;
};

struct dict *dict_new(int max_len, size_t size);
void dict_set(struct dict *dict, const char *key, void *value);
void *dict_get(struct dict *dict, const char *key);
void dict_rm(struct dict *dict, const char *key);
void dict_free(struct dict *dict);
