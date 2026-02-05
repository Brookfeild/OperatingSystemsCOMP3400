#include <stdbool.h>
#include <stddef.h>

/**
 * Struct that represents a linked list with a single
 * int value.
 */
struct ll_node {
    int data; /** The data that this node stores */
    struct ll_node *next; /** The next pointer */
};

struct ll_node *ll_head(struct ll_node *head);
struct ll_node *ll_tail(struct ll_node *head);
int ll_size(struct ll_node *head);
struct ll_node *ll_find(struct ll_node *head, int value);
int *ll_toarray(struct ll_node *head);
struct ll_node *ll_create(int value);
struct ll_node *ll_fromarray(int* array, int len);
void ll_destroy(struct ll_node *head);
void ll_append(struct ll_node *head, int value);
struct ll_node *ll_remove(struct ll_node *head, int value);
