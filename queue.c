#include "queue.h"

LIST *create() {
	return calloc(1,sizeof(LIST));
}

//values are pushed into the first of the List.
//next is heading toward the first of the List.
void push(LIST *list, int value) {
	NODE *node = calloc(1, sizeof(NODE));
	
	node->pid = value;

	//adds pid into an empty list.
	if(list->last == EMPTY && list->first == EMPTY) {
		list->first = node;
		list->last = node;
	}
	//adds pid to a non-empty list.
	else {
		list->first->next = node;
		node->prev = list->first;
		list->first = node;
	}

	list->count++;
}

//values are poped off the tail of the list.
//prev is heading toward the last of the list.
int pop(LIST *list) {
	int pid;

	//returns an error if the list is empty and you try to pop off of it.
	if(list->last == EMPTY && list->first == EMPTY) {
		printf("ERROR: The list is empty\n");
		return -1;
	}
	//if the list only has one entry pops it then sets the list to be empty.
	else if(list->last == list->first)
	{
		pid = list->last->pid;
		free(list->last);
		list->first = EMPTY;
		list->last = EMPTY;
	}
	//pops off the last thing in a list that is longer than 1.
	else {
		pid = list->last->pid;
		list->last = list->last->next;
		free(list->last->prev);
		list->last->prev = EMPTY;
	}

	list->count--;
	return pid;
}

void destroy(LIST *list) {
	if (list->first == EMPTY && list->last == EMPTY) {
		free(list);
	}
	else {
		while (list->count >= 0) {
			pop(list);

			list->count--;
		}
	}
}

void retrieve(int pid, LIST *list) {
	NODE *node= list->first;

	while(pid != node->pid) {
		node = node->prev;	
	}
}