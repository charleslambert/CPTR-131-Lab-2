//I followed a tutorial to understand and write this code.
//The tutorial was made by Zed Shaw.

#include <stdio.h>
#include <stdlib.h>

#define EMPTY NULL


typedef struct node {
	struct node *next;
	struct node *prev;
	int pid;
}NODE;

typedef struct double_l_list {
	int count;
	NODE *first;
	NODE *last;
}LIST;

//create a LIST
LIST *create();

//delete a PID in the LIST
void delete();

//Put a PID in the LIST
//push
void push(LIST *list, int value);

//Take a value out of the list
//delete reference in the list
//pop
int pop(LIST *list);

//See a value in the list, at tail
void peek();

//Destroy list
void destroy(LIST *list);