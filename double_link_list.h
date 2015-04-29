#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	struct node *prev;
	void *value;
}NODE;

NODE *make_node();
void insert_before(NODE *node, void *value);
void insert_after(NODE *node, void *value);