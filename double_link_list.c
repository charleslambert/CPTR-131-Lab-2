#include "double_link_list.h"

NODE *make_node() {
	return calloc(1,sizeof(NODE));
}

void insert_before(NODE *node, void *value) {
	NODE *new_node = make_node();

	new_node->value = value;

	new_node->prev = node->prev;
	new_node->next = node;
	node->prev = new_node;

	if (new_node->prev != NULL) {

		new_node->prev->next = new_node;
	} 
}

void insert_after(NODE *node, void *value) {
	NODE *new_node = calloc(1, sizeof(NODE));

	new_node->value = value;

	new_node->next = node->next;
	new_node->prev = node;
	node ->next = new_node;

	if (new_node->next != NULL) {

		new_node->next->prev = new_node;
	}
}

void delete_node(NODE *node) {

	if (node->next != NULL){
		node->next->prev = node->prev;
	}
	if (node->prev != NULL) {
		node->prev->next = node->next;
	}
		
	free(node);
}


//This function may not be used but is for future use.
void *retrieve(void *value, NODE *first_node) {
	void *return_value;

	while(first_node != NULL) {
		if(first_node->value == value) {
			return_value = first_node->value;
			delete_node(first_node);
			return return_value;
		}
		else {
			first_node = first_node->next;
		}
	}

	return NULL;
}